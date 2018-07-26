// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EventSystem.h"
#include "BaseEventObject.h"
#include <functional>

#include "MyProject2GameMode.generated.h"



template<typename TBaseEvent>
class TEventSystem
{
public:
	TEventSystem()
	{
		Singleton<TEventSystem<TBaseEvent>>::Instance().SetData(this);
	}

	static void Subscribe(const std::function<void(const TBaseEvent&)>* Handler)
	{
		Singleton<TEventSystem<TBaseEvent>>::GetInstance()->Handlers.Add(Handler);
		//Handlers.Add(Handler);
	}

	void FireEvent(TBaseEvent Event)
	{
		for (const std::function<void(const TBaseEvent&)>* handler : Singleton<TEventSystem<TBaseEvent>>::GetInstance()->Handlers)
		{
			//const std::function<void(const TBaseEvent&)> h = *handler;
			(*handler)(Event);
		}
	}

	void Fire() {
		for (const std::function<void(const TBaseEvent&)>* handler : Singleton<TEventSystem<TBaseEvent>>::GetInstance()->Handlers)
		{
			//const std::function<void(const TBaseEvent&)> h = *handler;

		}
	}

private:
	TArray<const std::function<void(const TBaseEvent&)>* > Handlers;
};

class IEvent
{
	virtual void Emit() = 0;
};

struct FMyEvent : public TEventSystem<FMyEvent>, IEvent
{
	void Emit() override
	{
		FireEvent(*this);
	}

	int MyValue;
};


/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 *
 * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of MyProject2Character
 */
UCLASS(minimalapi)
class AMyProject2GameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMyProject2GameMode();
	void FMyEventHandler(const FMyEvent& Event) const;
	static void FMyStaticEventHandler(const FMyEvent& Event);

private:

	void EventHandler(const UBaseEventObject* Event);

	EventDelegate EventHandlerDelegate;
};

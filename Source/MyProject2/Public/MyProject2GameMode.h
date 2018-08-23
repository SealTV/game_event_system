// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EventSystem.h"
#include "BaseEvent.h"
#include <functional>

#include "MyProject2GameMode.generated.h"


UCLASS(minimalapi)
class AMyProject2GameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMyProject2GameMode();

private:

	void EventHandler(TSharedPtr<FBaseEvent>& Event);

	FEventHandlerDelegate Delegate;
};


UCLASS(BlueprintType, Blueprintable)
class MYPROJECT2_API UStringEventHandler : public UObject
{
	GENERATED_BODY()

public:

	~UStringEventHandler()
	{
		Unsubscribe();
	}

	UFUNCTION(BlueprintCallable)
	void Subscribe()
	{
		Delegate.BindUObject(this, &UStringEventHandler::Handler);
		UEventsHelper::Subscribe<FStringEvent>(&Delegate);
	}

	UFUNCTION(BlueprintCallable)
	void Unsubscribe()
	{
		if (!bSubscribet)
			return;
		UEventsHelper::Unsubscribe<FStringEvent>(&Delegate);

	}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EventHandler(const FStringEvent& Event) const;

private:

	bool bSubscribet;

	FEventHandlerDelegate Delegate;

	void Handler(TSharedPtr<FBaseEvent>& Event)
	{
	}
};
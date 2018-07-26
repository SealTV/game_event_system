// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MyProject2GameMode.h"
#include "MyProject2Character.h"
#include "EventSystem.h"
#include "BaseEventObject.h"

//class UEventBus;

#include <functional>


void AMyProject2GameMode::FMyEventHandler(const FMyEvent& Event) const
{
	GLog->Log(FString::FromInt(Event.MyValue));
}

void AMyProject2GameMode::FMyStaticEventHandler(const FMyEvent & Event)
{
	GLog->Log(FString::FromInt(Event.MyValue));
}

AMyProject2GameMode::AMyProject2GameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AMyProject2Character::StaticClass();	
	EventHandlerDelegate.BindUObject(this, &AMyProject2GameMode::EventHandler);
	
	UIntEventObject::Subscribe(&EventHandlerDelegate);

	//UEventBus* bus;

	AEventSystem::Subscribe<UIntEventObject>(&EventHandlerDelegate);

	/*TEventSystem<UIntEventObject>::Subscribe([](UIntEventObject Value)
	{
		return;
	}
	);*/

	//FMyEvent Event;

	//auto foo = ;
	//std::function<void(const AMyProject2GameMode&, FMyEvent)> foo = &FMyEventHandler;
	//auto f = [=](FMyEvent Event) {FMyEventHandler(Event); };
	
	//FMyEventBus Bus;
	FMyEvent Event;


	std::function<void(const FMyEvent&)> ff = std::bind(&AMyProject2GameMode::FMyEventHandler, this, std::placeholders::_1);
	//std::function<void(const FMyEvent&)> ff = &AMyProject2GameMode::FMyStaticEventHandler;
	FMyEvent::Subscribe(&ff);
	//FMyEvent::Subscribe(&ff);
	
	Event.MyValue = 120;

	Event.Fire();

	//Event.Fire();
	
	//Event.Fire();
}


void AMyProject2GameMode::EventHandler(const UBaseEventObject * Event)
{
	const UIntEventObject* IntEvent = Cast<UIntEventObject, UBaseEventObject>(Event);
	GLog->Log("AMyProject2GameMode handle event");

	int v = IntEvent->GetValue();
	auto strValue = FString::FromInt((int32)v);
	GLog->Log("AMyProject2GameMode handle value = " + strValue);
	AEventSystem::Unsubscribe<UIntEventObject>(&EventHandlerDelegate);

}

 
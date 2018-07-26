// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MyProject2GameMode.h"
#include "MyProject2Character.h"
#include "BaseEventObject.h"


AMyProject2GameMode::AMyProject2GameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AMyProject2Character::StaticClass();	
	EventHandlerDelegate.BindUObject(this, &AMyProject2GameMode::EventHandler);
	
	UBaseEventObject::Subscribe(UIntEventObject::StaticClass(), &EventHandlerDelegate);
}

void AMyProject2GameMode::EventHandler(const UBaseEventObject * Event)
{
	const UIntEventObject* IntEvent = Cast<UIntEventObject, UBaseEventObject>(Event);
	GLog->Log("AMyProject2GameMode handle event");

	int v = IntEvent->GetValue();
	auto strValue = FString::FromInt((int32)v);
	GLog->Log("AMyProject2GameMode handle value = " + strValue);

	UBaseEventObject::Unsubsctibe(UIntEventObject::StaticClass(), &EventHandlerDelegate);

}


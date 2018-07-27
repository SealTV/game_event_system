// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MyProject2GameMode.h"
#include "MyProject2Character.h"
#include "EventSystem.h"

#include <functional>

#include "MyProject2.h"


AMyProject2GameMode::AMyProject2GameMode()
{
	DefaultPawnClass = AMyProject2Character::StaticClass();
	 
	Delegate.BindUObject(this, &AMyProject2GameMode::EventHandler);

	UEventsHelper::Subscribe<FIntEvent>(&Delegate);

	TSharedPtr<FE> Event = TSharedPtr<FE>(new FE());

	Event->i = 10;
}


void AMyProject2GameMode::EventHandler(TSharedPtr<FBaseEvent> Event)
{
	TSharedPtr<FIntEvent> v1 = FBaseEvent::Resotre<FIntEvent>(Event);
/*
	const FIntEvent* IntEvent = reinterpret_cast<FIntEvent*>(Event.Get());
	int v = IntEvent->Value;
	auto strValue = FString::FromInt((int32)v);*/
}

void UStringEventHandler::EventHandler_Implementation(const FStringEvent& Event) const
{
	GLog->Log(Event.Value);
}

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


void AMyProject2GameMode::EventHandler(TSharedPtr<FBaseEvent>& Event)
{
	FIntEvent* v1 = FBaseEvent::Resotre<FIntEvent>(Event.Get());
	GLog->Log(FString::FromInt(v1->Value));
}

void UStringEventHandler::EventHandler_Implementation(const FStringEvent& Event) const
{
	GLog->Log(Event.Value);
}

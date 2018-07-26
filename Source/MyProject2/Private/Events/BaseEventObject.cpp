// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEventObject.h"
#include "EventSystem.h"

void UBaseEventObject::EmitEvent(const UBaseEventObject * Event)
{
	AEventSystem::AddNewEvent(Event);
}

void UBaseEventObject::Subscribe(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler)
{
	AEventSystem::AddHandler(Type, Handler);
}

void UBaseEventObject::Unsubsctibe(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler)
{ 
	AEventSystem::RemoveHandler(Type, Handler);
}

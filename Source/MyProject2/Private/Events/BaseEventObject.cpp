// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEventObject.h"
#include "EventSystem.h"

void UBaseEventObject::EmitEvent(const UBaseEventObject * Event)
{
	AEventSystem::AddEvent(Event);
}

void UBaseEventObject::Subscribe(const EventDelegate * Handler)
{
	AEventSystem::Subscribe<UBaseEventObject>(Handler);
}

void UBaseEventObject::Unsubscribe(const EventDelegate * Handler)
{
	AEventSystem::Unsubscribe<UBaseEventObject>(Handler);
}

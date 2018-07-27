// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEvent.h"
#include "EventSystem.h"

template <typename TEvent>
void EmitEvent(TEvent* Event)
{
	UEventsHelper::Emit<TEvent>(TSharedPtr<TEvent>(Event));
}

FBaseEvent::FBaseEvent()
{
	GLog->Log("Create FBaseEvent");
}

FBaseEvent::~FBaseEvent()
{
	GLog->Log("Delete FBaseE");
}

FIntEvent::FIntEvent()
{
	GLog->Log("Create FIntEvent");
}

FIntEvent::~FIntEvent()
{
	GLog->Log("Delete FIntEvent");
}


FStringEvent::FStringEvent()
{
	GLog->Log("Create FStringEvent");
}

FStringEvent::~FStringEvent()
{
	GLog->Log("Delete FStringEvent");
}

void FBaseEvent::Emit()
{
	EmitEvent<FBaseEvent>(this);
}

void FIntEvent::Emit()
{
	EmitEvent<FIntEvent>(this);
}

void FStringEvent::Emit()
{
	EmitEvent<FStringEvent>(this);
}

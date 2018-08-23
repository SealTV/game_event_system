// Fill out your copyright notice in the Description page of Project Settings.

#include "EventSystem.h"


// Sets default values
AEventSystem::AEventSystem()
{
	PrimaryActorTick.bCanEverTick = true;

	Singleton<AEventSystem>::Instance().SetData(this);
} 


AEventSystem::~AEventSystem() 
{
	Singleton<AEventSystem>::Instance().SetData(nullptr);
}

// Called when the game starts or when spawned
void AEventSystem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEventSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto map = EventsStructsMap;
	EventsStructsMap.Empty();
	HandleEvents(map);
}
 
void AEventSystem::HandleEvents(TMap<const UStruct*, TArray<TSharedPtr<FBaseEvent>>> &Map)
{
	for (TPair<const UStruct*, TArray<TSharedPtr<FBaseEvent>>>& pair : Map)
	{
		const UStruct* key = pair.Key;

		while(Map[key].Num() > 0)
		{
			TSharedPtr<FBaseEvent> Event = Map[key].Pop(); 
			if (EventsStuctHandlers.Contains(key))
			{
				CallHandlers(EventsStuctHandlers[key], Event);
			}
		}
	}
}

void AEventSystem::CallHandlers(TArray<const FEventHandlerDelegate*> &Handlers, TSharedPtr<FBaseEvent>& Event)
{ 
	for (const FEventHandlerDelegate* Handler : Handlers)
	{
		Handler->ExecuteIfBound(Event);
	}
} 

void AEventSystem::SetEvent(const UStruct* Type, TSharedPtr<FBaseEvent> Event)
{
	if (!EventsStructsMap.Contains(Type))
	{
		EventsStructsMap.Add(Type, TArray<TSharedPtr<FBaseEvent>>());
	}
	 
	EventsStructsMap[Type].Push(Event);
} 

void AEventSystem::AddHandler(const UStruct*  Type, const FEventHandlerDelegate * Handler)
{
	if (!EventsStuctHandlers.Contains(Type))
	{
		EventsStuctHandlers.Add(Type, TArray<const FEventHandlerDelegate*>());
	}

	EventsStuctHandlers[Type].Add(Handler);
}

void AEventSystem::RemoveHandler(const UStruct* Type, const FEventHandlerDelegate * Handler)
{
	if (!EventsStuctHandlers.Contains(Type))
	{
		return;
	}

	EventsStuctHandlers[Type].Remove(Handler);
}

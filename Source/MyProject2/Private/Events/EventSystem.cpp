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
	
	//AEventSystem::Instance = this;
}

// Called every frame
void AEventSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	for (auto pair : EventsMap)
	{
		auto key = pair.Key;

		while (EventsMap[key].Num() > 0)
		{
			auto Event = EventsMap[key].Pop();
			Event->HandleEvent();
		}
	}
} 

void AEventSystem::AddEvent(const UBaseEventObject* Event)
{
	UClass* Class = Event->GetClass();
	bool contains = EventsMap.Contains(Class);

	if (!contains) {
		EventsMap.Add(Class, TArray<const UBaseEventObject*>());
	}

	EventsMap[Class].Push(Event);

	GLog->Log("Add event");
}


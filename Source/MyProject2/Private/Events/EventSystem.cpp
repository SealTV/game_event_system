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

	auto map = EventsMap;
	EventsMap.Empty();
	HandleEvents(map);
}

void AEventSystem::HandleEvents(TMap<TSubclassOf<UBaseEventObject>, TArray<const UBaseEventObject*>> &map)
{
	for (auto pair : map)
	{
		auto key = pair.Key;

		while (map[key].Num() > 0)
		{
			auto Event = map[key].Pop();
			if (EventsHandlers.Contains(key))
			{
				Event->HandleEvent();
				auto handlers = EventsHandlers[key];
				for (auto handler : handlers)
				{
					handler->Execute(Event);
				}
				
				//Event->
				
			}
		}
	}
}

//void AEventSystem::HandleEvents(TMap<const UBaseEventObject*, TArray<const UBaseEventObject*>> &map)
//{
//	for (auto pair : map)
//	{
//		auto key = pair.Key;
//
//		while (map[key].Num() > 0)
//		{
//			auto Event = map[key].Pop();
//			if (EventsHandlers.Contains(key))
//			{
//				Event->HandleEvent();
//				auto handlers = EventsHandlers[key];
//				for (auto handler : handlers)
//				{
//					handler->Execute(Event);
//				}
//			}
//		}
//	}
//}

void AEventSystem::AddEvent(const UBaseEventObject * Event)
{
	Singleton<AEventSystem>::GetInstance()->SetEvent(Event);
}

void AEventSystem::AddEvent(const UStruct * Type, FSimpleEvent& Event)
{
	Singleton<AEventSystem>::GetInstance()->SetEvent(Type, Event);
}

void AEventSystem::SetEvent(const UStruct* Type, FSimpleEvent& Event)
{
	if (!EventsStructsMap.Contains(Type))
	{
		EventsStructsMap.Add(Type, TArray<void*>());
	}
	 
	EventsStructsMap[Type].Push(& Event);
}

void AEventSystem::SetEvent(const UBaseEventObject* Event)
{
	UClass* Class = Event->GetClass();
	bool contains = EventsMap.Contains(Class);

	if (!contains) {
		EventsMap.Add(Class, TArray<const UBaseEventObject*>());
	}

	EventsMap[Class].Push(Event);
}

void AEventSystem::AddHandler(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler)
{
	if (!EventsHandlers.Contains(Type))
	{ 
		EventsHandlers.Add(Type, TArray<const EventDelegate*>()); 
	}

	EventsHandlers[Type].Add(Handler);
}
 
void AEventSystem::RemoveHandler(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler)
{
	if (!EventsHandlers.Contains(Type))
	{
		return;
	}

	EventsHandlers[Type].Remove(Handler);
}

void AEventSystem::AddHandler(const UStruct*  Type, const EventDelegate * Handler)
{
	if (!EventsStuctHandlers.Contains(Type))
	{
		EventsStuctHandlers.Add(Type, TArray<const EventDelegate*>());
	}

	EventsStuctHandlers[Type].Add(Handler);
}

void AEventSystem::RemoveHandler(const UStruct* Type, const EventDelegate * Handler)
{
	if (!EventsStuctHandlers.Contains(Type))
	{
		return;
	}

	EventsStuctHandlers[Type].Remove(Handler);
}

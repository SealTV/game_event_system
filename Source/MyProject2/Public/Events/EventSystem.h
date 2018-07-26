// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEventObject.h"
#include "EventSystem.generated.h"


template<class T>
class Singleton
{
public:
	static Singleton& Instance()
	{
		static Singleton s;
		return s;
	}

	static T* GetInstance()
	{
		return Instance().Data;
	}

	void SetData(T* data) {
		Data = data;
	}

	T* GetData();

private:
	T * Data;

	Singleton() {}
	~Singleton() {}

	Singleton(Singleton const&);
	Singleton& operator= (Singleton const&);
};


UCLASS()
class MYPROJECT2_API AEventSystem : public AActor
{
	GENERATED_BODY()

public:	
	AEventSystem();
	~AEventSystem();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void HandleEvents(TMap<TSubclassOf<UBaseEventObject>, TArray<const UBaseEventObject *>> &map);

	static void AddNewEvent(const UBaseEventObject* Event)
	{
		Singleton<AEventSystem>::GetInstance()->AddEvent(Event);
	}


	template <typename T>
	void AddEvent(FSimpleEvent& Event)
	{
		if (!EventsStructsMap.Contains(Event::StaticStruct()))
		{

		}

		EventsMap
	}

	static void AddHandler(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler)
	{
		Singleton<AEventSystem>::GetInstance()->Subscribe(Type, Handler);
	}

	static void RemoveHandler(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler)
	{
		Singleton<AEventSystem>::GetInstance()->Unsubscribe(Type, Handler);
	}
	 
	void AddEvent(const UBaseEventObject* Event);

	void Subscribe(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler);
	void Unsubscribe(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler);

private: 

	TMap <TSubclassOf<UBaseEventObject>, TArray<const UBaseEventObject*>> EventsMap;
	TMap <TSubclassOf<UBaseEventObject>, TArray<const EventDelegate*>> EventsHandlers;

	TMap <const UStruct*, TArray<const UBaseEventObject*>> EventsStructsMap;
}; 
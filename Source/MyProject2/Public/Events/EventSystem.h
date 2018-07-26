// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEventObject.h"
#include "BaseEvent.h"
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

	static void AddEvent(const UBaseEventObject* Event);

	template <typename T>
	static void SetEvent(FSimpleEvent& Event)
	{
		AddEvent(Event::StaticStruct(), Event);
	}

	static void AddEvent(const UStruct* Type, FSimpleEvent& Event);

	template <typename T>
	static void Subscribe(const EventDelegate* Handler)
	{
		Singleton<AEventSystem>::GetInstance()->AddHandler(T::StaticClass(), Handler);
	}

	template <typename T>
	static void Unsubscribe(const EventDelegate* Handler)
	{
		Singleton<AEventSystem>::GetInstance()->RemoveHandler(T::StaticClass(), Handler);
	}

	static void Subscribe(const UStruct* Type, const EventDelegate* Handler)
	{
		Singleton<AEventSystem>::GetInstance()->AddHandler(Type, Handler);
	}

	static void Unsubscribe(const UStruct* Type, const EventDelegate* Handler)
	{
		Singleton<AEventSystem>::GetInstance()->RemoveHandler(Type, Handler);
	}

private: 

	void SetEvent(const UStruct* Type, FSimpleEvent& Event);
	void SetEvent(const UBaseEventObject* Event);

	void AddHandler(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler);
	void RemoveHandler(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler);

	void AddHandler(const UStruct*, const EventDelegate* Handler);
	void RemoveHandler(const UStruct*, const EventDelegate* Handler);

	TMap <TSubclassOf<UBaseEventObject>, TArray<const UBaseEventObject*>> EventsMap;
	TMap <TSubclassOf<UBaseEventObject>, TArray<const EventDelegate*>> EventsHandlers;

	TMap <const UStruct*, TArray<void*>> EventsStructsMap;
	TMap <const UStruct*, TArray<const EventDelegate*>> EventsStuctHandlers;
};

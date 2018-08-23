// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	static void AddEvent(const UStruct* Type, TSharedPtr<FBaseEvent> Event)
	{
		Singleton<AEventSystem>::GetInstance()->SetEvent(Type, Event);
	}

	static void Subscribe(const UStruct* Type, const FEventHandlerDelegate* Handler)
	{
		Singleton<AEventSystem>::GetInstance()->AddHandler(Type, Handler);
	}

	static void Unsubscribe(const UStruct* Type, const FEventHandlerDelegate* Handler)
	{
		Singleton<AEventSystem>::GetInstance()->RemoveHandler(Type, Handler);
	}

private: 
	void HandleEvents(TMap<const UStruct*, TArray<TSharedPtr<FBaseEvent>>> &Map);

	void CallHandlers(TArray<const FEventHandlerDelegate*> &Handlers, TSharedPtr<FBaseEvent>& Event);

	void SetEvent(const UStruct* Type, TSharedPtr<FBaseEvent> Event);

	void AddHandler(const UStruct*, const FEventHandlerDelegate* Handler);
	void RemoveHandler(const UStruct*, const FEventHandlerDelegate* Handler);

	TMap <const UStruct*, TArray<TSharedPtr<FBaseEvent>>> EventsStructsMap;

	TMap <const UStruct*, TArray<const FEventHandlerDelegate*>> EventsStuctHandlers;
};

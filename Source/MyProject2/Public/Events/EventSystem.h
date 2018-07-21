// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEventObject.h"
#include "EventSystem.generated.h"

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

	void AddEvent(UBaseEventObject Event);
};

template<class T>
class Singleton
{
public:
	static Singleton& Instance()
	{
		// согласно стандарту, этот код ленивый и потокобезопасный
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

	Singleton() {}  // конструктор недоступен
	~Singleton() {} // и деструктор

						 // необходимо также запретить копирование
	Singleton(Singleton const&); // реализация не нужна
	Singleton& operator= (Singleton const&);  // и тут
};


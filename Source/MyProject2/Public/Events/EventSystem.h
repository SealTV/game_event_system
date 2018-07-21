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
		// �������� ���������, ���� ��� ������� � ����������������
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

	Singleton() {}  // ����������� ����������
	~Singleton() {} // � ����������

						 // ���������� ����� ��������� �����������
	Singleton(Singleton const&); // ���������� �� �����
	Singleton& operator= (Singleton const&);  // � ���
};


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEvent.generated.h"


USTRUCT()
struct MYPROJECT2_API FSimpleEvent
{
	GENERATED_USTRUCT_BODY()


};

USTRUCT()
struct MYPROJECT2_API FStringEvent : public FSimpleEvent
{
	GENERATED_USTRUCT_BODY()
	FString Value;
};

class HelperClass
{
public: 
	//template <typename T>
	//static void Subscribe()
	//{
	//	//AEventSystem::Subscribe<T>(nullptr);
	//}
};


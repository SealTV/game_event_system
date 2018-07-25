// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseEventObject.generated.h"

UENUM(BlueprintType)
enum class EventType : uint8
{
	BaseEvent,
	BoxDestroy,
	BoxCreate,
	IntEvent
};

UCLASS()
class MYPROJECT2_API UBaseEventObject : public UObject
{
	GENERATED_BODY()
public:
	EventType GetType();

	virtual void HandleEvent() const
	{
		GLog->Log("Base handle event");
	}
	
protected:
	EventType Type;	
};

UCLASS()
class MYPROJECT2_API UIntEventObject : public UBaseEventObject
{
	GENERATED_BODY()
public:
	UIntEventObject()
	{
		Type = EventType::IntEvent;
	}

	void SetValue(int i) { value = i; }
	int GetValue() { return value; }

	void HandleEvent() const override
	{
		//auto IntEvent = Cast<UIntEventObject, UBaseEventObject>(Event);
		GLog->Log(FString::FromInt(this->value));
	} 

private:

	int value;
};


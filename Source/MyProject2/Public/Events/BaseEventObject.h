// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "EventSystem.h"

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

class UBaseEventObject;
DECLARE_DELEGATE_OneParam(EventDelegate, const UBaseEventObject*)

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

	void Emit()
	{
		EmitEvent(this);
	}

	static void EmitEvent(const UBaseEventObject* Event);

	static void Subscribe(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler);
	static void Unsubsctibe(const TSubclassOf<UBaseEventObject>& Type, const EventDelegate* Handler);
	
protected:
	EventType Type;	
};

UCLASS()
class MYPROJECT2_API UIntEventObject : public UBaseEventObject
{
	GENERATED_BODY()
	
public:
	int GetValue() const { return value; }
	void SetValue(int i) { value = i; }

private:

	int value;
};

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


//UCLASS()
//class MYPROJECT2_API UEvents : UObject
//{
//	GENERATED_BODY()
//public:
//
//};

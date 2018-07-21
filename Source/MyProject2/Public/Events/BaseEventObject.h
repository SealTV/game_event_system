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
	BoxCreate
};

class MYPROJECT2_API UBaseEventObject
{
public:
	EventType GetType();
	
private:
	EventType Type;	
};

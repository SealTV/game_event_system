// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEvent.generated.h"


USTRUCT(BlueprintType)
struct MYPROJECT2_API FBaseEvent
{
	GENERATED_USTRUCT_BODY()

	FBaseEvent();
	virtual ~FBaseEvent();
	virtual void Emit();

	template <typename TEvent>
	static TEvent* Resotre(FBaseEvent* Event)
	{
		return reinterpret_cast<TEvent*>(Event);
	}
};

USTRUCT(BlueprintType)
struct MYPROJECT2_API FIntEvent : public FBaseEvent
{
	GENERATED_USTRUCT_BODY()

	FIntEvent();
	~FIntEvent();

	static void Emit(int value)
	{
		FIntEvent* Event = new FIntEvent();
		Event->Value = value;
		Event->Emit();
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Value;
	void Emit() override;
};

USTRUCT(BlueprintType)
struct MYPROJECT2_API FStringEvent : public FBaseEvent
{
	GENERATED_USTRUCT_BODY()

	FStringEvent();
	~FStringEvent();

	static void Emit(FString value)
	{
		FStringEvent* Event = new FStringEvent();
		Event->Value = value;
		Event->Emit();
	} 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Value;
	void Emit() override;
};


DECLARE_DELEGATE_OneParam(FEventHandlerDelegate, TSharedPtr<FBaseEvent>&)

UCLASS()
class UEventsHelper : public UObject
{
	GENERATED_BODY()
public: 

	template <typename TEvent>
	static void Emit(TSharedPtr<TEvent> Event)
	{
		AEventSystem::AddEvent(TEvent::StaticStruct(), Event);
	}

	template <typename TEvent>
	static void Subscribe(const FEventHandlerDelegate* Handler)
	{
		AEventSystem::Subscribe(TEvent::StaticStruct(), Handler);
	}

	template <typename TEvent>
	static void Unsubscribe(const FEventHandlerDelegate* Handler)
	{
		AEventSystem::Unsubscribe(TEvent::StaticStruct(), Handler);
	}
};


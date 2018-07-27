// Fill out your copyright notice in the Description page of Project Settings.

#include "CollisionHandlerComponent.h"
#include "Components/BoxComponent.h"
#include "MyProject2Character.h"
#include "BaseEvent.h"
#include "Runtime/Engine/Public/WorldCollision.h"

UCollisionHandlerComponent::UCollisionHandlerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCollisionHandlerComponent::BeginPlay()
{
	Super::BeginPlay();

	auto Owner = GetOwner();
	UBoxComponent* Box = Owner->FindComponentByClass<UBoxComponent>();
	if (!IsValid(Box)) {
		return;
	}

	FCollisionShape shape = Box->GetCollisionShape();

	Box->OnComponentBeginOverlap.AddDynamic(this, &UCollisionHandlerComponent::TriggerEnter);
}


void UCollisionHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCollisionHandlerComponent::TriggerEnter(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GLog->Log("Trigger enter");
	if (!IsValid(OtherActor))
	{
		return;
	}

	GLog->Log(OtherActor->GetName());

	AMyProject2Character* Character = Cast<AMyProject2Character>(OtherActor);

	if (!IsValid(Character)) {
		return;
	}
	 
	
	FIntEvent::Emit(IntValue);
	//FStringEvent::Emit("Collision");


	/*UIntEventObject* Event = NewObject<UIntEventObject>();
	Event->SetValue(IntValue);
	Event->Emit();*/

	GetOwner()->Destroy(false, false);
}


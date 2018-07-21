// Fill out your copyright notice in the Description page of Project Settings.

#include "Cube.h"
#include "Components/BoxComponent.h"
#include "EventSystem.h"
#include "BaseEvent.h"
#include "MyProject2Character.h"

// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();

	auto CollisonComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisonComponent->SetCollisionProfileName(TEXT("Cube"));
	RootComponent = CollisonComponent;

	CollisonComponent->OnComponentBeginOverlap.AddDynamic(this, &ACube::OnTriggerEnter);
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

} 

void ACube::OnTriggerEnter(class UPrimitiveComponent* OverlapComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GLog->Log("Begin overlap");
	//auto character = Cast<AMyProject2Character>(Other);
	Singleton<AEventSystem>::GetInstance()->AddEvent(UBaseEventObject());
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "EventSystem.h"


// Sets default values
AEventSystem::AEventSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Singleton<AEventSystem>::Instance().SetData(this);
} 


AEventSystem::~AEventSystem() 
{
	Singleton<AEventSystem>::Instance().SetData(nullptr);
}

// Called when the game starts or when spawned
void AEventSystem::BeginPlay()
{
	Super::BeginPlay();
	//AEventSystem::Instance = this;
}

// Called every frame
void AEventSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
} 

void AEventSystem::AddEvent(UBaseEventObject Event)
{
	GLog->Log("Add event");
}


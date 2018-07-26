// Fill out your copyright notice in the Description page of Project Settings.

#include "Cube.h"
#include "Components/BoxComponent.h"

#include "MyProject2Character.h"

// Sets default values
ACube::ACube()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACube::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

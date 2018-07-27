// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MyProject2.generated.h"


USTRUCT()
struct MYPROJECT2_API FBaseE
{
	GENERATED_USTRUCT_BODY()

	FBaseE()
	{
		GLog->Log("Create FBaseE");
	}

	virtual ~FBaseE()
	{
		GLog->Log("Delete FBaseE");
	}

};

USTRUCT()
struct MYPROJECT2_API FE : public FBaseE
{
	GENERATED_USTRUCT_BODY()

	virtual ~FE()
	{
		GLog->Log("Delete FE" + FString::FromInt(i));
	}

	int i;
};

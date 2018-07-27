// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MyProject2.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, MyProject2, "MyProject2" );



void Test(TSharedPtr<FBaseE> Event)
{
	FE* Target;
	Target = reinterpret_cast<FE*>(Event.Get());
}

// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MyProject2GameMode.h"
#include "MyProject2Character.h"

AMyProject2GameMode::AMyProject2GameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AMyProject2Character::StaticClass();	
}

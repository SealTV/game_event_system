// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseEventObject.h"

#include "MyProject2GameMode.generated.h"

/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 *
 * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of MyProject2Character
 */
UCLASS(minimalapi)
class AMyProject2GameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMyProject2GameMode();

private:

	void EventHandler(const UBaseEventObject* Event);

	EventDelegate EventHandlerDelegate;
};

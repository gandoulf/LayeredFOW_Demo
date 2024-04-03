// Copyright Epic Games, Inc. All Rights Reserved.

#include "LayeredFOW_DemoGameMode.h"
#include "LayeredFOW_DemoPlayerController.h"
#include "LayeredFOW_DemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALayeredFOW_DemoGameMode::ALayeredFOW_DemoGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ALayeredFOW_DemoPlayerController::StaticClass();
}
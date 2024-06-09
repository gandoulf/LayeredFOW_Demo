// Copyright Enzo Resse. All Rights Reserved. 2023


#include "MOBA/Spawner/FOW_SplineActor.h"
#include "Tools/FunctionLibrairy/FOWFunctionLibrary.h"
#include "Net/UnrealNetwork.h"

AFOW_SplineActor::AFOW_SplineActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFOW_SplineActor::BeginPlay()
{
	Super::BeginPlay();
}

void AFOW_SplineActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFOW_SplineActor, SplineMovingOn);
}

void AFOW_SplineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFOW_SplineActor::OnRep_UpdateDrawerTeam()
{
	if (SplineMovingOn != nullptr)
	{
		DistanceOnSpline = UFOWFunctionLibrary::FindSplineDistanceAtWorldLocation(SplineMovingOn, GetActorLocation());
	}
}
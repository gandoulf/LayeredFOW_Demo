// Copyright Enzo Resse. All Rights Reserved. 2023


#include "MOBA/Spawner/FOW_SplineSpawner.h"
#include "MOBA/Spawner/FOW_SplineActor.h"
#include "Components/SplineComponent.h"

AFOW_SplineSpawner::AFOW_SplineSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFOW_SplineSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void AFOW_SplineSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateSplineActor(DeltaTime);
}

void AFOW_SplineSpawner::UpdateSplineActor(float DeltaTime)
{
	const float speed = DeltaTime * ActorSpeed;
	TArray<AFOW_SplineActor*> SplineActors_cpy = SplineActors;
	for (AFOW_SplineActor* actor : SplineActors_cpy)
	{
		if (actor != nullptr)
		{
			actor->DistanceOnSpline = actor->DistanceOnSpline + speed;
			if (actor->DistanceOnSpline < actor->SplineMovingOn->GetSplineLength())
			{
				const FVector distance = actor->SplineMovingOn->GetLocationAtDistanceAlongSpline(actor->DistanceOnSpline, ESplineCoordinateSpace::World);
				actor->SetActorLocation(distance);
			}
			else
			{
				ReleaseActorFromSpline(actor);
			}
		}
	}
}

void AFOW_SplineSpawner::ReleaseActorFromSpline_Implementation(AFOW_SplineActor* actor)
{
	actor->Destroy();
}
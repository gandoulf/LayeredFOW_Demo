// Copyright Enzo Resse. All Rights Reserved. 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FOW_SplineActor.generated.h"

class USplineComponent;

UCLASS()
class LAYEREDFOW_DEMO_API AFOW_SplineActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AFOW_SplineActor();

	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, Category = "Settings", Meta = (ExposeOnSpawn = true), Replicated, ReplicatedUsing = OnRep_UpdateDrawerTeam)
		USplineComponent* SplineMovingOn = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "Internal")
		float DistanceOnSpline = 0;

	//Replication callback methode
	UFUNCTION()
		virtual void OnRep_UpdateDrawerTeam();
};

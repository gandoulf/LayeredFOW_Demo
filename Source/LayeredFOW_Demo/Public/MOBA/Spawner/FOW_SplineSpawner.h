// Copyright Enzo Resse. All Rights Reserved. 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FOW_SplineSpawner.generated.h"

class AFOW_SplineActor;

UCLASS()
class LAYEREDFOW_DEMO_API AFOW_SplineSpawner : public AActor
{
	GENERATED_BODY()
	
public:	

	AFOW_SplineSpawner();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void UpdateSplineActor(float DeltaTime);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "FOW")
		void ReleaseActorFromSpline(AFOW_SplineActor* actor);
	virtual void ReleaseActorFromSpline_Implementation(AFOW_SplineActor* actor);

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere ,Category = "Settings", Meta = (ExposeOnSpawn = true))
		float ActorSpeed = 500;

	UPROPERTY(BlueprintReadWrite, Category = "Internal")
		TArray<AFOW_SplineActor* > SplineActors;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Patrol.generated.h"

/**
* A patrol component that stores assigned patrol points
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrol : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> GetPatrolPoints() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Waypoints")
	TArray<AActor*> Waypoints;
};

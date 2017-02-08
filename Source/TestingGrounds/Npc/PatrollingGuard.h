// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	//TODO Remove or make a gitter
	UPROPERTY(EditInstanceOnly, Category = "Way Points")
	TArray<AActor*> WaypointsCPP;
	
	
};

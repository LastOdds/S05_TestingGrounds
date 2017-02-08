// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "Patrol.h"


TArray<AActor*> UPatrol::GetPatrolPoints() const
{
	return Waypoints;
}

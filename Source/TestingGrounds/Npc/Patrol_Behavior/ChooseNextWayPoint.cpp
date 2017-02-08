// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Patrol.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	
	//Get the patrol component
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolComp = ControlledPawn->FindComponentByClass<UPatrol>();

	//Get patrol route
	if (!ensure(PatrolComp)) { return EBTNodeResult::Failed; }
	auto PatrolPoints = PatrolComp->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) { UE_LOG(LogTemp, Warning, TEXT("A patrol is missiong points")); return EBTNodeResult::Failed; }

	//Tell the blackboard what the waypoint is
	//Get Blackboard and index information
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycle the index for a new waypoint
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}

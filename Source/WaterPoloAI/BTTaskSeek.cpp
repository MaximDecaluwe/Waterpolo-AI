// Fill out your copyright notice in the Description page of Project Settings.
#include "BTTaskSeek.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "FieldPlayer.h"
#include "Kismet/KismetMathLibrary.h"

EBTNodeResult::Type UBTTaskSeek::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAIController* pController = Cast<AAIController>(OwnerComp.GetOwner());

	if (!pController)
		return EBTNodeResult::Type::Failed;

	AFieldPlayer* pPawn = Cast<AFieldPlayer>(pController->GetPawn());
	if (!pPawn)
		return EBTNodeResult::Type::Failed;

	UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent();
	if (!BBComp)
		return EBTNodeResult::Type::Failed;

	FVector target_offset = BBComp->GetValueAsVector(Target.SelectedKeyName);
	target_offset -= pPawn->GetActorLocation();
	float distance = target_offset.Size();
	float ramped_speed;
	ramped_speed = pPawn->SwimSpeed;
	ramped_speed *= (distance / 30.0f);
	float clipped_speed = FMath::Min(ramped_speed, pPawn->SwimSpeed);
	FVector DesiredVelocity = clipped_speed * target_offset;
	DesiredVelocity /= distance;
	pPawn->Velocity = UKismetMathLibrary::VLerp(pPawn->Velocity, DesiredVelocity, 0.1f);

	return EBTNodeResult::Type::Succeeded;
}




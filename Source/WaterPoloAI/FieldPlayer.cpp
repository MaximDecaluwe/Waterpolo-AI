// Fill out your copyright notice in the Description page of Project Settings.

#include "FieldPlayer.h"

AFieldPlayer::AFieldPlayer(): SwimSpeed(0), Team(ETeamEnum::VE_Blue), Position(EPositionsEnum::VE_CB)
{
}

void AFieldPlayer::ApplySteeringForce_Implementation(const FVector2D & Force)
{
	
}

void AFieldPlayer::UpdateTransform_Implementation()
{
}

FVector2D AFieldPlayer::GetEstimatedFuturePosition_Implementation(float DeltaSeconds, float Offset, const FVector2D& GoalPos)
{
	return FVector2D();
}

FVector2D AFieldPlayer::Seek_Implementation(const FVector2D& Target)
{
	return FVector2D();
}

FVector2D AFieldPlayer::Pursue_Implementation(AFieldPlayer* fieldPlayer, float Offset, const FVector2D& GoalPos)
{
	return FVector2D();
}

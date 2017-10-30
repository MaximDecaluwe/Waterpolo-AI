// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/DefaultPawn.h"
#include "CoreMinimal.h"
#include "FieldPlayer.generated.h"

UENUM(BlueprintType)
enum class ETeamEnum : uint8
{
	VE_White 	UMETA(DisplayName = "White"),
	VE_Blue 	UMETA(DisplayName = "Blue")
};

UENUM(BlueprintType)
enum class ETeamStatusEnum : uint8
{
	VE_Attack 	UMETA(DisplayName = "Attack"),
	VE_Defend 	UMETA(DisplayName = "Defend"),
	VE_NEUTRAL  UMETA(DisplayName = "Neutral")
};

UENUM(BlueprintType)
enum class EPositionsEnum : uint8
{
	VE_CF UMETA(DisplayName = "Centre Forward"),
	VE_LW UMETA(DisplayName = "Left wing"),
	VE_RW UMETA(DisplayName = "Right wing"),
	VE_LB UMETA(DisplayName = "Left back"),
	VE_RB UMETA(DisplayName = "Right Back"),
	VE_CB UMETA(DisplayName = "Centre back")
};

UCLASS(abstract)
class WATERPOLOAI_API AFieldPlayer : public ADefaultPawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AFieldPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SwimSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETeamEnum Team;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EPositionsEnum Position;
protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Steering")
		void ApplySteeringForce(const FVector2D& Force);
	virtual void ApplySteeringForce_Implementation(const FVector2D& Force);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Steering")
		void UpdateTransform();
	virtual void UpdateTransform_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Steering")
		FVector2D GetEstimatedFuturePosition(float DeltaSeconds, float Offset, const FVector2D& GoalPos);
	virtual FVector2D GetEstimatedFuturePosition_Implementation(float DeltaSeconds, float Offset, const FVector2D& GoalPos);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Steering")
		FVector2D Seek(const FVector2D& Target);
	virtual FVector2D Seek_Implementation(const FVector2D& Target);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Steering")
		FVector2D Pursue(AFieldPlayer* fieldPlayer, float Offset, const FVector2D& GoalPos);
	virtual FVector2D Pursue_Implementation(AFieldPlayer* fieldPlayer, float Offset, const FVector2D& GoalPos);
};

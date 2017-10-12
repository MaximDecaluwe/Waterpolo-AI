// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
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

UCLASS()
class WATERPOLOAI_API AFieldPlayer : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PlayerMesh;
public:
	// Sets default values for this pawn's properties
	AFieldPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SwimSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETeamEnum Team;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HasBall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EPositionsEnum Position;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};

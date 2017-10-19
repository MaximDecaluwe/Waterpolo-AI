// Fill out your copyright notice in the Description page of Project Settings.

#include "FieldPlayer.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AFieldPlayer::AFieldPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>("Player Mesh");
}

// Called when the game starts or when spawned
void AFieldPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFieldPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if( Velocity.Size() < FLT_EPSILON)
		return;

	SetActorLocation(GetActorLocation() + Velocity * DeltaTime);

	FVector dir = Velocity;
	dir.Normalize();
	SetActorRotation(UKismetMathLibrary::MakeRotFromXZ(dir, FVector(0,0,1)));
}

// Called to bind functionality to input
void AFieldPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


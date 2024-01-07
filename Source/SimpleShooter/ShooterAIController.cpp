// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"



void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	MoveToActor(PlayerPawn,100,false);
	SetFocus(PlayerPawn);
}

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
		
}

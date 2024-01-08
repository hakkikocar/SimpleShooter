// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"


// Beginplay Function
void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
	if (BehaviorTree!=nullptr)
	{
		RunBehaviorTree(BehaviorTree);
	}
}


//Tick Function
void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	
	//bool Sight=LineOfSightTo(PlayerPawn);
	//UE_LOG(LogTemp,Warning,TEXT("is true %hhd"),Sight);

	//if (Sight)
	//{
	//	SetFocus(PlayerPawn);
	//}
	//else
	//{
	//	ClearFocus(EAIFocusPriority::Gameplay);
	//	StopMovement();
	//}

	
}
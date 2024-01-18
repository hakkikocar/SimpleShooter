// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


// Beginplay Function
void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
	if (BehaviorTree!=nullptr)
	{
		RunBehaviorTree(BehaviorTree);
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
		
		GetBlackboardComponent()->SetValueAsVector(TEXT("OwnerLocation"),GetPawn()->GetActorLocation());
	}
}


//Tick Function
void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
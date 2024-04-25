// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameModeBase::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	UE_LOG(LogTemp,Warning,TEXT("A pawn was killed"))
	APlayerController* PlayerController=Cast<APlayerController>(PawnKilled->GetController());

	if (PlayerController != nullptr)
	{
		EndGame(false);
	}
	for (AShooterAIController*Controller:TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!Controller->bIsDeat())
		{
			return;
		}
	}
	EndGame(true);
}

void AKillEmAllGameModeBase::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller:TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController()==bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(),bIsWinner);
	}
}
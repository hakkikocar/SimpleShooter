// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AKillEmAllGameModeBase::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	UE_LOG(LogTemp,Warning,TEXT("A pawn was killed"))
	APlayerController* PlayerController=Cast<APlayerController>(PawnKilled->GetController());

	if (PlayerController != nullptr)
	{
		PlayerController->GameHasEnded(nullptr,false);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "ShooterPlayerController.generated.h"


UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	virtual void GameHasEnded(AActor* EndGameFocus=nullptr, bool bIsWinner=false) override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> HudWidgetClass;
	
private:
	UPROPERTY(EditAnywhere)
	float RestartDelay=5.f;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WinScreenClass;

	FTimerHandle RestartTimer;
	
	UUserWidget* HudWidget;
};

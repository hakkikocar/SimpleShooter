// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
	bool IsDeath()const;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AGun> GunClass;
	UPROPERTY()
	AGun*Gun;

	UPROPERTY(VisibleDefaultsOnly)
	USkeletalMeshComponent* GunMesh;

	void Shooot();

	UPROPERTY(EditAnywhere,Category="Combat")
	float MaxHealth=100;
	UPROPERTY(VisibleAnywhere,Category="Combat")
	float Health;
};

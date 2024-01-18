// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root= CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash,Mesh,TEXT("MuzzleFlashSocket"));

	APawn* OwnerPawn=Cast<APawn>(GetOwner());
	if (OwnerPawn==nullptr)return;
	AController* OwnerController=OwnerPawn->GetController();
	if (OwnerController==nullptr)return;

	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location,Rotation);
	
	FVector End= Location+ Rotation.Vector()*MaxRange;
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	bool bSucces=GetWorld()->LineTraceSingleByChannel(HitResult,Location,End,ECC_GameTraceChannel1,Params);

	if (bSucces)
	{
		FVector ShotDirection = -Rotation.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactEffect,HitResult.Location,ShotDirection.Rotation(),true);
		FPointDamageEvent PointDamageEvent(Damage,HitResult,ShotDirection,nullptr);

		AActor* HitActor= HitResult.GetActor();
		if (HitActor)
		{
			HitActor->TakeDamage(Damage,PointDamageEvent,OwnerController,this);
		}
	}

	
}

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

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash,Mesh,TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound,Mesh,TEXT("MuzzleFlashSocket"));
	
	FHitResult Hit;
	FVector ShortDirection;
	bool bSucces=GunTrace(Hit,ShortDirection);
	if (bSucces)
	{
		
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactEffect,Hit.Location,ShortDirection.Rotation(),true);
		UGameplayStatics::PlaySoundAtLocation(GetWorld(),ImpactSound,Hit.Location,1,1,0);
		AActor* HitActor= Hit.GetActor();
		if (HitActor)
		{
			FPointDamageEvent PointDamageEvent(Damage,Hit,ShortDirection,nullptr);
			AController* OwnerController=GetOwnerController();
			HitActor->TakeDamage(Damage,PointDamageEvent,OwnerController,this);
		}
	}
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

bool AGun::GunTrace(FHitResult& Hit, FVector& ShortDirection)
{
	AController* OwnerController=GetOwnerController();
	if (OwnerController==nullptr)return false;
	
	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location,Rotation);
	ShortDirection = -Rotation.Vector();
	
	FVector End= Location+ Rotation.Vector()*MaxRange;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(Hit,Location,End,ECC_GameTraceChannel1,Params);
}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn=Cast<APawn>(GetOwner());
	if (OwnerPawn==nullptr)return nullptr;
	return OwnerPawn->GetController();
}




	

  // Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskShoot.h"

#include "AIController.h"
#include "ShooterCharacter.h"
#include "Widgets/Text/ISlateEditableTextWidget.h"

  UBTTaskShoot::UBTTaskShoot()
  {
    NodeName="Shoot";
  }

  EBTNodeResult::Type UBTTaskShoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
  {
    Super::ExecuteTask(OwnerComp, NodeMemory);
    AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    if (OwnerComp.GetAIOwner()==nullptr && Character==nullptr)
    {
      return EBTNodeResult::Failed;
    }
    Character->Shooot();

    
    
    return EBTNodeResult::Succeeded;
    
  }

// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CleatBlackboardValue.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTTask_CleatBlackboardValue::UBTTask_CleatBlackboardValue()
{
	NodeName= "Clear Blackboard Value";
	
}

EBTNodeResult::Type UBTTask_CleatBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	return EBTNodeResult::Succeeded;
}

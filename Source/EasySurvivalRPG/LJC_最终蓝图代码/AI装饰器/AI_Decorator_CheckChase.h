// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/Decorators/BTDecorator_BlueprintBase.h"
#include "AI_Decorator_CheckChase.generated.h"

/**
 * 
 */
UCLASS()
class EASYSURVIVALRPG_API UAI_Decorator_CheckChase : public UBTDecorator_BlueprintBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		float  CallCastAndGetDistance(APawn* Object);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		FBlackboardKeySelector GetTargetActor();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		FBlackboardKeySelector GetGuardActor();
	UFUNCTION(BlueprintCallable)
		virtual bool  CallChasePerformConditionCheckAI(AAIController* OwnerController, APawn* ControlledPawn);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector MyTargetActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector MyGuardActor;
};

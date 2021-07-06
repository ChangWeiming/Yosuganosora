// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/Decorators/BTDecorator_BlueprintBase.h"
#include "AI_Decorator_InSight.generated.h"

/**
 * 
 */
UCLASS()
class EASYSURVIVALRPG_API UAI_Decorator_InSight : public UBTDecorator_BlueprintBase
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		FBlackboardKeySelector GetActor();

	UFUNCTION(BlueprintCallable)
		virtual bool  CallSightPerformConditionCheckAI(AAIController* OwnerController, APawn* ControlledPawn);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector TargetActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SightAngle = 10.0f;
};

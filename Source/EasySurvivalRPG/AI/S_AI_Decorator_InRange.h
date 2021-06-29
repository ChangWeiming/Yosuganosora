// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/Decorators/BTDecorator_BlueprintBase.h"
#include "S_AI_Decorator_InRange.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class EASYSURVIVALRPG_API US_AI_Decorator_InRange : public UBTDecorator_BlueprintBase
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (Category = "AI", OverrideNativeName = "PerformConditionCheckAI"))
		virtual bool S_PerformConditionCheckAI(AAIController* OwnerController, APawn* ControlledPawn);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = ( Category = "Blackboard"))
		FBlackboardKeySelector Target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Range;



};

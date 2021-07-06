// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/Decorators/BTDecorator_BlueprintBase.h"
#include "AI_Decorator_CheckTarget.generated.h"

/**
 * 
 */
UCLASS()
class EASYSURVIVALRPG_API UAI_Decorator_CheckTarget : public UBTDecorator_BlueprintBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		virtual bool  CallPerformConditionCheckAI(AAIController* OwnerController, APawn* ControlledPawn);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void  CallIsAlive_BPI(AActor* Object, bool& Result);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		bool  CastAndClearTarget(APawn* Pawn);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		FBlackboardKeySelector GetBlueActor();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBlackboardKeySelector MyTargetActor;

};

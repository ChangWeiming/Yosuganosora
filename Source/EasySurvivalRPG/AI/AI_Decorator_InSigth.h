// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "BehaviorTree/Decorators/BTDecorator_BlueprintBase.h"
#include "AI_Decorator_InSigth.generated.h"



/**
 * 
 */
/*易错点：两个成员变量为带眼睛的*/

/* Comment = " Alternative AI version of ReceiveConditionCheck
@Note that if both generic and AI event versions are implemented only the more
suitable one will be called, meaning the AI version if called for AI, generic one otherwise */
/*ToolTip = "Alternative AI version of ReceiveConditionCheck   
@Note that if both generic and AI event versions are implemented only the more    
suitable one will be called, meaning the AI version if called for AI, generic one otherwise
*/


UCLASS(Blueprintable, BlueprintType)
class EASYSURVIVALRPG_API UAI_Decorator_InSigth : public UBTDecorator_BlueprintBase
{
	GENERATED_BODY()

public:
	UAI_Decorator_InSigth();

	UFUNCTION(BlueprintCallable, meta = (Category = "AI"))
		bool  PerformConditionCheckAI_S(AAIController* OwnerController, APawn* ControlledPawn) ;
public:


	/*	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (DisplayName = "Target", Category = "Blackboard", OverrideNativeName = "Target"))
		FBlackboardKeySelector Target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Sight Angle", Category = "默认", OverrideNativeName = "SightAngle"))
		float SightAngle;

};

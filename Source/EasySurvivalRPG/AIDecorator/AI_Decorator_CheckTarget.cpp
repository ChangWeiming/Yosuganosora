// Easy Systems


#include "AI_Decorator_CheckTarget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BehaviorTree/BTFunctionLibrary.h"


bool  UAI_Decorator_CheckTarget::CallPerformConditionCheckAI(AAIController* OwnerController, APawn* ControlledPawn)
{
	AActor* LocalTargetActor{};

	MyTargetActor = GetBlueActor();
	LocalTargetActor = UBTFunctionLibrary::GetBlackboardValueAsActor(this, MyTargetActor);

	//LocalTargetActor = GetActor();
	//检测目标是否存活，是的话则返回true，否则将目标从攻击列表中移除；
	bool Result = true;
	if (::IsValid(LocalTargetActor))
	{
		CallIsAlive_BPI(LocalTargetActor, Result);

		if (Result)
		{
			return true;
		}
		else
		{
			CastAndClearTarget(ControlledPawn);
			return false;
		}
	}
	else
	{
		return false;
	}



}


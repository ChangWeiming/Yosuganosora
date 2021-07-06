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
	//���Ŀ���Ƿ���ǵĻ��򷵻�true������Ŀ��ӹ����б����Ƴ���
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


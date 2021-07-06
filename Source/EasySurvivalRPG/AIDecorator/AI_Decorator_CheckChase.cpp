// Easy Systems


#include "AI_Decorator_CheckChase.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BehaviorTree/BTFunctionLibrary.h"



//检测是否达到追击距离条件；
bool UAI_Decorator_CheckChase::CallChasePerformConditionCheckAI(AAIController * OwnerController, APawn * ControlledPawn)
{
	MyTargetActor = GetTargetActor();
	MyGuardActor = GetGuardActor();

	AActor* LocalTargetActor{};
	FVector LocalGuardVector{};
	FVector TargetVector{};

	LocalTargetActor = UBTFunctionLibrary::GetBlackboardValueAsActor(this, MyTargetActor);
	

	TargetVector = LocalTargetActor->AActor::K2_GetActorLocation();
	
	LocalGuardVector = UBTFunctionLibrary::GetBlackboardValueAsVector(this, MyGuardActor);

	float TDDisatance = UKismetMathLibrary::VSize(TargetVector - LocalGuardVector);

	float ChaseDisatnce = CallCastAndGetDistance(ControlledPawn);//通过守卫结构体获得可追击距离

	//检测玩家是否在可追击距离内
	if (ChaseDisatnce > TDDisatance)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

// Easy Systems


#include "AI_Decorator_CheckChase.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BehaviorTree/BTFunctionLibrary.h"



//����Ƿ�ﵽ׷������������
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

	float ChaseDisatnce = CallCastAndGetDistance(ControlledPawn);//ͨ�������ṹ���ÿ�׷������

	//�������Ƿ��ڿ�׷��������
	if (ChaseDisatnce > TDDisatance)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

// Easy Systems


#include"iostream"
#include "AI_Decorator_InRange.h"
#include"Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BehaviorTree/BTFunctionLibrary.h"

using namespace std;
//���ش���ֵ�ᵼ��ֻ����ע����ҵ��ǲ��ṥ����
bool UAI_Decorator_InRange::CallRangePerformConditionCheckAI(AAIController * OwnerController, APawn * ControlledPawn)
{


	TargetActor = GetActor();//���

	FVector PawnLocation = ControlledPawn->AActor::K2_GetActorLocation();//AI��������
	FVector TargetLocation = UBTFunctionLibrary::GetBlackboardValueAsVector(this, TargetActor);


	AActor* LocalTargetActor = UBTFunctionLibrary::GetBlackboardValueAsActor(this, TargetActor);


	//�������Ƿ��ڿɹ���������
	if (::IsValid(LocalTargetActor))
	{
		float PADistance = ControlledPawn->AActor::GetDistanceTo(LocalTargetActor);

		if (PADistance <= Range)
		{
			cout << "In Attack Range";
			return true;
		}
		else
		{
			cout << "Not In Attack Range";
			return false;
		}

		//return (PADistance <= Range) ? true : false;
	}
	else
	{
		float PTDistance = UKismetMathLibrary::VSize(PawnLocation - TargetLocation);

		if (PTDistance <= Range)
		{
			cout << "In Attack Range";			
			return true;
		}
		else
		{
			cout << "Not In Attack Range";
			return false;
		}

		//return (PTDistance <= Range) ? true : false;
	}



}
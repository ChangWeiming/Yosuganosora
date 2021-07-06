// Easy Systems


#include"iostream"
#include "AI_Decorator_InRange.h"
#include"Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "BehaviorTree/BTFunctionLibrary.h"

using namespace std;
//返回错误值会导致只跟踪注视玩家但是不会攻击；
bool UAI_Decorator_InRange::CallRangePerformConditionCheckAI(AAIController * OwnerController, APawn * ControlledPawn)
{


	TargetActor = GetActor();//玩家

	FVector PawnLocation = ControlledPawn->AActor::K2_GetActorLocation();//AI守卫怪物
	FVector TargetLocation = UBTFunctionLibrary::GetBlackboardValueAsVector(this, TargetActor);


	AActor* LocalTargetActor = UBTFunctionLibrary::GetBlackboardValueAsActor(this, TargetActor);


	//检测玩家是否在可攻击距离内
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
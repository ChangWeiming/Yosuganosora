// Easy Systems


#include "AI_Decorator_InSight.h"
#include "Kismet/KismetSystemLibrary.h"
#include"Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BTFunctionLibrary.h"



//会跟随但是不会攻击,检测玩家是否在可攻击角度
bool UAI_Decorator_InSight::CallSightPerformConditionCheckAI(AAIController * OwnerController, APawn * ControlledPawn)
{
	TargetActor = GetActor();

	AActor* LocalTargetActor{};

	//玩家
	LocalTargetActor = UBTFunctionLibrary::GetBlackboardValueAsActor(this, TargetActor);

	if (::IsValid(LocalTargetActor))
	{
		FVector PawnLocation = ControlledPawn->GetActorLocation();//守卫位置
		FVector TaregtLocation = LocalTargetActor->GetActorLocation();//玩家位置
		

		FRotator PawnRotator = ControlledPawn->GetActorRotation();//守卫的旋转角度
		//Find a rotation for an object at Start location to point at Target location.,
		//守卫转到玩家需要旋转的角度
		FRotator TPRotator = UKismetMathLibrary::FindLookAtRotation(PawnLocation,TaregtLocation);


		//守卫的偏航角(向左向右)
		FRotator NewPawnRotation = UKismetMathLibrary::MakeRotator(0.0f, 0.0f, PawnRotator.Yaw);
		//玩家与守卫的相差的旋转角
		FRotator NewTPRotation = UKismetMathLibrary::MakeRotator(0.0f, 0.0f, TPRotator.Yaw);


		bool IsInSight = UKismetMathLibrary::EqualEqual_RotatorRotator(NewPawnRotation, NewTPRotation,SightAngle);

		if (IsInSight)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	};
	
}
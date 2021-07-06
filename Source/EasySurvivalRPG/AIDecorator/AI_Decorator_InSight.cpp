// Easy Systems


#include "AI_Decorator_InSight.h"
#include "Kismet/KismetSystemLibrary.h"
#include"Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BTFunctionLibrary.h"



//����浫�ǲ��ṥ��,�������Ƿ��ڿɹ����Ƕ�
bool UAI_Decorator_InSight::CallSightPerformConditionCheckAI(AAIController * OwnerController, APawn * ControlledPawn)
{
	TargetActor = GetActor();

	AActor* LocalTargetActor{};

	//���
	LocalTargetActor = UBTFunctionLibrary::GetBlackboardValueAsActor(this, TargetActor);

	if (::IsValid(LocalTargetActor))
	{
		FVector PawnLocation = ControlledPawn->GetActorLocation();//����λ��
		FVector TaregtLocation = LocalTargetActor->GetActorLocation();//���λ��
		

		FRotator PawnRotator = ControlledPawn->GetActorRotation();//��������ת�Ƕ�
		//Find a rotation for an object at Start location to point at Target location.,
		//����ת�������Ҫ��ת�ĽǶ�
		FRotator TPRotator = UKismetMathLibrary::FindLookAtRotation(PawnLocation,TaregtLocation);


		//������ƫ����(��������)
		FRotator NewPawnRotation = UKismetMathLibrary::MakeRotator(0.0f, 0.0f, PawnRotator.Yaw);
		//�����������������ת��
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
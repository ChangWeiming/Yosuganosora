// Easy Systems


#include "AI_Decorator_InSigth.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include"Kismet/KismetMathLibrary.h"

UAI_Decorator_InSigth::UAI_Decorator_InSigth()
{
	SightAngle = 10.000000f;
}


bool UAI_Decorator_InSigth::PerformConditionCheckAI_S(AAIController * OwnerController, APawn * ControlledPawn)
{
	FRotator PawnRotation;
	FRotator TPRotation;
	
	FVector PawnLocation;
	FVector TargetLocation;

	AActor* TargetActor;
	TargetActor = UBTFunctionLibrary::GetBlackboardValueAsActor(this,Target);

	bool  returnValue;

	if (::IsValid(TargetActor))
	{
		PawnRotation = ControlledPawn->K2_GetActorRotation();

		PawnLocation = ControlledPawn->K2_GetActorLocation();

		TargetLocation = TargetActor->K2_GetActorLocation();

		TPRotation = UKismetMathLibrary::FindLookAtRotation(PawnLocation, TargetLocation);
		
		float PawnRotationRoll;
		float PawnRotationPitch;
		float PawnRotationYaw;

		float TPRotationRoll;
		float TPRotationPitch;
		float TPRotationYaw;

		UKismetMathLibrary::BreakRotator(PawnRotation, PawnRotationRoll, PawnRotationPitch,PawnRotationYaw);
		UKismetMathLibrary::BreakRotator(PawnRotation, TPRotationRoll, TPRotationPitch, TPRotationYaw);

		FRotator NewPawnLocation = UKismetMathLibrary::MakeRotator(0.0f, 0.0f, PawnRotationYaw);
		FRotator NewTargetLocation = UKismetMathLibrary::MakeRotator(0.0f, 0.0f, TPRotationYaw);
		returnValue = UKismetMathLibrary::EqualEqual_RotatorRotator(NewPawnLocation, NewTargetLocation, SightAngle);
		
		return returnValue;
	}
	else
	{
		return false;
	}
	
}

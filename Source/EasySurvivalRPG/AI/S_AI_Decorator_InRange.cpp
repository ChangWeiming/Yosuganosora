// Easy Systems


#include "S_AI_Decorator_InRange.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BTFunctionLibrary.h"
/*Alternative AI version of ReceiveConditionCheckt
if both generic and AI event versions are implemented only the more
suitable one will be called, meaning the AI version if called for AI, generic one otherwise 
ToolTip = "Alternative AI version of ReceiveConditionCheck   
@Note that if both generic and AI event versions are implemented only the more    
suitable one will be called, meaning the AI version if called for AI, generic one otherwise"*/


bool US_AI_Decorator_InRange::S_PerformConditionCheckAI(AAIController * OwnerController, APawn * ControlledPawn)
{
	  AActor* TargetActor =  UBTFunctionLibrary::GetBlackboardValueAsActor(this,Target);
	  
	  FVector TargetVector =  UBTFunctionLibrary::GetBlackboardValueAsVector(this, Target);

	  FVector PawnLocation = ControlledPawn->AActor::K2_GetActorLocation();

	  if (::IsValid(TargetActor))
	  {
		  float PawnDisatance = ControlledPawn->AActor::GetDistanceTo(TargetActor);
		  if (PawnDisatance <= Range)
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
		  FVector TPVector = PawnLocation - TargetVector;

		  float TPLength = UKismetMathLibrary::VSize(TPVector);

		  if (TPLength <= Range)
		  {
			  return true;
		  }
		  else
		  {
			  return false;
		  }
	  }
	return false;
}

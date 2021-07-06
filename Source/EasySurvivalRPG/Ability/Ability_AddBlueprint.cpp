// Easy Systems


#include "Ability_AddBlueprint.h"
#include "Components/ActorComponent.h"
#include "Materials/MaterialInterface.h"
#include "Sound/SoundBase.h"
#include "Particles/ParticleSystem.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

void AAbility_AddBlueprint::CallAddUse()
{
	APawn* MyPwan = AActor::GetInstigator();

	AController* MyController = MyPwan->APawn::GetController();

	if (::IsValid(MyPwan))
	{
		CallAddBlueprintToList_BPI(MyController, TargetBlueprintList, TargetBlueprint);
		AActor::K2_DestroyActor();
	}
	else
	{
		AActor::K2_DestroyActor();
	}

}
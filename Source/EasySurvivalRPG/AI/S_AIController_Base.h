// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "Actions/PawnActionsComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIController.h"
#include "S_AIController_Base.generated.h"

/**
 * 
 */
UCLASS()
class EASYSURVIVALRPG_API AS_AIController_Base : public AAIController
{
	GENERATED_BODY()
public:
	AS_AIController_Base();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void S_EventBeginPlay();
public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		USceneComponent* S_TransformComponent;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UPathFollowingComponent* S_PathFollowingComponent;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UPawnActionsComponent* S_ActionsComp;


};

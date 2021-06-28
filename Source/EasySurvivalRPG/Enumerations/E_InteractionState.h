// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "E_InteractionState.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EE_InteractionState:uint8
{
	Attacking UMETA(DisplayName = "Attacking"),
	ContinueAttck UMETA(DisplayName = "ContinueAttack"),
	UpperBody UMETA(DisplayName = "UpperBody"),
	Blocking UMETA(DisplayName = "Blocking"),
	BlockRotating UMETA(DisplayName = "BlockRotating"),
	UsingItem UMETA(DisplayName = "UsingItem"),
	ShouldBlocking UMETA(DisplayName = "ShouldBlocking"),
	ShouldAiming UMETA(DisplayName = "ShouldAiming"),
	Aiming UMETA(DisplayName = "Aiming"),
	Dashing UMETA(DisplayName = "Dashing"),
};

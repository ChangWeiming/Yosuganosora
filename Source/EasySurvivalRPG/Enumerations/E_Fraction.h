// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "E_Fraction.generated.h"

/**
 *
 */
UENUM(BlueprintType)
enum class EE_Fraction :uint8
{
	Player UMETA(DisplayName = "Player"),
	Undead UMETA(DisplayName = "Undead"),
	SmallAnimals UMETA(DisplayName = "SmallAnimals"),
};

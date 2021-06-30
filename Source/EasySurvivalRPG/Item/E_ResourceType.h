#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "E_ResourceType.generated.h"

UENUM(BlueprintType)
enum class EResourceType : uint8
{
	RCoins UMETA(DisplayName = "Coins")
};
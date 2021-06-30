#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "STR_Item.h"
#include "STR_ResourceValue.h"

#include "STR_CostValue.generated.h"

USTRUCT(BlueprintType)
struct EASYSURVIVALRPG_API FSTR_CostValue
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BarterValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSTR_Item> CostItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSTR_ResourceValue> CostResources;
};
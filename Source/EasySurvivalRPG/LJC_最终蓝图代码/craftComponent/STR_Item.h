// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "STR_Item.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct EASYSURVIVALRPG_API FS_STR_Item 
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FDataTableRowHandle ItemHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Charges;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Durability;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Decay;
};

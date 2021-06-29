// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include"STR_Blueprint.h"
#include "UObject/NoExportTypes.h"
#include "STR_QueueBlueprint.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct EASYSURVIVALRPG_API FSTR_QueueBlueprint
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSTR_Blueprint Blueprint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 AmountRemaining;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TimeRemaining;
};

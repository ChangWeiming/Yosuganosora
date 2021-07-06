// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include"STR_Blueprint.h"
#include "UObject/NoExportTypes.h"
#include "STR_QueueBlueprint.generated.h"

/**
 * 
 */
//保存一个正在被制作的物品包括它的制作数量和甚于制作时间
USTRUCT(BlueprintType)
struct EASYSURVIVALRPG_API FS_STR_QueueBlueprint
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FS_STR_Blueprint Blueprint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 AmountRemaining;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TimeRemaining;
};

// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "STR_Item.h"
#include "Engine/Texture2D.h"
#include "UObject/NoExportTypes.h"
#include "STR_Blueprint.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct EASYSURVIVALRPG_API FS_STR_Blueprint
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Description;//物品描述

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D*  Icon;//物品纹理

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FS_STR_Item> ResultItems;//被制作出来的物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FS_STR_Item> RequiredItems;//制作最终物品所需要的物品

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RequiredTime;//制作物品所需的剩余时间

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Experience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer Tags;


};

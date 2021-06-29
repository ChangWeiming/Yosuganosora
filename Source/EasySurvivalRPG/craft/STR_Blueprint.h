// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "../Item/STR_Item.h"
#include "Engine/Texture2D.h"
#include "UObject/NoExportTypes.h"
#include "STR_Blueprint.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct EASYSURVIVALRPG_API FSTR_Blueprint
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D*  Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSTR_Item> ResultItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSTR_Item> RequiredItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RequiredTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Experience;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		FGameplayTagContainer Tags;


};

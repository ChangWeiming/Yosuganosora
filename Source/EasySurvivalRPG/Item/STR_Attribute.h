#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"

#include "STR_Attribute.generated.h"

USTRUCT(BlueprintType)
struct EASYSURVIVALRPG_API FSTR_Attribute
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDataTableRowHandle GameplayTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;
};
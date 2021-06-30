#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "E_ResourceType.h"

#include "STR_ResourceValue.generated.h"

USTRUCT(BlueprintType)
struct EASYSURVIVALRPG_API FSTR_ResourceValue
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EResourceType ResourceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;
};
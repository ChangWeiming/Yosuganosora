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
		FText Description;//��Ʒ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D*  Icon;//��Ʒ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FS_STR_Item> ResultItems;//��������������Ʒ

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FS_STR_Item> RequiredItems;//����������Ʒ����Ҫ����Ʒ

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RequiredTime;//������Ʒ�����ʣ��ʱ��

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Experience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer Tags;


};

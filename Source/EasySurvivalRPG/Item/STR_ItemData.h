#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "STR_Attribute.h"

#include "STR_ItemData.generated.h"

class AItem;

USTRUCT(BlueprintType)
struct EASYSURVIVALRPG_API FSTR_ItemData
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

	//Basic info
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AItem* ItemClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxStack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxCharges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxDurability;

	//Maps to basic info
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, UStaticMesh*> StaticMeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, UStaticMesh*> SkeletalMeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, USoundBase*> Sounds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, FDataTableRowHandle> Handles;

	//Game control
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer ItemTags;
	//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	FSTRCostValue CostValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSTR_Attribute EquipmentAttributes;

	//additional settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanDecay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DecayTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDataTableRowHandle DecayItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Weight;
	//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	AAbilityBase UseAbilityClass;
};
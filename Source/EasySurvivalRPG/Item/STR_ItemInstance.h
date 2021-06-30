// Easy Systems

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "Sound/SoundBase.h"
#include "GameplayTagContainer.h"

#include "Item.h"
#include "STR_Attribute.h"
#include "STR_CostValue.h"

#include "STR_ItemInstance.generated.h"

USTRUCT(BlueprintType)
struct EASYSURVIVALRPG_API FSTR_ItemInstance
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDataTableRowHandle ItemHandle;
	
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSTR_CostValue CostValue;
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

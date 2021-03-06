// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "STR_ItemData.h"
#include "STR_ItemInstance.h"
#include "STR_Item.h"
#include "STR_ResourceValue.h"

#include "ItemsLibrary.generated.h"

/**
 * 
 */
UCLASS()
class EASYSURVIVALRPG_API UItemsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static bool ItemHandle(FDataTableRowHandle itemHandle);
	
	//Returns true if item data is valid.
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|State", WorldContext = "__WorldContext", OverrideNativeName = "ItemIsValid"))
	static void ItemIsValid(FSTR_ItemData Item, UObject* WorldContext,
		/*out*/ bool& IsValid);
	
	//Returns true if item instance is valid.
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|State", WorldContext = "__WorldContext", OverrideNativeName = "ItemInstanceIsValid"))
	static void ItemInstanceIsValid(FSTR_ItemInstance ItemInstance, UObject* WorldContext,
		/*out*/ bool& IsValid);

	//Returns item drop mesh
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Property", WorldContext = "__WorldContext", OverrideNativeName = "GetItemDropMesh"))
	static void GetItemDropMesh(FSTR_ItemData Item, UObject* WorldContext, 
		/*out*/ UStaticMesh*& StaticMesh);
	
	//Returns item icon.
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Property", WorldContext = "__WorldContext", OverrideNativeName = "GetItemIcon"))
	static void GetItemIcon(FSTR_ItemData bpp__Item__pf, UObject* WorldContext, 
		/*out*/ UTexture2D*& Icon);
	
	//Returns item amount
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Property", WorldContext = "__WorldContext", OverrideNativeName = "GetItemAmount"))
	static void GetItemAmount(FSTR_ItemData Item, UObject* WorldContext, 
		/*out*/ int32& Amount);
	
	//Make item data by instance
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|MakeItems", WorldContext = "__WorldContext", OverrideNativeName = "MakeItem"))
	static void MakeItem(FSTR_ItemInstance ItemInstance, int32 Amount, int32 Charges, float Durability, float Decay, UObject* WorldContext, 
		/*out*/ FSTR_ItemData& Item);

	//Make valid item decay value for item instance.
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|Make Items", WorldContext = "__WorldContext", OverrideNativeName = "MakeItemDecay"))
	static void MakeItemDecay(FSTR_ItemInstance const& ItemInstance, float Decay, UObject* WorldContext,
		/*out*/ float& ResultDecay);

	//Make valid item amount value for item instance.
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|Make Items", WorldContext = "__WorldContext", OverrideNativeName = "MakeItemAmount"))
	static void MakeItemAmount(FSTR_ItemInstance const& ItemInstance, int32 Amount, UObject* WorldContext,
		/*out*/ int32& ResultAmount);

	//Make valid item durability value for item instance
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|Make Items", WorldContext = "__WorldContext", OverrideNativeName = "MakeItemDurability"))
	static void MakeItemDurability(FSTR_ItemInstance const& ItemInstance, float Durability, UObject* WorldContext,
		/*out*/ float& ResultDurability);

	//Make valid item charges value for item instance
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|Make Items", WorldContext = "__WorldContext", OverrideNativeName = "MakeItemCharges"))
	static void MakeItemCharges(FSTR_ItemInstance const& ItemInstance, int32 Charges, UObject* WorldContext,
		/*out*/ int32& ResultCharges);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Property", WorldContext = "__WorldContext", OverrideNativeName = "GetItemID"))
	static void GetItemID(FSTR_ItemData Item, UObject* WorldContext, 
		/*out*/ FName& ItemID);
	
	UFUNCTION(BlueprintCallable, meta = (Category = "Items Library|Utility|Calculations", WorldContext = "__WorldContext", OverrideNativeName = "RemoveFromItemAmount"))
	static void RemoveFromItemAmount(FSTR_ItemData Item, int32 AmountToRemove, UObject* WorldContext,
		/*out*/ bool& WasRemoved, /*out*/ FSTR_ItemData& ResultItem, /*out*/ int32& AmountRemoved);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|Calculations", WorldContext = "__WorldContext", OverrideNativeName = "SetItemAmount"))
	static void SetItemAmount(FSTR_ItemData Item, int32 Amount, UObject* WorldContext, /*out*/ FSTR_ItemData& ResultItem);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|Other", WorldContext = "__WorldContext", OverrideNativeName = "CreateRequiredItemsList"))
	static void CreateRequiredItemsList(UObject* WorldContext,
		/*out*/ TArray<FSTR_Item>& RequiredItems, /*out*/ TMap<FName, int32>& ItemsList);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Property", WorldContext = "__WorldContext", OverrideNativeName = "GetItemAmountWeight"))
	static void GetItemAmountWeight(FSTR_ItemData Item, UObject* WorldContext, 
		/*out*/ float& Weight);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|Make Items", WorldContext = "__WorldContext", OverrideNativeName = "MakeItemsDataFromItem"))
	static void MakeItemsDataFromItem(FSTR_Item Item, UObject* WorldContext, 
		/*out*/ TArray<FSTR_ItemData>& Items);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|Make Items", WorldContext = "__WorldContext", OverrideNativeName = "MakeItemInstance"))
	static void MakeItemInstance(FDataTableRowHandle ItemHandle, UObject* WorldContext,
		/*out*/ FSTR_ItemInstance& ItemInstance);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|State", WorldContext = "__WorldContext", OverrideNativeName = "ItemIsResource"))
	static void ItemIsResource(FSTR_ItemData Item, UObject* WorldContext, 
		/*out*/ bool& Result);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Property", WorldContext = "__WorldContext", OverrideNativeName = "GetItemTags"))
	static void GetItemTags(FSTR_ItemData Item, UObject* WorldContext, 
		/*out*/ FGameplayTagContainer& ItemTags);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Property", WorldContext = "__WorldContext", OverrideNativeName = "GetItemResources"))
	static void GetItemResources(FSTR_ItemData Item, UObject* WorldContext,
		/*out*/ TArray<FSTR_ResourceValue>& Resources);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Property", WorldContext = "__WorldContext", OverrideNativeName = "GetItemCostResources"))
	static void GetItemCostResources(FSTR_ItemData Item, UObject* WorldContext,
		/*out*/ TArray<FSTR_ResourceValue>& ResourcesCost);

	//Add amount to item stack.
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|Calculations", WorldContext = "__WorldContext", OverrideNativeName = "GetItemMaxStack"))
	static void GetItemMaxStack(FSTR_ItemData Item, UObject* WorldContext,
		/*out*/ int32& MaxStack);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|Utility|Calculations", Tooltip = "Add amount to item stack.", WorldContext = "__WorldContext", OverrideNativeName = "AddToItemAmount"))
	static void AddToItemAmount(FSTR_ItemData Item, int32 AmountToAdd, UObject* WorldContext, 
		/*out*/ FSTR_ItemData& ResultItem);

	UFUNCTION(BlueprintCallable, meta = (Category = "Items Library|Utility|Calculations", WorldContext = "__WorldContext", OverrideNativeName = "MultiplyResources"))
	static void MultiplyResources(TArray<FSTR_ResourceValue>& Resources, float Multiplier, UObject* WorldContext, 
		/*out*/ TArray<FSTR_ResourceValue>& ResultResources);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Items Library|State",  WorldContext = "__WorldContext", OverrideNativeName = "ItemIsStackable"))
	static void ItemIsStackable(FSTR_ItemData Item, UObject* WorldContext, 
		/*out*/ bool& Result);


};


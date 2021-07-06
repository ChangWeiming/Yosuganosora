// Easy Systems


#include "ItemsLibrary.h"
#include "BlueprintGameplayTagLibrary.h" 
#include "Kismet/KismetMathLibrary.h"
#include "GeneratedCodeHelpers.h"

bool UItemsLibrary::ItemHandle(FDataTableRowHandle itemHandle) {
	return itemHandle.RowName != "None" &&
		IsValid(itemHandle.DataTable);
}

void UItemsLibrary::ItemIsValid(FSTR_ItemData Item, UObject* WorldContext, 
	/*输出*/ bool& IsValid)
{
	IsValid = UKismetMathLibrary::NotEqual_NameName(Item.ItemHandle.RowName, FName(TEXT("None")));
}

void UItemsLibrary::ItemInstanceIsValid(FSTR_ItemInstance ItemInstance, UObject* WorldContext,
	/*输出*/ bool& IsValid)
{
	IsValid = UKismetMathLibrary::NotEqual_NameName(ItemInstance.ItemHandle.RowName, FName(TEXT("None")));
}

void UItemsLibrary::GetItemDropMesh(FSTR_ItemData Item, UObject* WorldContext,
	/*输出*/ UStaticMesh*& StaticMesh)
{
	TArray<UStaticMesh*> staticMeshes;
	UStaticMesh* resMesh;
	staticMeshes.Reset();

	FCustomThunkTemplates::Map_Values(Item.StaticMeshes, 
		staticMeshes);

	FCustomThunkTemplates::Array_Get(staticMeshes, 0,
		resMesh);

	StaticMesh = resMesh;
}

void UItemsLibrary::GetItemIcon(FSTR_ItemData Item, UObject* WorldContext, 
	/*输出*/ UTexture2D*& Icon)
{
	Icon = Item.Icon;
}

void UItemsLibrary::GetItemAmount(FSTR_ItemData Item, UObject* WorldContext, 
	/*输出*/ int32& Amount)
{
	Amount = Item.Amount;
}

//unimplemented.
void UItemsLibrary::MakeItem(FSTR_ItemInstance ItemInstance, int32 Amount, int32 Charges, float Durability, float Decay, UObject* WorldContext,
	/*输出*/ FSTR_ItemData& Item)
{
	float clampedDecay{};
	float clampedDuribility{};
	int32 clampedCharges{};
	int32 clampedAmount{};
	
	UItemsLibrary::MakeItemDecay(ItemInstance, Decay, WorldContext, 
		/*out*/ clampedDecay);
	UItemsLibrary::MakeItemDurability(ItemInstance, Durability, WorldContext, 
		/*out*/ clampedDuribility);
	UItemsLibrary::MakeItemCharges(ItemInstance, Charges, WorldContext, 
		/*out*/ clampedCharges);
	UItemsLibrary::MakeItemAmount(ItemInstance, Amount, WorldContext, 
		/*out*/ clampedAmount);
	
	Item.ItemHandle = ItemInstance.ItemHandle;
	Item.Amount = clampedAmount;
	Item.Charges = clampedCharges;
	Item.Durability = clampedDuribility;
	Item.Decay = clampedDecay;
	Item.Name = ItemInstance.Name;
	Item.Description = ItemInstance.Description;
	Item.Icon = ItemInstance.Icon;
	Item.ItemClass = ItemInstance.ItemClass;
	Item.MaxStack = ItemInstance.MaxStack;
	Item.MaxCharges = ItemInstance.MaxCharges;
	Item.MaxDurability = ItemInstance.MaxDurability;
	Item.StaticMeshes = ItemInstance.StaticMeshes;
	Item.SkeletalMeshes = ItemInstance.SkeletalMeshes;
	Item.Sounds = ItemInstance.Sounds;
	Item.Handles = ItemInstance.Handles;
	Item.ItemTags = ItemInstance.ItemTags;
	Item.CostValue= ItemInstance.CostValue;
//	Item.EquipmentAttributes = ItemInstance.EquipmentAttributes;
	Item.CanDecay = ItemInstance.CanDecay;
	Item.DecayTime = ItemInstance.DecayTime;
	Item.DecayItem = ItemInstance.DecayItem;
	Item.Weight = ItemInstance.Weight;
	Item.UseAbilityClass = ItemInstance.UseAbilityClass;
}
void UItemsLibrary::MakeItemAmount(FSTR_ItemInstance const& ItemInstance_const, int32 Amount, UObject* WorldContext, 
	/*out*/ int32& resAmount)
{
	FSTR_ItemInstance& ItemInstance = *const_cast<FSTR_ItemInstance *>(&ItemInstance_const);
	int32 selectDefault{};

	resAmount = UKismetMathLibrary::Clamp(TSwitchValue<bool, int32 >(
		UKismetMathLibrary::EqualEqual_IntInt(Amount, 0) ,
		selectDefault, 2,
		TSwitchPair<bool, int32 >(false, Amount),
		TSwitchPair<bool, int32 >(true, ItemInstance.MaxStack)),
		0, ItemInstance.MaxStack);
}

void UItemsLibrary::MakeItemDurability(FSTR_ItemInstance const& ItemInstance_const, float Durability, UObject* WorldContext, 
	/*out*/ float& resDurability)
{
	FSTR_ItemInstance& ItemInstance = *const_cast<FSTR_ItemInstance *>(&ItemInstance_const);
	float selectDefault{};

	resDurability = UKismetMathLibrary::FClamp(TSwitchValue<bool, float >(
		UKismetMathLibrary::Less_FloatFloat(Durability, 0.000000),
		selectDefault, 2,
		TSwitchPair<bool, float >(false, Durability),
		TSwitchPair<bool, float >(true, ItemInstance.MaxDurability)),
		0.000000, ItemInstance.MaxDurability);
}

void UItemsLibrary::MakeItemDecay(FSTR_ItemInstance const& ItemInstance_const, float Decay, UObject* WorldContext, 
	/*out*/ float& resDecay)
{
	FSTR_ItemInstance& ItemInstance = *const_cast<FSTR_ItemInstance *>(&ItemInstance_const);

	bool isDecayEqualZero{};
	float floatV{};
	float selectDefault{};
	float selectDefault1{};

	isDecayEqualZero = UKismetMathLibrary::EqualEqual_FloatFloat(Decay, 0.000000);

	floatV = 0.000000;

	resDecay = UKismetMathLibrary::FClamp(
		TSwitchValue<bool, float >(ItemInstance.CanDecay, selectDefault1,
			2,
			TSwitchPair<bool, float >(false, floatV),
			TSwitchPair<bool, float >(true,
				TSwitchValue<bool, float >(isDecayEqualZero, selectDefault,
					2,
					TSwitchPair<bool, float >(false, Decay),
					TSwitchPair<bool, float >(true, ItemInstance.DecayTime)))),
		0.000000, ItemInstance.DecayTime);
}

void UItemsLibrary::MakeItemCharges(FSTR_ItemInstance const& ItemInstance_const, int32 Charges, UObject* WorldContext,
	/*out*/ int32& resCharges)
{
	FSTR_ItemInstance& ItemInstance = *const_cast<FSTR_ItemInstance *>(&ItemInstance_const);
	int32 selectDefault{};

	resCharges = UKismetMathLibrary::Clamp(TSwitchValue<bool, int32 >(
		UKismetMathLibrary::Less_IntInt(Charges, 0),
		selectDefault,
		2,
		TSwitchPair<bool, int32 >(false, Charges),
		TSwitchPair<bool, int32 >(true, ItemInstance.MaxCharges)),
		0, ItemInstance.MaxCharges);
}

void UItemsLibrary::GetItemID(FSTR_ItemData Item, UObject* WorldContext,
	/*out*/ FName& ItemID)
{
	ItemID = Item.ItemHandle.RowName;
}

void UItemsLibrary::RemoveFromItemAmount(FSTR_ItemData Item, int32 AmountToRemove, UObject* WorldContext,
	/*out*/ bool& WasRemoved, /*out*/ FSTR_ItemData& ResultItem, /*out*/ int32& AmountRemoved)
{
	int32 itemAmount = 0;
	GetItemAmount(Item, WorldContext, itemAmount);
	if (itemAmount >= AmountToRemove) {
		SetItemAmount(Item, itemAmount - AmountToRemove, WorldContext, ResultItem);
		AmountRemoved = AmountToRemove;
		WasRemoved = true;
	}
	else {
		WasRemoved = false;
		AmountRemoved = AmountToRemove;
	}
}

void UItemsLibrary::SetItemAmount(FSTR_ItemData Item, int32 Amount, UObject* WorldContext, 
	/*out*/ FSTR_ItemData& ResultItem)
{
	FSTR_ItemData bpfv__K2Node_SetFieldsInStruct_StructOut__pf{};
	Item.Amount = Amount;
	ResultItem = Item;
}

void UItemsLibrary::CreateRequiredItemsList(UObject* WorldContext,
	/*out*/ TArray<FSTR_Item>& RequiredItems, /*out*/ TMap<FName, int32>& ItemsList)
{
	for (auto &item : RequiredItems) {
		ItemsList.Add(item.ItemHandle.RowName, item.Amount);
	}
}

void UItemsLibrary::GetItemAmountWeight(FSTR_ItemData Item, UObject* WorldContext,
	/*out*/ float& Weight)
{
	Weight = Item.Amount * Item.Weight;
}

void UItemsLibrary::MakeItemsDataFromItem(FSTR_Item Item, UObject* WorldContext,
	/*out*/ TArray<FSTR_ItemData>& Items) {
	FSTR_ItemInstance itemInstance{};
	UItemsLibrary::MakeItemInstance(Item.ItemHandle, WorldContext, 
		itemInstance);

	for (int32 i = 0; i < Item.Amount / itemInstance.MaxStack - 1; ++i) {
		FSTR_ItemData itemResult{};
		UItemsLibrary::MakeItem(itemInstance, Item.Amount, Item.Charges, Item.Durability, Item.Decay, WorldContext, 
			itemResult);
		Items.Add(itemResult);
	}

	if (Item.Amount % itemInstance.MaxStack != 0) {
		FSTR_ItemData itemResult{};
		UItemsLibrary::MakeItem(itemInstance, Item.Amount % itemInstance.MaxStack, Item.Charges, Item.Durability, Item.Decay, WorldContext,
			itemResult);
		Items.Add(itemResult);
	}
}


void UItemsLibrary::MakeItemInstance(FDataTableRowHandle ItemHandle, UObject* WorldContext, 
	/*out*/ FSTR_ItemInstance& ItemInstance)
{
	FSTR_ItemInstance OutRow{};
	bool ok = false;
	ok = FCustomThunkTemplates::GetDataTableRowFromName(const_cast<UDataTable*>(ItemHandle.DataTable), ItemHandle.RowName,
		OutRow);
	if (ok)
	{
		ItemInstance = OutRow;
	}
}

void UItemsLibrary::GetItemTags(FSTR_ItemData Item, UObject* WorldContext,
	/*out*/ FGameplayTagContainer& ItemTags)
{

}

void UItemsLibrary::ItemIsResource(FSTR_ItemData Item, UObject* WorldContext,
	/*out*/ bool& Result)
{
	FGameplayTagContainer tagContainer{};
	UItemsLibrary::GetItemTags(Item, WorldContext,
		/*out*/ tagContainer);

	const UScriptStruct* nullStruct = FGameplayTag::StaticStruct();
	uint8* structSize = (uint8*)FMemory_Alloca(nullStruct->GetStructureSize());
	
	nullStruct->InitializeStruct(structSize);
	FGameplayTag& tag = *reinterpret_cast<FGameplayTag*>(structSize);
	
	auto& name = (*(AccessPrivateProperty<FName >(&(tag), FGameplayTag::__PPO__TagName())));
	name = FName(TEXT("EasyRPG.Items.Resource"));

	Result = tagContainer.HasTag(tag);
}

void UItemsLibrary::GetItemResources(FSTR_ItemData Item, UObject* WorldContext,
	/*out*/ TArray<FSTR_ResourceValue>& Resources)
{
	TArray<FSTR_ResourceValue> ResourcesCost{};
	int32 amount{};
	float floatConverted{};
	UItemsLibrary::GetItemCostResources(Item, WorldContext, ResourcesCost);
	UItemsLibrary::GetItemAmount(Item, WorldContext, amount);
	floatConverted = UKismetMathLibrary::Conv_IntToFloat(amount);
	
	UItemsLibrary::MultiplyResources( ResourcesCost, floatConverted, WorldContext,
		/*out*/ Resources);
}

void UItemsLibrary::GetItemCostResources(FSTR_ItemData Item, UObject* WorldContext,
	/*out*/ TArray<FSTR_ResourceValue>& ResourcesCost)
{
	ResourcesCost = Item.CostValue.CostResources;
}

void UItemsLibrary::MultiplyResources(TArray<FSTR_ResourceValue>& Resources, float Multiplier, UObject* WorldContext,
	/*out*/ TArray<FSTR_ResourceValue>& ResultResources)
{
	for (auto &r : Resources) {
		FSTR_ResourceValue tmp{};
		tmp.ResourceType = r.ResourceType;
		tmp.Value = r.Value * Multiplier;
		ResultResources.Add(tmp);
	}
}

void UItemsLibrary::ItemIsStackable(FSTR_ItemData Item, UObject* WorldContext,
	/*out*/ bool& Result)
{
	Result = Item.MaxStack > 1;
}

void UItemsLibrary::GetItemMaxStack(FSTR_ItemData Item, UObject* WorldContext,
	/*out*/ int32& MaxStack)
{
	MaxStack = Item.MaxStack;
}

void UItemsLibrary::AddToItemAmount(FSTR_ItemData Item, int32 AmountToAdd, UObject* WorldContext,
	/*out*/ FSTR_ItemData& ResultItem)
{
	int32 nowAmount{};
	int32 maxStack{};
	int32 addedSum{};
	UItemsLibrary::GetItemAmount(Item, WorldContext, nowAmount);
	UItemsLibrary::GetItemMaxStack(Item, WorldContext, maxStack);
	addedSum = UKismetMathLibrary::Add_IntInt(nowAmount, AmountToAdd);
	addedSum = UKismetMathLibrary::Clamp(addedSum, 0, maxStack);

	Item.Amount = addedSum;
	ResultItem = Item;
}
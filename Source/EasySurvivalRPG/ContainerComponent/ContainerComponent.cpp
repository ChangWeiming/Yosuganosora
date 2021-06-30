// Easy Systems


#include "ContainerComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GeneratedCodeHelpers.h"
#include "../Item/ItemsLibrary.h"

// Sets default values for this component's properties
UContainerComponent::UContainerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UContainerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UContainerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UContainerComponent::TryAddItemsOrDrop(/*out*/ TArray<FSTR_Item>& ResultItemResultItem)
{

}

void UContainerComponent::CheckRequiredItems(/*out*/ TArray<FSTR_Item>& RequiredItems, bool& Results)
{
	TMap<FName, int32> targetList{};
	GetItemList(targetList);
	for (FSTR_Item &item : RequiredItems) {
		if (targetList.Contains(item.ItemHandle.RowName) && targetList[item.ItemHandle.RowName] >= item.Amount) {
			continue;
		}
		else {
			Results = false;
			return; 
		}
	}
	Results = true;

}

void UContainerComponent::GetItemList(/*out*/ TMap<FName, int32>& ItemList)
{
	for (auto &item : Items) {
		FName itemID{};
		int32 totAmount = 0;
		UItemsLibrary::GetItemID(item, nullptr, itemID);
		if (ItemList.Contains(itemID)) {
			totAmount += ItemList[itemID];
		}

		ItemList.Add(itemID, totAmount);
	}
}

void UContainerComponent::CalculateWeight()
{
	float nowWeight = 0.0f;
	for (FSTR_ItemData &item : Items) {
		bool validResult = false;
		UItemsLibrary::ItemIsValid(item, nullptr, validResult);
		if (validResult) {
			float weight = 0.0f;
			UItemsLibrary::GetItemAmountWeight(item, nullptr, weight);
			nowWeight += weight;
		}
	}

	if (UKismetMathLibrary::NotEqual_FloatFloat(nowWeight, this->Weight)) {
		this->Weight = nowWeight;
		OnWeightChanged.Broadcast(nowWeight);
	}

}

void UContainerComponent::SetItem(int32 Slot, FSTR_ItemData Item) 
{
	FCustomThunkTemplates::Array_Set(Items, Slot, Item, true);

	this->CalculateWeight();

	for (auto &player : ActivePlayers) {
		this->UpdateContainerSlotBPI(player, this, Slot, Item);
	}

	bool validResult = false;
	UItemsLibrary::ItemIsValid(Item, nullptr, validResult);
	if (validResult && Item.CanDecay) {
		FCustomThunkTemplates::Array_AddUnique(DecaySlots, Slot);
	}
	else {
		FCustomThunkTemplates::Array_RemoveItem(DecaySlots, Slot);
	}
	OnSlotItemChanged.Broadcast(Slot, Item);
}

void UContainerComponent::RemoveRequiredItems(/*out*/ TArray<FSTR_Item>& RequiredItems) {
	TMap<FName, int32> items{};
	UItemsLibrary::CreateRequiredItemsList(nullptr, RequiredItems, items);
	

	for (int32 idx = 0; idx != Items.Num(); ++idx) {
		auto item = Items[idx];
		bool validResult = false;
		UItemsLibrary::ItemIsValid(item, nullptr, validResult);
		if (validResult) {
			FName itemID("");
			UItemsLibrary::GetItemID(item, nullptr, itemID);
			if (items.Contains(itemID)) {
				int32 remainingAmount = items[itemID];

				bool removed = false;
				FSTR_ItemData result;
				int32 amountRemoved = 0;
				UItemsLibrary::RemoveFromItemAmount(item, remainingAmount, nullptr, removed, result, amountRemoved);

				SetItem(idx, result);

				if (remainingAmount - amountRemoved > 0) {
					items.Add(itemID, remainingAmount - amountRemoved);
				}
				else {
					items.Remove(itemID);
				}
			}
		}
	}
}

void UContainerComponent::AddResources(TArray<FSTR_ResourceValue>& Resource)
{

}

void UContainerComponent::AddResource(FSTR_ResourceValue const& Resource)
{
	bool added = false;
	for (auto &r : this->Resources) {
		if (r.ResourceType == Resource.ResourceType) {
			r.Value += Resource.Value;
			added = true;
		}
		if (added) break;
	}
	if (!added) {
		Resources.Add(Resource);
	}

	for (auto player : ActivePlayers) {
		this->UpdateContainerResourcesBPI(player, this, Resources);
	}
}

void UContainerComponent::UpdateContainerSlotBPI_Implementation(APlayerController* target, UContainerComponent* container, int32 slot, FSTR_ItemData item)
{

}

void UContainerComponent::UpdateContainerResourcesBPI_Implementation(APlayerController* target, UContainerComponent* container, TArray<FSTR_ResourceValue>& updatedResources)
{

}
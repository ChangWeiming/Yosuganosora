// Easy Systems


#include "ContainerComponent.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

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
	for (auto &r : Resource) {
		this->AddResource(r);
	}
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

void UContainerComponent::GetItem(int32 Slot, 
	/*out*/ FSTR_ItemData& Item)
{
	FCustomThunkTemplates::Array_Get(Items, Slot, /*out*/ Item);
}

void UContainerComponent::AddAmountToSlot(int32 Slot, int32 AmountToAdd,
	/*out*/ int32& AmountRemaining)
{
	AmountRemaining = AmountToAdd;
	FSTR_ItemData item{};
	this->GetItem(Slot, item);

	int32 itemAmount, maxStack;
	UItemsLibrary::GetItemAmount(item, nullptr, itemAmount);
	UItemsLibrary::GetItemMaxStack(item, nullptr, maxStack);

	if (itemAmount < maxStack) {
		FSTR_ItemData addedItem{};

		if (AmountToAdd <= maxStack - itemAmount) {
			AmountRemaining = 0;
			UItemsLibrary::AddToItemAmount(item, AmountToAdd, nullptr, addedItem);
		}
		else {
			AmountRemaining = AmountToAdd - (maxStack - itemAmount);
			UItemsLibrary::AddToItemAmount(item, maxStack - itemAmount, nullptr, addedItem);
		}
		this->SetItem(Slot, addedItem);
	}
}

void UContainerComponent::AddItemToStacks(FSTR_ItemData Item,
	/*out*/ int32& AmountRemaining)
{
	FName itemID{};
	int32 amount = 0;
	UItemsLibrary::GetItemID(Item, nullptr, itemID);
	UItemsLibrary::GetItemAmount(Item, nullptr, amount);

	for (int32 idx = 0; idx < Items.Num(); ++idx) {
		auto &item = Items[idx];
		FName nowItemID{};
		bool stackable = false;
		UItemsLibrary::ItemIsStackable(item, nullptr, stackable);
		UItemsLibrary::GetItemID(item, nullptr, nowItemID);
		if (nowItemID == itemID && stackable) {
			this->AddAmountToSlot(idx, amount, AmountRemaining);
			amount = AmountRemaining;
			if (AmountRemaining == 0) {
				return;
			}
		}
	}
	AmountRemaining = amount;
}

void UContainerComponent::TryAddItemsOrDrop(TArray<FSTR_Item>& AddedItems)
{
	for (auto &item : AddedItems) {
		TArray<FSTR_ItemData> items;
		UItemsLibrary::MakeItemsDataFromItem(item, nullptr, items);
		for (auto &it : items) {
			bool validResult = false;
			UItemsLibrary::ItemIsValid(it, nullptr, validResult);
			if (validResult) {
				bool success = false;
				FSTR_ItemData remainingItem{};
				this->TryAddItem(it, success, remainingItem);
				if (!success) {
					this->SpawnDropItem(remainingItem);
				}
			}
		}
	}
}

void UContainerComponent::TryAddItem(FSTR_ItemData Item,
	/*out*/ bool& Success, FSTR_ItemData& RemainingItem)
{
	int32 totAmount = 0;
	UItemsLibrary::GetItemAmount(Item, nullptr, totAmount);

	bool validResult = false;
	UItemsLibrary::ItemIsValid(Item, nullptr, validResult);
	
	if (validResult) {
		bool isResource = false;
		UItemsLibrary::ItemIsResource(Item, nullptr, isResource);
		if (isResource) {
			//resource type
			TArray<FSTR_ResourceValue> itemResources;
			UItemsLibrary::GetItemResources(Item, nullptr, itemResources);
			this->AddResources(itemResources);
			OnItemAdded.Broadcast(Item);
			Success = true;
			return;
		}
		else {
			//item type
			bool isStackable = false;
			UItemsLibrary::ItemIsStackable(Item, nullptr, isStackable);
			
			if (isStackable) {
				// item type && stackable
				int32 remainingAmount = 0;
				this->AddItemToStacks(Item, remainingAmount);

				if (remainingAmount == 0) {
					// item type && stackable && no remains
					OnItemAdded.Broadcast(Item);
					Success = true;
					return;
				}
				else {
					// item type && stackable && reamins so it is necessary to add to empty slot
					int32 emptySlot = 0;
					bool haveEmptySlot = false;
					this->GetEmptySlot(haveEmptySlot, emptySlot);
					UItemsLibrary::SetItemAmount(Item, remainingAmount, nullptr, RemainingItem);
					
					if (haveEmptySlot) {
						this->SetItem(emptySlot, RemainingItem);
						
						OnItemAdded.Broadcast(Item);
						Success = true;
						return;
					} 
					//fall to failure case
				}
			}
			else {
				// item type && not stackable
				int32 emptySlot = 0;
				bool haveEmptySlot = false;
				this->GetEmptySlot(haveEmptySlot, emptySlot);
				if (haveEmptySlot) {
					this->SetItem(emptySlot, Item);

					OnItemAdded.Broadcast(Item);
					Success = true;
					return;
				}
				else {
					//fall to failure case
					RemainingItem = Item;
				}
			}

			//failure case
			int32 nowAmount;
			UItemsLibrary::GetItemAmount(RemainingItem, nullptr, nowAmount);
			if (totAmount > nowAmount) {
				UItemsLibrary::SetItemAmount(Item, totAmount - nowAmount, nullptr, Item);
				OnItemAdded.Broadcast(Item);
			}
			Success = false;

		}
	}
	else {
		Success = false;
	}
}

void UContainerComponent::GetEmptySlot(bool& Success, int32& Slot)
{
	for (int32 idx = 0; idx < Items.Num(); ++idx) {
		bool validResult = false;
		UItemsLibrary::ItemIsValid(Items[idx], nullptr, validResult);

		if (!validResult) {
			Success = true;
			Slot = idx;
			return;
		}
	}

	Success = false;
	Slot = 0;
}

void UContainerComponent::SpawnDropItem(FSTR_ItemData ItemData)
{
	FVector dropLocation(EForceInit::ForceInit);
	FTransform transform{};
	AActor* spawnedActor{};


	transform = UKismetMathLibrary::MakeTransform(dropLocation, UKismetMathLibrary::RandomRotator(false), FVector(1.000000, 1.000000, 1.000000));
	
	spawnedActor = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, (UClass*)ItemData.ItemClass, transform, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn, ((AActor*)nullptr));

	FCustomThunkTemplates::SetStructurePropertyByName(spawnedActor, FName(TEXT("ItemHandle")), ItemData.ItemHandle);
	UKismetSystemLibrary::SetIntPropertyByName(spawnedActor, FName(TEXT("Amount")), ItemData.Amount);
	UKismetSystemLibrary::SetIntPropertyByName(spawnedActor, FName(TEXT("Charges")), ItemData.Charges);
	UKismetSystemLibrary::SetFloatPropertyByName(spawnedActor, FName(TEXT("Durability")), ItemData.Durability);
	UKismetSystemLibrary::SetFloatPropertyByName(spawnedActor, FName(TEXT("Decay")), ItemData.Decay);
	this->GetDropLocation(/*out*/ dropLocation);

	transform = UKismetMathLibrary::MakeTransform(dropLocation, UKismetMathLibrary::RandomRotator(false), FVector(1.000000, 1.000000, 1.000000));
	CastChecked<AItem>(UGameplayStatics::FinishSpawningActor(spawnedActor, transform), ECastCheckedType::NullAllowed);
}

void UContainerComponent::GetDropLocation(FVector& TargetDropLocation) {
	if (!this->DropLocationOverrided) {
		if (::IsValid(this->DropPrimitiveComponent)) {
			TargetDropLocation = DropPrimitiveComponent->USceneComponent::K2_GetComponentLocation();
		}
		else {
			TargetDropLocation = UKismetMathLibrary::Add_VectorVector(UActorComponent::GetOwner()->AActor::K2_GetActorLocation(),
				FVector(0.000000, 0.000000, 100.000000));
		}

	}
	else {				
		this->DropLocation = TargetDropLocation;
	}
}

void UContainerComponent::UpdateContainerSlotBPI_Implementation(APlayerController* target, UContainerComponent* container, int32 slot, FSTR_ItemData item)
{

}

void UContainerComponent::UpdateContainerResourcesBPI_Implementation(APlayerController* target, UContainerComponent* container, TArray<FSTR_ResourceValue>& updatedResources)
{

}
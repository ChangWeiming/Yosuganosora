// Easy Systems


#include "ContainerComponent.h"
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

void UContainerComponent::RemoveRequiredItems(/*out*/ TArray<FSTR_Item>& RequiredItems)
{


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

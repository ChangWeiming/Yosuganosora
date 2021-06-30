// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Item/STR_ItemData.h"
#include "../Item/STR_Item.h"

#include "ContainerComponent.generated.h"

UDELEGATE(meta = (OverrideNativeName = "OnOpened__DelegateSignature"))
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpened);
UDELEGATE(meta = (OverrideNativeName = "OnClosed__DelegateSignature"))
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClosed);
UDELEGATE(meta = (OverrideNativeName = "OnSlotItemChanged__DelegateSignature"))
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSlotItemChanged, int32, Slot, FSTR_ItemData, Item);
UDELEGATE(meta = (OverrideNativeName = "OnWeightChanged__DelegateSignature"))
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeightChanged, float, Weight);
UDELEGATE(meta = (OverrideNativeName = "OnItemAdded__DelegateSignature"))
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemAdded, FSTR_ItemData, Item);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EASYSURVIVALRPG_API UContainerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UContainerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Slots", Category = "Settings", OverrideNativeName = "Slots"))
	int32 Slots;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Items", Category = "State", OverrideNativeName = "Items"))
	TArray<FSTR_ItemData> Items;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Resources", Category = "State", OverrideNativeName = "Resources"))
	TArray<FSTR_ResourceValue> Resources;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Active Players", Category = "State", OverrideNativeName = "ActivePlayers"))
	TArray<APlayerController*> ActivePlayers;
	
	//multicast delegates
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "On Opened", Category = "Bindings", OverrideNativeName = "OnOpened"))
	FOnOpened OnOpened;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "On Closed", Category = "Bindings", OverrideNativeName = "OnClosed"))
	FOnClosed OnClosed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "On Slot Item Changed", Category = "Bindings", OverrideNativeName = "OnSlotItemChanged"))
	FOnSlotItemChanged OnSlotItemChanged;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "On Weight Changed", Category = "Bindings", OverrideNativeName = "OnWeightChanged"))
	FOnWeightChanged OnWeightChanged;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "On Item Added", Category = "Bindings", OverrideNativeName = "OnItemAdded"))
	FOnItemAdded OnItemAdded;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Drop Primitive Component", Category = "State", OverrideNativeName = "DropPrimitiveComponent"))
	UPrimitiveComponent* DropPrimitiveComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Drop Location", Category = "State", OverrideNativeName = "DropLocation"))
	FVector DropLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Drop Location Overrided", Category = "State", OverrideNativeName = "DropLocationOverrided"))
	bool DropLocationOverrided;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Decay Factor", Category = "Settings", OverrideNativeName = "DecayFactor"))
	float DecayFactor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Decay Tick Time", Category = "Settings", OverrideNativeName = "DecayTickTime"))
	float DecayTickTime;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Decay Slots", Category = "State", OverrideNativeName = "DecaySlots"))
	TArray<int32> DecaySlots;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Weight", Category = "State", OverrideNativeName = "Weight"))
	float Weight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Save ID", Category = "State", OverrideNativeName = "SaveID"))
	int32 SaveID;

	//UPROPERTY(Transient, DuplicateTransient, meta = (OverrideNativeName = "K2Node_CustomEvent_Player_1"))
	//APlayerController* b0l__K2Node_CustomEvent_Player_1__pf;
	//UPROPERTY(Transient, DuplicateTransient, meta = (OverrideNativeName = "K2Node_CustomEvent_Player"))
	//APlayerController* b0l__K2Node_CustomEvent_Player__pf;

	//function declaration
	UFUNCTION(BlueprintCallable, meta = (Category = "Container|Items", OverrideNativeName = "TryAddItemsOrDrop"))
	virtual void TryAddItemsOrDrop(/*out*/ TArray<FSTR_Item>& ResultItem);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Container|Items", OverrideNativeName = "CheckRequiredItems"))
	virtual void CheckRequiredItems(/*out*/ TArray<FSTR_Item>& RequiredItems, 
		/*out*/ bool& Result);

	UFUNCTION(BlueprintCallable, meta = (Category = "Container|Items", OverrideNativeName = "RemoveRequiredItems"))
	virtual void RemoveRequiredItems(/*out*/ TArray<FSTR_Item>& RequiredItems);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Container|Items", Tooltip = "Returns map list of items.", OverrideNativeName = "GetItemList"))
	virtual void GetItemList(/*out*/ TMap<FName, int32>& ItemList);

	UFUNCTION(BlueprintCallable, meta = (Category = "Container|Items", OverrideNativeName = "CalculateWeight"))
	virtual void CalculateWeight();

	UFUNCTION(BlueprintCallable, meta = (Category = "Container|Items", OverrideNativeName = "SetItem"))
	virtual void SetItem(int32 Slot, FSTR_ItemData Item);

	UFUNCTION(BlueprintCallable, meta = (Category = "Container|Resources", Tooltip = "Adds resources to the container.", OverrideNativeName = "AddResources"))
	virtual void AddResources(/*out*/ TArray<FSTR_ResourceValue>& Resource);

	UFUNCTION(BlueprintCallable, meta = (Category = "Container|Resources", Tooltip = "Adds resource to the container.", OverrideNativeName = "AddResource"))
	virtual void AddResource(FSTR_ResourceValue const& Resource);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (Category = "InterfaceBP", OverrideNativeName = "UpdateContainerSlotBPI"))
	void UpdateContainerSlotBPI(APlayerController* target, UContainerComponent* container, int32 slot, FSTR_ItemData item);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (Category = "InterfaceBP", OverrideNativeName = "UpdateContainerResourcesBPI"))
	void UpdateContainerResourcesBPI(APlayerController* target, UContainerComponent* container, TArray<FSTR_ResourceValue>& updatedResources);
};

// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Item/STR_ItemData.h"
#include "../Item/STR_Item.h"

#include "ContainerComponent.generated.h"



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
	//UDELEGATE(meta = (OverrideNativeName = "OnOpened__DelegateSignature"))
	//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpened__pf__BP_ContainerComponent_C__pf__MulticastDelegate);
	//UDELEGATE(meta = (OverrideNativeName = "OnClosed__DelegateSignature"))
	//	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClosed__pf__BP_ContainerComponent_C__pf__MulticastDelegate);
	//UDELEGATE(meta = (OverrideNativeName = "OnSlotItemChanged__DelegateSignature"))
	//	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSlotItemChanged__pf__BP_ContainerComponent_C__pf__MulticastDelegate, int32, bpp__Slot__pf, FDEPRECATED_STR_ItemData__pf2029040651, bpp__Item__pf);
	//UDELEGATE(meta = (OverrideNativeName = "OnWeightChanged__DelegateSignature"))
	//	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeightChanged__pf__BP_ContainerComponent_C__pf__MulticastDelegate, float, bpp__Weight__pf);
	//UDELEGATE(meta = (OverrideNativeName = "OnItemAdded__DelegateSignature"))
	//	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemAdded__pf__BP_ContainerComponent_C__pf__MulticastDelegate, FDEPRECATED_STR_ItemData__pf2029040651, bpp__Item__pf);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Slots", Category = "Settings", OverrideNativeName = "Slots"))
	int32 Slots;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Items", Category = "State", OverrideNativeName = "Items"))
	TArray<FSTR_ItemData> Items;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, meta = (DisplayName = "Resources", Category = "State", OverrideNativeName = "Resources"))
	//	TArray<FSTR_Resource> bpv__Resources__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Active Players", Category = "State", OverrideNativeName = "ActivePlayers"))
	TArray<APlayerController*> ActivePlayers;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "On Opened", Category = "Bindings", OverrideNativeName = "OnOpened"))
	//	FOnOpened__pf__BP_ContainerComponent_C__pf__MulticastDelegate bpv__OnOpened__pf;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "On Closed", Category = "Bindings", OverrideNativeName = "OnClosed"))
	//	FOnClosed__pf__BP_ContainerComponent_C__pf__MulticastDelegate bpv__OnClosed__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Drop Primitive Component", Category = "State", OverrideNativeName = "DropPrimitiveComponent"))
	UPrimitiveComponent* DropPrimitiveComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Drop Location", Category = "State", OverrideNativeName = "DropLocation"))
	FVector DropLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Drop Location Overrided", Category = "State", OverrideNativeName = "DropLocationOverrided"))
	bool DropLocationOverrided;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "On Slot Item Changed", Category = "Bindings", OverrideNativeName = "OnSlotItemChanged"))
	//	FOnSlotItemChanged__pf__BP_ContainerComponent_C__pf__MulticastDelegate bpv__OnSlotItemChanged__pf;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Decay Factor", Category = "Settings", OverrideNativeName = "DecayFactor"))
	float DecayFactor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Decay Tick Time", Category = "Settings", OverrideNativeName = "DecayTickTime"))
	float DecayTickTime;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Decay Slots", Category = "State", OverrideNativeName = "DecaySlots"))
	TArray<int32> DecaySlots;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Weight", Category = "State", OverrideNativeName = "Weight"))
	float Weight;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "On Weight Changed", Category = "Bindings", OverrideNativeName = "OnWeightChanged"))
	//	FOnWeightChanged__pf__BP_ContainerComponent_C__pf__MulticastDelegate bpv__OnWeightChanged__pf;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintAssignable, BlueprintCallable, meta = (DisplayName = "On Item Added", Category = "Bindings", OverrideNativeName = "OnItemAdded"))
	//	FOnItemAdded__pf__BP_ContainerComponent_C__pf__MulticastDelegate bpv__OnItemAdded__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Save ID", Category = "State", OverrideNativeName = "SaveID"))
	int32 SaveID;
	//UPROPERTY(Transient, DuplicateTransient, meta = (OverrideNativeName = "K2Node_CustomEvent_Player_1"))
	//APlayerController* b0l__K2Node_CustomEvent_Player_1__pf;
	//UPROPERTY(Transient, DuplicateTransient, meta = (OverrideNativeName = "K2Node_CustomEvent_Player"))
	//APlayerController* b0l__K2Node_CustomEvent_Player__pf;

	UFUNCTION(BlueprintCallable, meta = (Category = "Container|Items", OverrideNativeName = "TryAddItemsOrDrop"))
	virtual void TryAddItemsOrDrop(/*out*/ TArray<FSTR_Item>& ResultItem);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Container|Items", OverrideNativeName = "CheckRequiredItems"))
	virtual void CheckRequiredItems(/*out*/ TArray<FSTR_Item>& RequiredItems, 
		/*out*/ bool& Result);

	UFUNCTION(BlueprintCallable, meta = (Category = "Container|Items", OverrideNativeName = "RemoveRequiredItems"))
	virtual void RemoveRequiredItems(/*out*/ TArray<FSTR_Item>& RequiredItems);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Container|Items", Tooltip = "Returns map list of items.", OverrideNativeName = "GetItemList"))
	virtual void GetItemList(/*out*/ TMap<FName, int32>& ItemList);

};

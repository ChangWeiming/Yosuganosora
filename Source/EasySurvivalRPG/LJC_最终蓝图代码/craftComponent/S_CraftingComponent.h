#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"	
#include "STR_Item.h"	
#include "Engine/DataTable.h"
#include "GameFramework/PlayerController.h"
#include "STR_QueueBlueprint.h"
#include "Components/ActorComponent.h"
#include "S_CraftingComponent.generated.h"


UCLASS(BlueprintType, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EASYSURVIVALRPG_API US_CraftingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	US_CraftingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//BlueprintImplementableEvent

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void CallTryAddItemsorDrop(const TArray<FS_STR_Item>&  TryItem);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void CallUpdateCraftingQueue_BPI(APlayerController* ActivePlayer);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void  CallMakeBlueprintRequiredItems(const FS_STR_Blueprint& MyBlueprint, int32 Myint, TArray<FS_STR_Item>& ReturnItem);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void  CallGetBlueprintFromHandle(const FDataTableRowHandle&  TableHandle, FS_STR_Blueprint& ReturnBlueprint);


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void  CallCheckRequiredItems(const TArray<FS_STR_Item>& STR_Item, bool& Reslut);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void  CallOverRmoveRequiredItems(const TArray<FS_STR_Item>& Items);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void  CallStartCrafting(const FS_STR_Blueprint& Blueprint, const int32& Amount);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void  CCOnCraftingStarted();

	UFUNCTION(BlueprintCallable, BlueprintPure, BlueprintImplementableEvent)
		void  GetCraftingBlueprints(TArray<FDataTableRowHandle>& Blueprints);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void  CallUpdateCraftingQueueBlueprint_BPI(APlayerController* PlayerController, const int32& IndexInQueue, const FS_STR_QueueBlueprint& QueueBlueprint);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void  CallMultiplyItems(const TArray<FS_STR_Item>& Items, const float& MultiPlier, TArray<FS_STR_Item>& ResultItems);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void  CCOnCraftingCompleted(const FS_STR_Blueprint& CCBlueprint, int32 CCAmount);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void  CCOnCraftingEnded();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void  CallCompleteCrafting_BPI(APlayerController* ComPlayer, const FS_STR_Blueprint& ComBlueprint, int32 ComAmount);


	UFUNCTION(BlueprintCallable)
		virtual void CancelCrafting(int32 IndexInQueue);

	UFUNCTION(BlueprintCallable)
		virtual void AddBlueprintToQueue(FS_STR_Blueprint Blueprint, int32 Amount);

	UFUNCTION(BlueprintCallable)
		virtual void AutoStartCrafting();

	UFUNCTION(BlueprintCallable)
		virtual void SetCraftingEnabled(bool Enable);

	UFUNCTION(BlueprintCallable, meta = (Category = "Crafting", Tooltip = "Crafting tick. Updates crafting blueprints time.", OverrideNativeName = "CraftingTick"))
		virtual void CraftingTick();

	UFUNCTION(BlueprintCallable, meta = (Category = "Crafting", Tooltip = "Complete crafting blueprint. Adds result items and adds experience.", OverrideNativeName = "CompleteCrafting"))
		void CompleteCrafting(FS_STR_Blueprint  Blueprint, int32 Amount = 1);

	UFUNCTION(BlueprintCallable, meta = (Category = "Crafting", Tooltip = "Updates queue blueprint widget by index.", OverrideNativeName = "Update Queue Blueprint"))
		void UpdateQueueBlueprint(int32 IndexInQueue,  FS_STR_QueueBlueprint  QueueBlueprint);

	UFUNCTION(BlueprintCallable, meta = (Category = "Crafting", Tooltip = "Remove bluepring from queue by index.", OverrideNativeName = "RemoveBlueprintFromQueue"))
		void RemoveBlueprintFromQueue(int32 IndexInQueue);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Private"))
		FTimerHandle CraftingTickTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Private"))
		TArray<APlayerController*> ActivePlayers;

	//用于储存当前要制作的物品的队列
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Private"))
		TArray<FS_STR_QueueBlueprint> BlueprintsQueue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Private"))
		int32 SaveID;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Settings", OverrideNativeName = "CraftingListHandle"))
		FDataTableRowHandle CraftingListHandle; */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Settings", OverrideNativeName = "CraftingEnabled"))
		bool CraftingEnabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Settings", OverrideNativeName = "Autocrafting"))
		bool Autocrafting;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Settings", OverrideNativeName = "CraftingTickTime"))
		float CraftingTickTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Settings", OverrideNativeName = "MulticraftCount"))
		int32 MulticraftCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Settings", OverrideNativeName = "CompleteEventBinds"))
		bool CompleteEventBinds;

};

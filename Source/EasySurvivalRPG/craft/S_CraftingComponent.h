// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/PlayerController.h"
#include "STR_QueueBlueprint.h"
#include "Components/ActorComponent.h"
#include "S_CraftingComponent.generated.h"


UCLASS(BlueprintType, Blueprintable,ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (Category = "Crafting", Tooltip = "Updates queue blueprint widget by index.", OverrideNativeName = "Update Queue Blueprint"))
		void UpdateQueueBlueprint(int32 IndexInQueue, FS_STR_QueueBlueprint  QueueBlueprint);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (Category = "Crafting", Tooltip = "Complete crafting blueprint. Adds result items and adds experience.", OverrideNativeName = "CompleteCrafting"))
		void CompleteCrafting(FS_STR_Blueprint  Blueprint, int32 Amount);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (Category = "Crafting", Tooltip = "Remove bluepring from queue by index.", OverrideNativeName = "RemoveBlueprintFromQueue"))
	    void RemoveBlueprintFromQueue(int32 IndexInQueue);

	UFUNCTION(BlueprintCallable, meta = (Category = "Crafting", Tooltip = "Crafting tick. Updates crafting blueprints time.", OverrideNativeName = "CraftingTick"))
		virtual void CraftingTick();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Private"))
		FTimerHandle CraftingTickTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Private"))
		TArray<APlayerController*> ActivePlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Private"))
		TArray<FSTR_QueueBlueprint> BlueprintsQueue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Private"))
		int32 SaveID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Settings", OverrideNativeName = "CraftingListHandle"))
		FDataTableRowHandle CraftingListHandle;
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

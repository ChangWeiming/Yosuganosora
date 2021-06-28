// Easy Systems

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "Components/StaticMeshComponent.h "
#include "STR_ItemData.h"

#include "Item.generated.h"

UCLASS()
class EASYSURVIVALRPG_API AItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Item")
	void DecayTick();
	UFUNCTION(BlueprintCallable, Category = "Item")
	void DestoryItem();
	UFUNCTION(BlueprintNativeEvent, Category = "Item")
	void PlayDropSound();
	UFUNCTION(BlueprintCallable, Category = "Item")
	void ConstructionInit();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	FDataTableRowHandle ItemHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 Charges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	float Durability;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	float Decay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	bool SimulatePhysics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	bool CanDecay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	bool InfinityItem;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float DecayTickTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float DestoryTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool InWater;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	FSTR_ItemData ItemData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	int32 SaveID;

};

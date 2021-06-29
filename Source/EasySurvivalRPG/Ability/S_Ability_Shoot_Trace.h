// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"
#include "UObject/UObjectGlobals.h"
#include "Runtime/CoreUObject/Public/UObject/NoExportTypes.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "GameFramework/PlayerController.h"
#include "Materials/MaterialInterface.h"
#include "Sound/SoundBase.h"
#include "Particles/ParticleSystem.h"
#include "S_Ability_Base.h"
#include "S_Ability_Shoot_Trace.generated.h"


/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class EASYSURVIVALRPG_API AS_Ability_Shoot_Trace : public AS_Ability_Base
{
	GENERATED_BODY()

public:
	AS_Ability_Shoot_Trace(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Shooting Range", Category = "Settings|Attributes"))
		float ShootingRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Base Damage", Category = "Settings|Attributes"))
		float BaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Tree Damage", Category = "Settings|Attributes"))
		float TreeDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Mine Damage", Category = "Settings|Attributes"))
		float MineDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Critical Damage Multiplier", Category = "Settings|Attributes"))
		float CriticalDamageMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHitResult LocalHit{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LocalHitItem{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPrimitiveComponent* LocalHitComponent{};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* LocalHitActor{};


	UPROPERTY(Transient, DuplicateTransient, meta = (OverrideNativeName = "K2Node_CreateDelegate_OutputDelegate"))
		FTimerDynamicDelegate TimerDynamicDelegate;
public:
	//UFUNCTION(BlueprintCallable)
	virtual void Use() override;
	
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
		void MyUse();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent,meta = (Tooltip = "Update shooting variables from the character.", OverrideNativeName = "Update Shooting Attributes"))
		void UpdateShootingAttributes();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (Tooltip = "Check hit result and deal specific damage to each actor type.", Category, OverrideNativeName = "CheckHit"))
		void CheckHit(FHitResult HitResult);
	//Try shoot trace and return hit result.
	

	UFUNCTION(BlueprintCallable)
		void TryShootTrace(FVector StartLocation, FRotator Rotation, float ShootingRange_S,  FHitResult& HitResult,  bool& WasHit);

	UFUNCTION(BlueprintCallable)
		void DealDamageToTree(AActor* DamagedActor, FHitResult HitResult);
	UFUNCTION(BlueprintCallable)
		void DealDamageToMine(AActor* DamagedActor, FHitResult HitResult);
	UFUNCTION(BlueprintCallable)
		void DealDamageToActor(AActor* DamagedActor, FHitResult HitResult);

};

// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Materials/MaterialInterface.h"
#include "Sound/SoundBase.h"
#include "Particles/ParticleSystem.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Ability_Base.h"
#include "Ability_Shoot_Trace.generated.h"

/**
 *
 */
UCLASS()
class EASYSURVIVALRPG_API AAbility_Shoot_Trace : public AAbility_Base
{
	GENERATED_BODY()



public:

	UFUNCTION(BlueprintCallable, meta = (Tooltip = "Try shoot trace and return hit result."))
		virtual void TryShootTrace(FVector StartLocation, FRotator Rotation, float TShootingRange, /*out*/ FHitResult&HitResult, /*out*/ bool& WasHit);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void CallPlaySoundAtLocation(USoundBase* Sound, FVector Location);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void CallSpawnParticleAtLocation(UParticleSystem* Particle, FVector Location, FRotator Rotation, FVector Scale = FVector(1.0f, 1.0f, 1.0f));
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void CallSpawnDecal(UMaterialInterface* DecalMaterial, FVector DecalSize, FVector Location, FRotator Rotation, float LifeSpan);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void CallGetAttributes_BPI(UObject* InputObject, float& TBaseDamage, float& BaseCriticalDamage, float& BaseShootingRange, float& BaseWoodcuttingDamage, float& BaseMiningDamage);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void CheckHit(FHitResult HitResult);
	UFUNCTION(BlueprintCallable)
		void UpdateShootingAttributes();
	UFUNCTION(BlueprintCallable)
		void CallUse();



	UFUNCTION(BlueprintCallable, meta = (Tooltip = "Play shoot hit effects depending on the hit surface type.", OverrideNativeName = "PlayHitEffects"))
		virtual void PlayHitEffects(FHitResult HitResult);

	UFUNCTION(BlueprintCallable)
		virtual void DealDamageToActor(AActor* DamagedActor, FHitResult HitResult);
	UFUNCTION(BlueprintCallable, meta = (Tooltip = "Deal damage to the mine actor.", Category, OverrideNativeName = "DealDamageToMine"))
		virtual void DealDamageToMine(AActor*  DamagedActor, FHitResult HitResult);
	UFUNCTION(BlueprintCallable, meta = (Tooltip = "Deal damage to the tree actor.", Category, OverrideNativeName = "DealDamageToTree"))
		virtual void DealDamageToTree(AActor* DamagedActor, FHitResult HitResult);

	UFUNCTION(BlueprintCallable)
		virtual void CallBlunderbussUse();


public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Shooting Range", Category = "Settings|Attributes", OverrideNativeName = "ShootingRange"))
		float ShootingRange = 2500.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Base Damage", Category = "Settings|Attributes", OverrideNativeName = "BaseDamage"))
		float BaseDamage = 10.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Tree Damage", Category = "Settings|Attributes", OverrideNativeName = "TreeDamage"))
		float TreeDamage = 10.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Mine Damage", Category = "Settings|Attributes", OverrideNativeName = "MineDamage"))
		float MineDamage = 10.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Critical Damage Multiplier", Category = "Settings|Attributes", OverrideNativeName = "CriticalDamageMultiplier"))
		float CriticalDamageMultiplier = 20.0f;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Hit Sound", Category = "Settings|Sounds", OverrideNativeName = "DefaultHitSound"))
		USoundBase* DefaultHitSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Grass Hit Sound", Category = "Settings|Sounds", OverrideNativeName = "GrassHitSound"))
		USoundBase* GrassHitSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Sand Hit Sound", Category = "Settings|Sounds", OverrideNativeName = "SandHitSound"))
		USoundBase* SandHitSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Rock Hit Sound", Category = "Settings|Sounds", OverrideNativeName = "RockHitSound"))
		USoundBase* RockHitSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Wood Hit Sound", Category = "Settings|Sounds", OverrideNativeName = "WoodHitSound"))
		USoundBase* WoodHitSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Flesh Hit Sound", Category = "Settings|Sounds", OverrideNativeName = "FleshHitSound"))
		USoundBase* FleshHitSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Hit Particle", Category = "Settings|Effects", OverrideNativeName = "DefaultHitParticle"))
		UParticleSystem* DefaultHitParticle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Grass Hit Particle", Category = "Settings|Effects", OverrideNativeName = "GrassHitParticle"))
		UParticleSystem* GrassHitParticle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Sand Hit Particle", Category = "Settings|Effects", OverrideNativeName = "SandHitParticle"))
		UParticleSystem* SandHitParticle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Rock Hit Particle", Category = "Settings|Effects", OverrideNativeName = "RockHitParticle"))
		UParticleSystem* RockHitParticle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Wood Hit Particle", Category = "Settings|Effects", OverrideNativeName = "WoodHitParticle"))
		UParticleSystem* WoodHitParticle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Flesh Hit Particle", Category = "Settings|Effects", OverrideNativeName = "FleshHitParticle"))
		UParticleSystem* FleshHitParticle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Hit Decal", Category = "Settings|Effects", OverrideNativeName = "DefaultHitDecal"))
		UMaterialInterface* DefaultHitDecal;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Grass Hit Decal", Category = "Settings|Effects", OverrideNativeName = "GrassHitDecal"))
		UMaterialInterface* GrassHitDecal;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Sand Hit Decal", Category = "Settings|Effects", OverrideNativeName = "SandHitDecal"))
		UMaterialInterface* SandHitDecal;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Rock Hit Decal", Category = "Settings|Effects", OverrideNativeName = "RockHitDecal"))
		UMaterialInterface* RockHitDecal;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Wood Hit Decal", Category = "Settings|Effects", OverrideNativeName = "WoodHitDecal"))
		UMaterialInterface* WoodHitDecal;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Flesh Hit Decal", Category = "Settings|Effects", OverrideNativeName = "FleshHitDecal"))
		UMaterialInterface* FleshHitDecal;


	UPROPERTY(Transient, DuplicateTransient)
		FTimerDynamicDelegate Timer;

	UPROPERTY(Transient, DuplicateTransient)
		FTimerDynamicDelegate BTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings|Attributes")
		float ShootingDispersion = 3.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings|Attributes")
		int32 MaxCount = 12;

};



// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "./Character_BaseNative.h"
#include "../craft/STR_Blueprint.h"

#include "Character_Player.generated.h"

UCLASS()
class EASYSURVIVALRPG_API ACharacter_Player : public ACharacter_BaseNative
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacter_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	//UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "CraftingComponent"))
	//	UCraftingComponent*  CraftingComponent ;
	//UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "FootstepComponent"))
	//	UBP_FootstepComponent*  FootstepComponent ;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "BreathPoint"))
		USceneComponent*  BreathPoint ;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "WeaponMesh"))
		UStaticMeshComponent*  WeaponMesh ;
	//UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "HotbarContainer"))
	//	UHotbarComponent*  HotbarContainer ;
	//UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "EquipmentContainer"))
	//	UEquipmentComponent*  EquipmentContainer ;
	//UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "InventoryContainer"))
	//	UContainerComponent*  InventoryContainer ;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "FeetMesh"))
		USkeletalMeshComponent*  FeetMesh ;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "HandsMesh"))
		USkeletalMeshComponent*  HandsMesh ;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "PantsMesh"))
		USkeletalMeshComponent*  PantsMesh ;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "BodyMesh"))
		USkeletalMeshComponent*  BodyMesh ;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "HeadMesh"))
		USkeletalMeshComponent*  HeadMesh ;
	//UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "FoliageCheckerComponent"))
	//	UFoliageCheckerComponent*  FoliageCheckerComponent ;
	//UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "FollowCamera"))
	//	UCameraComponent*  FollowCamera ;
	//UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "CameraBoom"))
	//	USpringArmComponent*  CameraBoom ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Should Continue Main Interaction", Category = "State|Interactions", OverrideNativeName = "ShouldContinueMainInteraction"))
		bool  ShouldContinueMainInteraction ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Should Sprint", Category = "State|Interactions", OverrideNativeName = "ShouldSprint"))
		bool  ShouldSprint ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Should Pop Up", Category = "State|Interactions", OverrideNativeName = "ShouldPopUp"))
		bool  ShouldPopUp ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Should Dive", Category = "State|Interactions", OverrideNativeName = "ShouldDive"))
		bool  ShouldDive ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Equipment Character ID", Category = "Settings|Customization", OverrideNativeName = "EquipmentCharacterID"))
		FName  EquipmentCharacterID ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Head Mesh", Category = "Settings|Customization", OverrideNativeName = "DefaultHeadMesh"))
		USkeletalMesh*  DefaultHeadMesh ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Body Mesh", Category = "Settings|Customization", OverrideNativeName = "DefaultBodyMesh"))
		USkeletalMesh*  DefaultBodyMesh ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Pants Mesh", Category = "Settings|Customization", OverrideNativeName = "DefaultPantsMesh"))
		USkeletalMesh*  DefaultPantsMesh ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Hands Mesh", Category = "Settings|Customization", OverrideNativeName = "DefaultHandsMesh"))
		USkeletalMesh*  DefaultHandsMesh ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Feet Mesh", Category = "Settings|Customization", OverrideNativeName = "DefaultFeetMesh"))
		USkeletalMesh*  DefaultFeetMesh ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Stance", Category = "State|Interactions", OverrideNativeName = "Stance"))
	//	E_Stance   Stance ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Target Character Rotation", Category = "State|Rotation", OverrideNativeName = "TargetCharacterRotation"))
		FRotator  TargetCharacterRotation ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Character Rotation", Category = "State|Rotation", OverrideNativeName = "CharacterRotation"))
		FRotator  CharacterRotation ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Sword First Attack Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "SwordFirstAttackAnim"))
	//	FSTR_AnimMontagePlayData  SwordFirstAttackAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Spear First Attack Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "SpearFirstAttackAnim"))
	//	FSTR_AnimMontagePlayData  SpearFirstAttackAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Common Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "CommonJumpAnim"))
	//	FSTR_AnimMontagePlayData  CommonJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Sword Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "SwordJumpAnim"))
	//	FSTR_AnimMontagePlayData  SwordJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Shovel Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "ShovelJumpAnim"))
	//	FSTR_AnimMontagePlayData  ShovelJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Scroll Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "ScrollJumpAnim"))
	//	FSTR_AnimMontagePlayData  ScrollJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Stone Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "StoneJumpAnim"))
	//	FSTR_AnimMontagePlayData  StoneJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Hatchet Anim", Category = "Settings|Anims|Tools", OverrideNativeName = "HatchetAnim"))
	//	FSTR_AnimMontagePlayData  HatchetAnim ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Player Control Rotation", Category = "State|Rotation", OverrideNativeName = "PlayerControlRotation"))
		FRotator  PlayerControlRotation ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Oxygen", Category = "State|Oxygen", OverrideNativeName = "Oxygen"))
		float  Oxygen ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Max Oxygen", Category = "State|Oxygen", OverrideNativeName = "MaxOxygen"))
		float  MaxOxygen ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Oxygen Regeneration", Category = "State|Oxygen", OverrideNativeName = "OxygenRegeneration"))
		float  OxygenRegeneration ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Consume Oxygen", Category = "State|Oxygen", OverrideNativeName = "ConsumeOxygen"))
		bool  ConsumeOxygen ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Oxygen Consumption", Category = "State|Oxygen", OverrideNativeName = "OxygenConsumption"))
		float  OxygenConsumption ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Hair Color", Category = "Settings|Customization", OverrideNativeName = "DefaultHairColor"))
		FLinearColor  DefaultHairColor ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Pants Color", Category = "Settings|Customization", OverrideNativeName = "DefaultPantsColor"))
		FLinearColor  DefaultPantsColor ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Skin Color", Category = "Settings|Customization", OverrideNativeName = "DefaultSkinColor"))
		FLinearColor  DefaultSkinColor ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Customized Hair Colors", Category = "Settings|Customization", OverrideNativeName = "CustomizedHairColors"))
		TArray<FLinearColor>  CustomizedHairColors ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Customized Pants Colors", Category = "Settings|Customization", OverrideNativeName = "CustomizedPantsColors"))
		TArray<FLinearColor>  CustomizedPantsColors ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Customized Skin Colors", Category = "Settings|Customization", OverrideNativeName = "CustomizedSkinColors"))
		TArray<FLinearColor>  CustomizedSkinColors ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Dynamic Head Material", Category = "State|Customization", OverrideNativeName = "DynamicHeadMaterial"))
		UMaterialInstanceDynamic*  DynamicHeadMaterial ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Dynamic Body Material", Category = "State|Customization", OverrideNativeName = "DynamicBodyMaterial"))
		UMaterialInstanceDynamic*  DynamicBodyMaterial ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Dynamic Pants Material", Category = "State|Customization", OverrideNativeName = "DynamicPantsMaterial"))
		UMaterialInstanceDynamic*  DynamicPantsMaterial ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Dynamic Hands Material", Category = "State|Customization", OverrideNativeName = "DynamicHandsMaterial"))
		UMaterialInstanceDynamic*  DynamicHandsMaterial ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Dynamic Feet Material", Category = "State|Customization", OverrideNativeName = "DynamicFeetMaterial"))
		UMaterialInstanceDynamic*  DynamicFeetMaterial ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Customized Head Meshes", Category = "Settings|Customization", OverrideNativeName = "CustomizedHeadMeshes"))
		TArray<USkeletalMesh*>  CustomizedHeadMeshes ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Customized Pants Meshes", Category = "Settings|Customization", OverrideNativeName = "CustomizedPantsMeshes"))
		TArray<USkeletalMesh*>  CustomizedPantsMeshes ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Source Material", Category = "State|Customization", OverrideNativeName = "SourceMaterial"))
		UMaterialInterface*  SourceMaterial ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Equipment Stance", Category = "State|Interactions", OverrideNativeName = "EquipmentStance"))
	//	E_Stance   EquipmentStance ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Is Sprinting", Category = "State|Interactions", OverrideNativeName = "IsSprinting"))
		bool  IsSprinting ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Common Hit Reaction Anim", Category = "Settings|Anims|Damage Hit Reactions", OverrideNativeName = "CommonHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  CommonHitReactionAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Hatchet Miss Anim", Category = "Settings|Anims|Tools", OverrideNativeName = "HatchetMissAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  HatchetMissAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Pickaxe Miss Anim", Category = "Settings|Anims|Tools", OverrideNativeName = "PickaxeMissAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PickaxeMissAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Pickaxe Hit Anim", Category = "Settings|Anims|Tools", OverrideNativeName = "PickaxeHitAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PickaxeHitAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Death Anim", Category = "Settings|Anims|Death", OverrideNativeName = "DeathAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  DeathAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Death Under Water Anim", Category = "Settings|Anims|Death", OverrideNativeName = "DeathUnderWaterAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  DeathUnderWaterAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Spear Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "SpearJumpAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  SpearJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Two Handed Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "TwoHandedJumpAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  TwoHandedJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Polearm Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "PolearmJumpAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PolearmJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Pistol Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "PistolJumpAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PistolJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Blunderbuss Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "BlunderbussJumpAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  BlunderbussJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Rifle Jump Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "RifleJumpAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  RifleJumpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Landing Anim", Category = "Settings|Anims|Jump", OverrideNativeName = "LandingAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  LandingAnim ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Hunger", Category = "State|Hunger", OverrideNativeName = "Hunger"))
		float  Hunger ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Max Hunger", Category = "State|Hunger", OverrideNativeName = "MaxHunger"))
		float  MaxHunger ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Hunger Consumption", Category = "State|Hunger", OverrideNativeName = "HungerConsumption"))
		float  HungerConsumption ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Thirst", Category = "State|Thirst", OverrideNativeName = "Thirst"))
		float  Thirst ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Max Thirst", Category = "State|Thirst", OverrideNativeName = "MaxThirst"))
		float  MaxThirst ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Thirst Consumption", Category = "State|Thirst", OverrideNativeName = "ThirstConsumption"))
		float  ThirstConsumption ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Weight", Category = "State|Interactions", OverrideNativeName = "Weight"))
		float  Weight ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Max Weight", Category = "State|Interactions", OverrideNativeName = "MaxWeight"))
		float  MaxWeight ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Sprint Speed", Category = "Settings|Interactions", OverrideNativeName = "SprintSpeed"))
		float  SprintSpeed ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Is Overloaded", Category = "State|Interactions", OverrideNativeName = "IsOverloaded"))
		bool  IsOverloaded ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Eat Anim", Category = "Settings|Anims|Use", OverrideNativeName = "EatAnim"))
	//	FSTR_AnimMontagePlayData  EatAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Interaction Item Container", Category = "State|Interactions", OverrideNativeName = "InteractionItemContainer"))
	//	UBP_ContainerComponent*  InteractionItemContainer ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Interaction Item Slot", Category = "State|Interactions", OverrideNativeName = "InteractionItemSlot"))
		int32  InteractionItemSlot ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Drink Anim", Category = "Settings|Anims|Use", OverrideNativeName = "DrinkAnim"))
	//	FSTR_AnimMontagePlayData  DrinkAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Shovel Anim", Category = "Settings|Anims|Tools", OverrideNativeName = "ShovelAnim"))
	//	FSTR_AnimMontagePlayData ShovelAnim ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Target Hotbar Slot", Category = "State|Interactions", OverrideNativeName = "TargetHotbarSlot"))
		int32  TargetHotbarSlot ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Shovel Miss Anim", Category = "Settings|Anims|Tools", OverrideNativeName = "ShovelMissAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  ShovelMissAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Mallet Anim", Category = "Settings|Anims|Tools", OverrideNativeName = "MalletAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  MalletAnim ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Dig Actor", Category = "State|Interactions", OverrideNativeName = "DigActor"))
		AActor*  DigActor ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Dig Surface", Category = "State|Interactions", OverrideNativeName = "DigSurface"))
		TEnumAsByte<EPhysicalSurface>  DigSurface ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Dig Location", Category = "State|Interactions", OverrideNativeName = "DigLocation"))
		FVector  DigLocation ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Base Energy Restoration", Category = "Settings|Interactions", OverrideNativeName = "BaseEnergyRestoration"))
		float  BaseEnergyRestoration ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Jump Energy Consumption", Category = "Settings|Interactions", OverrideNativeName = "JumpEnergyConsumption"))
		float  JumpEnergyConsumption ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Attack Energy Consumption", Category = "Settings|Interactions", OverrideNativeName = "AttackEnergyConsumption"))
		float  AttackEnergyConsumption ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Tool Interaction Energy Consumption", Category = "Settings|Interactions", OverrideNativeName = "ToolInteractionEnergyConsumption"))
		float  ToolInteractionEnergyConsumption ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Is Tired", Category = "State|Interactions", OverrideNativeName = "IsTired"))
		bool  IsTired ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Stone Miss Anim", Category = "Settings|Anims|Tools", OverrideNativeName = "StoneMissAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  StoneMissAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Stone Anim", Category = "Settings|Anims|Tools", OverrideNativeName = "StoneAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  StoneAnim ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Sprint Energy Consumption", Category = "Settings|Interactions", OverrideNativeName = "SprintEnergyConsumption"))
		float  SprintEnergyConsumption ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Impact Sound", Category = "Settings|Interactions", OverrideNativeName = "DefaultImpactSound"))
		USoundBase*  DefaultImpactSound ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Spear Hit Reaction Anim", Category = "Settings|Anims|Damage Hit Reactions", OverrideNativeName = "SpearHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  SpearHitReactionAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Two Handed Hit Reaction Anim", Category = "Settings|Anims|Damage Hit Reactions", OverrideNativeName = "TwoHandedHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  TwoHandedHitReactionAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Polearm Hit Reaction Anim", Category = "Settings|Anims|Damage Hit Reactions", OverrideNativeName = "PolearmHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PolearmHitReactionAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Pistol Hit Reaction Anim", Category = "Settings|Anims|Damage Hit Reactions", OverrideNativeName = "PistolHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PistolHitReactionAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Sword Block Hit Reaction Anim", Category = "Settings|Anims|Block Hit Reactions", OverrideNativeName = "SwordBlockHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  SwordBlockHitReactionAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Scroll Anim", Category = "Settings|Anims|Use", OverrideNativeName = "ScrollAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  ScrollAnim ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Player Name", Category = "State|Interactions", OverrideNativeName = "PlayerName"))
		FString  PlayerName ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,   meta = (DisplayName = "Is Sleep", Category = "State|Interactions", OverrideNativeName = "IsSleep"))
		bool  IsSleep ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Go to Sleep Anim", Category = "Settings|Anims|Sleep", OverrideNativeName = "GoToSleepAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  GoToSleepAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Wake Up Anim", Category = "Settings|Anims|Sleep", OverrideNativeName = "WakeUpAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  WakeUpAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Spear Block Hit Reaction Anim", Category = "Settings|Anims|Block Hit Reactions", OverrideNativeName = "SpearBlockHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  SpearBlockHitReactionAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Two Handed Block Hit Reaction Anim", Category = "Settings|Anims|Block Hit Reactions", OverrideNativeName = "TwoHandedBlockHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  TwoHandedBlockHitReactionAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Two Hand First Attack Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "TwoHandFirstAttackAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  TwoHandFirstAttackAnim ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Select Hotbar Timer Handle", Category = "State|Interactions", OverrideNativeName = "SelectHotbarTimerHandle"))
		FTimerHandle  SelectHotbarTimerHandle ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Equiped Head Mesh", Category = "State|Customization", OverrideNativeName = "EquipedHeadMesh"))
		USkeletalMesh*  EquipedHeadMesh ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,  meta = (DisplayName = "Equiped Body Mesh", Category = "State|Customization", OverrideNativeName = "EquipedBodyMesh"))
		USkeletalMesh*  EquipedBodyMesh ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,  meta = (DisplayName = "Equiped Pants Mesh", Category = "State|Customization", OverrideNativeName = "EquipedPantsMesh"))
		USkeletalMesh*  EquipedPantsMesh ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,  meta = (DisplayName = "Equiped Hands Mesh", Category = "State|Customization", OverrideNativeName = "EquipedHandsMesh"))
		USkeletalMesh*  EquipedHandsMesh ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,  meta = (DisplayName = "Equiped Feet Mesh", Category = "State|Customization", OverrideNativeName = "EquipedFeetMesh"))
		USkeletalMesh*  EquipedFeetMesh ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Equiped Weapon Mesh", Category = "State|Customization", OverrideNativeName = "EquipedWeaponMesh"))
		UStaticMesh*  EquipedWeaponMesh ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Dialogue Anim", Category = "Settings|Anims|Dialogue", OverrideNativeName = "DialogueAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  DialogueAnim ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite , meta = (DisplayName = "Hair Type Index", Category = "State|Customization", OverrideNativeName = "HairTypeIndex"))
		int32  HairTypeIndex ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite , meta = (DisplayName = "Hair Color Index", Category = "State|Customization", OverrideNativeName = "HairColorIndex"))
		int32  HairColorIndex ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Pants Color Index", Category = "State|Customization", OverrideNativeName = "PantsColorIndex"))
		int32  PantsColorIndex ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Skin Color Index", Category = "State|Customization", OverrideNativeName = "SkinColorIndex"))
		int32  SkinColorIndex ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Should Update Character Rotation", Category = "State|Interactions", OverrideNativeName = "ShouldUpdateCharacterRotation"))
		bool  ShouldUpdateCharacterRotation ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Polearm First Attack Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "PolearmFirstAttackAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PolearmFirstAttackAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Pistol Shoot Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "PistolShootAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PistolShootAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Pistol Shoot Aim Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "PistolShootAimAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PistolShootAimAnim ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Camera Offset", Category = "Settings|Camera", OverrideNativeName = "DefaultCameraOffset"))
		FVector  DefaultCameraOffset ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Camera Length", Category = "Settings|Camera", OverrideNativeName = "DefaultCameraLength"))
		float  DefaultCameraLength ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Camera Lag", Category = "Settings|Camera", OverrideNativeName = "DefaultCameraLag"))
		float  DefaultCameraLag ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Aiming Camera Offsets", Category = "Settings|Camera", OverrideNativeName = "AimingCameraOffsets"))
	//	TMap<E__E_Stance , FVector>  AimingCameraOffsets ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Aiming Camera Length", Category = "Settings|Camera", OverrideNativeName = "AimingCameraLength"))
	//	TMap<E__E_Stance , float>  AimingCameraLength ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Aiming Camera Lag", Category = "Settings|Camera", OverrideNativeName = "AimingCameraLag"))
	//	TMap<E__E_Stance , float>  AimingCameraLag ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Target Camera Offset", Category = "State|Camera", OverrideNativeName = "TargetCameraOffset"))
		FVector  TargetCameraOffset ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Target Camera Length", Category = "State|Camera", OverrideNativeName = "TargetCameraLength"))
		float  TargetCameraLength ;
/*	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Pistol Reload Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "PistolReloadAnim"))
		FSTR_AnimMontagePlayData 1411893518  PistolReloadAnim ;*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Can Continue Shooting", Category = "State|Interactions", OverrideNativeName = "CanContinueShooting"))
		bool  CanContinueShooting ;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Block Continue Shooting", Category = "State|Interactions", OverrideNativeName = "BlockContinueShooting"))
		bool  BlockContinueShooting ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Pistol Reload Aim Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "PistolReloadAimAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PistolReloadAimAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Blunderbuss Shoot Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "BlunderbussShootAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  BlunderbussShootAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Blunderbuss Shoot Aim Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "BlunderbussShootAimAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  BlunderbussShootAimAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Blunderbuss Reload Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "BlunderbussReloadAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  BlunderbussReloadAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Blunderbuss Reload Aim Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "BlunderbussReloadAimAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  BlunderbussReloadAimAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Rifle Shoot Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "RifleShootAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  RifleShootAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Rifle Shoot Aim Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "RifleShootAimAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  RifleShootAimAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Rifle Reload Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "RifleReloadAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  RifleReloadAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Rifle Reload Aim Anim", Category = "Settings|Anims|Weapon", OverrideNativeName = "RifleReloadAimAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  RifleReloadAimAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Blunderbuss Hit Reaction Anim", Category = "Settings|Anims|Damage Hit Reactions", OverrideNativeName = "BlunderbussHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  BlunderbussHitReactionAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Rifle Hit Reaction Anim", Category = "Settings|Anims|Damage Hit Reactions", OverrideNativeName = "RifleHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  RifleHitReactionAnim ;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Polearm Block Hit Reaction Anim", Category = "Settings|Anims|Block Hit Reactions", OverrideNativeName = "PolearmBlockHitReactionAnim"))
	//	FSTR_AnimMontagePlayData 1411893518  PolearmBlockHitReactionAnim ;
public:
	// Event when crafting completed.
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Player", OverrideNativeName = "CraftingCompleted"))
	void CraftingCompleted(FSTR_Blueprint const& Blueprint, int32 Amount);

	// Check and update sprinting variables.
	UFUNCTION(BlueprintCallable, meta = (Category = "State", Tooltip = "", OverrideNativeName = "CheckSprint"))
	virtual void CheckSprint();

	// Update character rotation to control rotation
	UFUNCTION(BlueprintCallable, meta = (Category = "State", OverrideNativeName = "UpdateCharacterRotation"))
	virtual void UpdateCharacterRotation();

	// Check energy and set tired variable if energy is low
	UFUNCTION(BlueprintCallable, meta = (Category = "State", OverrideNativeName = "CheckEnergy"))
	virtual void CheckEnergy();
/*
	virtual void UpdateWalkSpeed( bool& Success);
	
	//Check and update swimming variables
	UFUNCTION(BlueprintCallable, meta = (Category = "State", OverrideNativeName = "CheckSwimming"))
	virtual void CheckSwimming();
*/
};

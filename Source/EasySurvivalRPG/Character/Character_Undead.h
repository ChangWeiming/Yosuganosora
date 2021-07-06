// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character/Character_BaseNative.h"

#include "Blueprint/BlueprintSupport.h"
#include "Runtime/CoreUObject/Public/UObject/NoExportTypes.h"

//#include "STR_AnimMontagePlayData.h"

#include "Item/STR_ItemData.h"
#include "Item/STR_Item.h"

//#include "E_Stance.h"

#include "Runtime/Engine/Classes/Engine/EngineTypes.h"

//#include "STR_DialogueReply.h"

#include "Runtime/Engine/Classes/Sound/DialogueTypes.h"

class UStaticMeshComponent;
class USkeletalMeshComponent;
class UBP_FootstepComponent_C;
class UBP_FoliageCheckerComponent_C;
class USoundBase;
class USkeletalMesh;
class UMaterialInstance;
class ABP_Mark_C;
class UStaticMesh;
class UDamageType;
class AController;
class UClass;
class APlayerController;

#include "Character_Undead.generated.h"


UCLASS()
class EASYSURVIVALRPG_API ACharacter_Undead : public ACharacter_BaseNative
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "默认", OverrideNativeName = "WeaponMesh"))
	    UStaticMeshComponent* WeaponMesh;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "默认", OverrideNativeName = "BodyMesh"))
		USkeletalMeshComponent* BodyMesh;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "默认", OverrideNativeName = "HandsMesh"))
		USkeletalMeshComponent* HandsMesh;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "默认", OverrideNativeName = "PantsMesh"))
		USkeletalMeshComponent* PantsMesh;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "默认", OverrideNativeName = "HeadMesh"))
		USkeletalMeshComponent* HeadMesh;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "默认", OverrideNativeName = "FootstepComponent"))
		UBP_FootstepComponent_C* FootstepComponent;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "默认", OverrideNativeName = "FoliageCheckerComponent"))
		UBP_FoliageCheckerComponent_C* FoliageCheckerComponent;

	//
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Hit Reaction Anim", Category = "Settings|Anims", OverrideNativeName = "HitReactionAnim"))
	//	TArray<FSTR_AnimMontagePlayData> HitReactionAnim;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Block Hit Reaction Anim", Category = "Settings|Anims", OverrideNativeName = "BlockHitReactionAnim"))
	//	FSTR_AnimMontagePlayData BlockHitReactionAnim;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Attack Anims", Category = "Settings|Anims", OverrideNativeName = "AttackAnims"))
	//	TArray<FSTR_AnimMontagePlayData> AttackAnims;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Default Impact Sound", Category = "Settings|Sounds", OverrideNativeName = "DefaultImpactSound"))
		USoundBase* DefaultImpactSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Weapon Item Data", Category = "State|Interactions", OverrideNativeName = "WeaponItemData"))
		FSTR_ItemData WeaponItemData;

	//武器相关
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Should Randomize Weapon", Category = "Settings|Weapon", OverrideNativeName = "ShouldRandomizeWeapon"))
		bool ShouldRandomizeWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, meta = (DisplayName = "Weapon Index", Category = "Settings|Weapon", OverrideNativeName = "WeaponIndex"))
		int32 WeaponIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Weapon Items", Category = "Settings|Weapon", OverrideNativeName = "WeaponItems"))
		TArray<FSTR_Item> WeaponItems;

	//
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Taunt Anim", Category = "Settings|Anims", OverrideNativeName = "TauntAnim"))
	//	FSTR_AnimMontagePlayData TauntAnim;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "AFKAnim", Category = "Settings|Anims", OverrideNativeName = "AFKAnim"))
	//	FSTR_AnimMontagePlayData AFKAnim;

	//着装相关
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Should Randomize Meshes", Category = "Settings|Customization", OverrideNativeName = "ShouldRandomizeMeshes"))
		bool ShouldRandomizeMeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, meta = (DisplayName = "Body Mesh Index", Category = "Settings|Customization", OverrideNativeName = "BodyMeshIndex"))
		int32 BodyMeshIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, meta = (DisplayName = "Head Mesh Index", Category = "Settings|Customization", OverrideNativeName = "HeadMeshIndex"))
		int32 HeadMeshIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, meta = (DisplayName = "Pants Mesh Index", Category = "Settings|Customization", OverrideNativeName = "PantsMeshIndex"))
		int32 PantsMeshIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, meta = (DisplayName = "Hands Mesh Index", Category = "Settings|Customization", OverrideNativeName = "HandsMeshIndex"))
		int32 HandsMeshIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, meta = (DisplayName = "Material Index", Category = "Settings|Customization", OverrideNativeName = "MaterialIndex"))
		int32 MaterialIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Body Meshes", Category = "Settings|Customization", OverrideNativeName = "BodyMeshes"))
		TArray<USkeletalMesh*> BodyMeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Head Meshes", Category = "Settings|Customization", OverrideNativeName = "HeadMeshes"))
		TArray<USkeletalMesh*> HeadMeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Pants Meshes", Category = "Settings|Customization", OverrideNativeName = "PantsMeshes"))
		TArray<USkeletalMesh*> PantsMeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Hands Meshes", Category = "Settings|Customization", OverrideNativeName = "HandsMeshes"))
		TArray<USkeletalMesh*> HandsMeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Mesh Materials", Category = "Settings|Customization", OverrideNativeName = "MeshMaterials"))
		TArray<UMaterialInstance*> MeshMaterials;

	//
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Mark", Category = "State|Other", OverrideNativeName = "Mark"))
		ABP_Mark_C* Mark;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing = "OnRep_BodySkeletalMesh", meta = (DisplayName = "Body Skeletal Mesh", Category = "Settings|Customization", OverrideNativeName = "BodySkeletalMesh"))
		USkeletalMesh* BodySkeletalMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing = "OnRep_HeadSkeletalMesh", meta = (DisplayName = "Head Skeletal Mesh", Category = "Settings|Customization", OverrideNativeName = "HeadSkeletalMesh"))
		USkeletalMesh* HeadSkeletalMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing = "OnRep_PantsSkeletalMesh", meta = (DisplayName = "Pants Skeletal Mesh", Category = "Settings|Customization", OverrideNativeName = "PantsSkeletalMesh"))
		USkeletalMesh* PantsSkeletalMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing = "OnRep_HandsSkeletalMesh", meta = (DisplayName = "Hands Skeletal Mesh", Category = "Settings|Customization", OverrideNativeName = "HandsSkeletalMesh"))
		USkeletalMesh* HandsSkeletalMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing = "OnRep_SkeletalMeshMaterial", meta = (DisplayName = "Skeletal Mesh Material", Category = "Settings|Customization", OverrideNativeName = "SkeletalMeshMaterial"))
		UMaterialInstance* SkeletalMeshMaterial;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing = "OnRep_WeaponStaticMesh", meta = (DisplayName = "Weapon Static Mesh", Category = "Settings|Customization", OverrideNativeName = "WeaponStaticMesh"))
		UStaticMesh* WeaponStaticMesh;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, meta = (DisplayName = "Stance", Category = "State|Interactions", OverrideNativeName = "Stance"))
	//	E_Stance Stance;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, meta = (DisplayName = "Equipment Stance", Category = "State|Interactions", OverrideNativeName = "EquipmentStance"))
	//	E_Stance EquipmentStance;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Dialogue Anim", Category = "Settings|Anims", OverrideNativeName = "DialogueAnim"))
	//	FSTR_AnimMontagePlayData DialogueAnim;

	UPROPERTY(Transient, DuplicateTransient, meta = (OverrideNativeName = "K2Node_CustomEvent_TraceStart"))
		FVector K2Node_CustomEvent_TraceStart;
	UPROPERTY(Transient, DuplicateTransient, meta = (OverrideNativeName = "K2Node_CustomEvent_TraceEnd"))
		FVector K2Node_CustomEvent_TraceEnd;
	UPROPERTY(Transient, DuplicateTransient, meta = (OverrideNativeName = "K2Node_Event_SoundName"))
		FName K2Node_Event_SoundName;
	UPROPERTY(Transient, DuplicateTransient, meta = (OverrideNativeName = "K2Node_CustomEvent_SoundName"))
		FName K2Node_CustomEvent_SoundName;

	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	void ExecuteUbergraph_BP_Character_Undead_0(int32 EntryPoint);
	void ExecuteUbergraph_BP_Character_Undead_1(int32 EntryPoint);
	void ExecuteUbergraph_BP_Character_Undead_2(int32 EntryPoint);
	void ExecuteUbergraph_BP_Character_Undead_3(int32 EntryPoint);
	void ExecuteUbergraph_BP_Character_Undead_4(int32 EntryPoint);
//	virtual void TraceDealDamage_BPI() override;

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, meta = (Category, OverrideNativeName = "DeleteMark (Multicast)"))
		virtual void DeleteMarkxxMulticastx();
	UFUNCTION(Server, Reliable, BlueprintCallable, meta = (Category, OverrideNativeName = "PlayItemSound (Server)"))
		virtual void PlayItemSoundxxServerx(FName SoundName);
//	virtual void PlayItemSound_BPI(FName SoundName) override;

	UFUNCTION(Server, Reliable, BlueprintCallable, meta = (Category, OverrideNativeName = "TraceDealDamage (Server)"))
		virtual void TraceDealDamagexxServerx(FVector TraceStart, FVector TraceEnd);
//	virtual void UserConstructionScript() override;

	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Combat", Tooltip = "Try to deal melee damage on the server.", OverrideNativeName = "TraceDealDamage_Server"))
		virtual void TraceDealDamage_Server(const FVector Start__const, const FVector End__const);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Interactions|Combat", Tooltip = "Get base damage and damage type.", OverrideNativeName = "GetBaseDamage"))
		virtual void GetBaseDamage(/*out*/ float& Damage, /*out*/ UClass*& DamageType);
	UFUNCTION(BlueprintCallable, meta = (Category = "Settings", Tooltip = "Randomize undead\'s weapon item.", CallInEditor = "true", OverrideNativeName = "RandomizeWeapon"))
		virtual void RandomizeWeapon();
	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base", Tooltip = "Drop death loot and hide undead\'s weapon.", OverrideNativeName = "DropDeathLoot"))
		virtual void DropDeathLoot();
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Interactions|Combat", Tooltip = "Returns impact sound depending on the surface type.", OverrideNativeName = "GetImpactSound"))
		virtual void GetImpactSound(EPhysicalSurface SurfaceType, /*out*/ USoundBase*& Sound);

	UFUNCTION(BlueprintCallable, meta = (Category = "State", Tooltip = "Update skeletal meshes and materials.", OverrideNativeName = "UpdateMeshes"))
		virtual void UpdateMeshes();
	UFUNCTION(BlueprintCallable, meta = (Category = "Settings", Tooltip = "Randomize undead\'s customization.", CallInEditor = "true", OverrideNativeName = "RandomizeMeshes"))
		virtual void RandomizeMeshes();
	UFUNCTION(BlueprintCallable, meta = (Category = "State", Tooltip = "Update weapon item data and weapon mesh.", OverrideNativeName = "UpdateWeapon"))
		virtual void UpdateWeapon();
	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base", Tooltip = "Make loot in the loot container.", OverrideNativeName = "MakeDeathLoot"))
		virtual void MakeDeathLoot();

	UFUNCTION(BlueprintCallable, meta = (Category = "State", Tooltip = "Create undead\'s mark.", OverrideNativeName = "CreateMark"))
		virtual void CreateMark();
//	virtual void InitCharacter(/*out*/ bool& Success) override;
//	virtual void UpdateTick(float DeltaSeconds, /*out*/ bool& Success) override;
//	virtual void Death(AController* KillerController, /*out*/ bool& Success) override;
//	virtual void DamageTaken(float Damage, const UDamageType* DamageType__const, AController* InstigatedBy, FHitResult HitInfo, /*out*/ bool& Success) override;
//	virtual void HitBlocked(float Damage, const UDamageType* DamageType__const, AController* InstigatedBy, FHitResult HitInfo, /*out*/ bool& Success) override;
//	virtual void TryAttack(/*out*/ bool& Success) override;

	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base", Tooltip = "Play weapon item sound.", OverrideNativeName = "PlayItemSound_Server"))
		virtual void PlayItemSound_Server(FName SoundName);
	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Combat", Tooltip = "Trace deal melee damage.", OverrideNativeName = "TraceDealDamage"))
		virtual void TraceDealDamage();
//	virtual void TryTaunt(/*out*/ bool& Success) override;
//	virtual void TryAFK(/*out*/ bool& Success) override;
	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base", Tooltip = "Play item sound.", OverrideNativeName = "PlaySound"))
		virtual void PlaySound(FName SoundName);
	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base", Tooltip = "Delete undead\'s mark.", OverrideNativeName = "DeleteMark"))
		virtual void DeleteMark();

	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnRep_BodySkeletalMesh"))
		virtual void OnRep_BodySkeletalMesh();
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnRep_HeadSkeletalMesh"))
		virtual void OnRep_HeadSkeletalMesh();
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnRep_PantsSkeletalMesh"))
		virtual void OnRep_PantsSkeletalMesh();
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnRep_HandsSkeletalMesh"))
		virtual void OnRep_HandsSkeletalMesh();
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnRep_SkeletalMeshMaterial"))
		virtual void OnRep_SkeletalMeshMaterial();
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "OnRep_WeaponStaticMesh"))
		virtual void OnRep_WeaponStaticMesh();

	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base", OverrideNativeName = "UpdateStance"))
		virtual void UpdateStance();
//	virtual void StartDialogue(APlayerController* PlayerController, /*out*/ bool& Success) override;
//	virtual void FinishDialogue(APlayerController* PlayerController, /*out*/ bool& Success) override;
//	virtual void UpdateTalkingState(/*out*/ bool& Success) override;
	//virtual void PlayDialogueReply(FSTR_DialogueReply DialogueReply, FDialogueContext DialogueContext, /*out*/ bool& Success) override;
	UFUNCTION(BlueprintCallable, meta = (Category = "Settings", Tooltip = "Disable randomizing for meshs and weapon.", CallInEditor = "true", OverrideNativeName = "DisableRandomizing"))
		virtual void DisableRandomizing();
	UFUNCTION(BlueprintCallable, meta = (Category, OverrideNativeName = "Be Blocked"))
		virtual void BeBlocked();

public:
	// Sets default values for this character's properties
	ACharacter_Undead(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

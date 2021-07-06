// Easy Systems

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"
#include "Components/AudioComponent.h"
#include "NavigationInvokerComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Sound/DialogueVoice.h"
#include "Engine/DataTable.h"

#include "Character_BaseNative.generated.h"

//UDELEGATE(meta = (OverrideNativeName = "OnDeath__DelegateSignature"))
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeath, ACharacter*, Character, AController*, KillerInstigator);



UCLASS()
class EASYSURVIVALRPG_API ACharacter_BaseNative : public ACharacter
{

	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacter_BaseNative();

protected:
	// Called when the game starts or when spawned
	  void BeginPlay() override;

public:	
	// Called every frame
	  void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	  void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "Audio"))
		UAudioComponent* Audio;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "NavigationInvoker"))
		UNavigationInvokerComponent* NavigationInvoker;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "StateWidget"))
		UWidgetComponent* StateWidget;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "WaterSplashCollision"))
		USphereComponent* WaterSplashCollision;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "AIPerception"))
		UAIPerceptionComponent* AIPerception;
//	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Default", OverrideNativeName = "AttributesComponent"))
//		UAttributesComponent* AttributesComponent;

	//角色状态血量相关变量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Health")
		float Health = 10.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Health")
		float MaxHealth = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Health")
		float HealthRegeneration = 0.0;
	//角色状态体力相关变量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Energy")
		float Energy = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Energy")
		float MaxEnergy = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Energy")
		float EnergyRegeneration = 0.0;

	//角色状态交互相关
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool IsAlive = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool IsAttacking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool TryContinueAttack = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool CanAttack = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool UpperBody = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool IsBlocking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool ShouldBlocking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool IsAiming = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool shouldAiming = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool IsBlockRotation = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool IsUsingItem = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool IsTalking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		FVector StartFallingLocation = FVector(0.0, 0.0, 0.0);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		FDateTime StartFallingTime = FDateTime(1, 1, 1, 8, 0, 0, 800);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool ShouldRun = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		bool ShouldOverrideWalkSpeed = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		float OverrideWalkSpeed = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		float OverrideWalkInterpSpeed = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		float TargetSpeed = 0.0;

	//AI
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "State|AI"))
		FVector GuardLocation = FVector(0.0, 0.0, 0.0);
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "State|AI"))
		bool IsScared = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "State|AI"))
		AActor* ThreatActor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "State|AI"))
		AActor* TargetActor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "State|AI"))
		TArray<AActor*> AggressiveActors;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = ( Category = "State|AI"))
	//	FSTR_Relationships Relationships;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Is Enabled AI", Category = "State|AI", OverrideNativeName = "IsEnabledAI"))
		bool IsEnabledAI = true;


	//UPROPERTY(EditInstanceOnly, BlueprintReadWrite,   meta = (DisplayName = "Patrol Point", Category = "Settings|AI", OverrideNativeName = "PatrolPoint"))
	//	APatrolPoint* PatrolPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,   meta = (DisplayName = "Is Aggressive", Category = "Settings|AI", OverrideNativeName = "IsAggressive"))
		bool IsAggressive = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Can be Scared", Category = "Settings|AI", OverrideNativeName = "CanBeScared"))
		bool CanBeScared = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,   meta = (DisplayName = "Aggression Distance", Category = "Settings|AI", OverrideNativeName = "AggressionDistance"))
		float AggressionDistance = 1000.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,   meta = (DisplayName = "Threat Distance", Category = "Settings|AI", OverrideNativeName = "ThreatDistance"))
		float ThreatDistance = 300.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Chasing Distance", Category = "Settings|AI", OverrideNativeName = "ChasingDistance"))
		float ChasingDistance = 2000.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Dialogue Handle", Category = "Settings|AI", OverrideNativeName = "DialogueHandle"))
		FDataTableRowHandle DialogueHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Dialogue Voice", Category = "Settings|AI", OverrideNativeName = "DialogueVoice"))
		UDialogueVoice* DialogueVoice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Relationships Handle", Category = "Settings|AI", OverrideNativeName = "RelationshipsHandle"))
		FDataTableRowHandle RelationshipsHandle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Character Name", Category = "Settings|Base", OverrideNativeName = "CharacterName"))
		FText CharacterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Character Icon", Category = "Settings|Base", OverrideNativeName = "CharacterIcon"))
		FSlateBrush CharacterIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Show Character State", Category = "Settings|Base", OverrideNativeName = "ShowCharacterState"))
		bool ShowCharacterState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Show Only Name", Category = "Settings|Base", OverrideNativeName = "ShowOnlyName"))
		bool ShowOnlyName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Experience for Killing", Category = "Settings|Base", OverrideNativeName = "ExperienceForKilling"))
		float ExperienceForKilling;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Walk Speed", Category = "Settings|Base", OverrideNativeName = "WalkSpeed"))
		float WalkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Run Speed", Category = "Settings|Base", OverrideNativeName = "RunSpeed"))
		float RunSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Loot Handle", Category = "Settings|Base", OverrideNativeName = "LootHandle"))
		FDataTableRowHandle LootHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Ragdoll Bone", Category = "Settings|Base", OverrideNativeName = "RagdollBone"))
		FName RagdollBone;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Fraction", Category = "Settings|Base", OverrideNativeName = "Fraction"))
	//	E_Fraction Fraction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Destroy Character Timer", Category = "Settings|Base", OverrideNativeName = "DestroyCharacterTimer"))
		float DestroyCharacterTimer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Is Dashing", Category = "Interactions|Base", MultiLine = "true", OverrideNativeName = "isDashing"))
		bool isDashing;


	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "StopDialogueSound_BPI"))
		  void StopDialogueSound_BPI();
	UFUNCTION(  BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "StopDialogueSound (Multicast)"))
		  void StopDialogueSoundxxMulticastx();
	UFUNCTION( BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "PlayDialogueSound (Multicast)"))
		  void PlayDialogueSoundxxMulticastx(USoundBase* Sound);
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "PlayDialogueReply_BPI"))
	//	  void PlayDialogueReply_BPI(FSTR_DialogueReply DialogueReply, FDialogueContext DialogueContext);
	//UFUNCTION(NetMulticast,   BlueprintCallable, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "PlayDialogueAtLocation (Multicast)"))
	//	  void PlayDialogueAtLocationxxMulticastx(UDialogueWave* DialogueWave, FDialogueContext DialogueContext, FVector Location);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "SetCharacterName (Server)"))
		  void SetCharacterNamexxServerx(const FText& CharacterNameTarget);
	UFUNCTION( BlueprintImplementableEvent, BlueprintCallable, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "PlaySoundAtLocation (Multicast)"))
		  void PlaySoundAtLocationxxMulticastx(USoundBase*  Sound , FVector  Location );

	UFUNCTION( BlueprintImplementableEvent, BlueprintCallable, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "EnableCapsuleCollision (Multicast)"))
		  void EnableCapsuleCollisionxxMulticastx(bool Enabled);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "PlayAFKAnimation_BPI"))
		  void PlayAFKAnimation_BPI();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "PlayTauntAnimation_BPI"))
		  void PlayTauntAnimation_BPI();
	//UFUNCTION(NetMulticast,   BlueprintCallable, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "PlayAnimation (Multicast)"))
	//	  void PlayAnimationxxMulticastx(FSTR_AnimMontagePlayData const&  AnimMontage  );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Interaction Object", CppFromBpEvent, OverrideNativeName = "TryTurnOn_BPI"))
		  void TryTurnOn_BPI();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Interaction Object", CppFromBpEvent, OverrideNativeName = "TryTurnOff_BPI"))
		  void TryTurnOff_BPI();
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "ContinueAttack_BPI"))
	//	  void ContinueAttack_BPI(FSTR_AnimMontagePlayData  Anim );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "TraceDealDamage_BPI"))
		  void TraceDealDamage_BPI();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "SetShouldSprint_BPI"))
		  void SetShouldSprint_BPI(bool  ShouldSprint );
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "SetAttributes_BPI"))
	//	  void SetAttributes_BPI(TArray<FSTR_Attribute> const&  Attributes  );
		  void ReceiveAnyDamage(float  Damage , const UDamageType*  DamageType  , AController*  InstigatedBy , AActor*  DamageCauser );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "OverrideWalkSpeed_BPI"))
		  void OverrideWalkSpeed_BPI(bool  ShouldOverrideWalkSpeedTarget , float  OverridedWalkSpeedTarget , float  OverridedWalkInterpSpeedTarget );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "SetShouldRun_BPI"))
		  void SetShouldRun_BPI(bool  ShouldRunTarget );
	UFUNCTION(   BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "StopAnimation (Multicast)"))
		  void StopAnimationxxMulticastx(float  InBlendOutTime , FName  SlotNodeName );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "SetCharacterName_BPI"))
		  void SetCharacterName_BPI(const FText&  CharacterNameTarget  );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "UpdateStateWidget_BPI"))
		  void UpdateStateWidget_BPI();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "ChangeEnergy_BPI"))
		  void ChangeEnergy_BPI(float  Value , bool  Percent );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "ChangeHealth_BPI"))
		  void ChangeHealth_BPI(float  Value , bool  Percent );
	UFUNCTION(   BlueprintCallable, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "EnableRagdoll (Multicast)"))
		  void EnableRagdollxxMulticastx();

	  void K2_OnMovementModeChanged(EMovementMode  PrevMovementMode , EMovementMode  NewMovementMode , uint8  PrevCustomMode , uint8  NewCustomMode );
	
	//UFUNCTION(meta = (OverrideNativeName = "BndEvt__Sphere_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature"))
	//	  void  BndEvt__Sphere_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature (UPrimitiveComponent*  OverlappedComponent , AActor*  OtherActor , UPrimitiveComponent*  OtherComp , int32  OtherBodyIndex , bool  bFromSweep , FHitResult const&  SweepResult  );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "FinishDialogue_BPI"))
		  void FinishDialogue_BPI(APlayerController*  PlayerController );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "StartDialogue_BPI"))
		  void StartDialogue_BPI(APlayerController*  PlayerController );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Interaction Object", CppFromBpEvent, OverrideNativeName = "TryInteract_BPI"))
		  void TryInteract_BPI(bool  Release , APlayerController*  PlayerController );
	//UFUNCTION(meta = (OverrideNativeName = "BndEvt__AIPerception_K2Node_ComponentBoundEvent_0_ActorPerceptionUpdatedDelegate__DelegateSignature"))
	//	  void  BndEvt__AIPerception_K2Node_ComponentBoundEvent_0_ActorPerceptionUpdatedDelegate__DelegateSignature (AActor*  Actor , FAIStimulus  Stimulus );
		
	  void  ReceiveBeginPlay ();

		  void  ReceivePointDamage (float  Damage , const UDamageType*  DamageType  , FVector  HitLocation , FVector  HitNormal , UPrimitiveComponent*  HitComponent , FName  BoneName , FVector  ShotFromDirection , AController*  InstigatedBy , AActor*  DamageCauser , FHitResult const&  HitInfo  );

	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "SetInteractionState_BPI"))
	//	  void  SetInteractionState_BPI (E_InteractionState   InteractionState , bool  State );
	//UFUNCTION(meta = (OverrideNativeName = "BndEvt__AttributesComponent_K2Node_ComponentBoundEvent_0_OnAttributesChanged__DelegateSignature"))
	//	  void  BndEvt__AttributesComponent_K2Node_ComponentBoundEvent_0_OnAttributesChanged__DelegateSignature ();

	  void  ReceiveTick (float  DeltaSeconds );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "PlayItemSoundAtLocation_BPI"))
		  void  PlayItemSoundAtLocation_BPI (FName  SoundName , FVector  Location );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "TryReload_BPI"))
		  void  TryReload_BPI ();
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "ContinueShooting_BPI"))
	//	  void  ContinueShooting_BPI (FSTR_AnimMontagePlayData  Anim );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "Reload_BPI"))
		  void  Reload_BPI ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "Shoot_BPI"))
		  void  Shoot_BPI (bool  AimedShoot );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "TryStartTradeWithPlayer_BPI"))
		  void  TryStartTradeWithPlayer_BPI (APlayerController*  PlayerController );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "UpdateCustomization_BPI"))
		  void  UpdateCustomization_BPI ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "PlayItemSound_BPI"))
		  void  PlayItemSound_BPI (FName  SoundName );
	
	  void  UserConstructionScript ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Update health variables and set health value in range of max health.", OverrideNativeName = "SetHealthValues"))
		  void  SetHealthValues (float  MaxHealthTarget , float  HealthRegenerationTarget );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Update energy variables and set energy value in range of max health.", OverrideNativeName = "SetEnergyValues"))
		  void  SetEnergyValues (float  MaxEnergyTarget , float  EnergyRegenerationTarget);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Change health value.", OverrideNativeName = "ChangeHealth"))
		  void  ChangeHealth (float  Value , bool  Percent , AController*  InstigatedBy , /*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Change energy value.", OverrideNativeName = "ChangeEnergy"))
		  void  ChangeEnergy (float  Value , bool  Percent , /*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Enable AI.", OverrideNativeName = "EnableAI"))
		  void  EnableAI ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Disable AI.", OverrideNativeName = "DisableAI"))
		  void  DisableAI ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Set guard location for AI.", OverrideNativeName = "SetGuardLocation"))
		  void  SetGuardLocation (FVector  Location );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure, meta = (Category = "AI", Tooltip = "Returns true if target actor is enemy.", OverrideNativeName = "TargetIsEnemy"))
		  void  TargetIsEnemy (AActor*  Target , /*out*/ bool&  IsEnemy );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure, meta = (Category = "AI", Tooltip = "Returns true if target actor is threat.", OverrideNativeName = "TargetIsThreat"))
		  void  TargetIsThreat (AActor* const&  Target  , /*out*/ bool&  IsThreat );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Check threat in range and return threat actor if it exist.", OverrideNativeName = "CheckThreatInRange"))
		  void  CheckThreatInRange (float  ThreatRangeTarget , /*out*/ bool&  HasThreatTarget , /*out*/ AActor*&  ThreatActorTarget );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Set character\'s scared state for AI.", OverrideNativeName = "SetScared"))
		  void  SetScared (bool  Scared );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Update Threat Actor for AI.", OverrideNativeName = "UpdateThreatActor"))
		  void  UpdateThreatActor (AActor*  ThreatActorTarget , bool  Override );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Update Target Actor for AI.", OverrideNativeName = "UpdateTargetActor"))
		  void  UpdateTargetActor (AActor*  TargetActorTarget , bool  Override );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Clear Threat Actor for AI.", OverrideNativeName = "ClearThreatActor"))
		  void  ClearThreatActor ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Clear Target Actor for AI.", OverrideNativeName = "ClearTargetActor"))
		  void  ClearTargetActor ();
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Set Patrol Point and Guard Location for AI.", OverrideNativeName = "SetPatrolPoint"))
	//	  void  SetPatrolPoint (APatrolPoint*  PatrolPoint );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure, meta = (Category = "Interactions|Base", Tooltip = "Returns true if character can interact.", OverrideNativeName = "IsCanInteract"))
		  void  IsCanInteract (/*out*/ bool&  CanInteract );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Enable ragdoll and disable capsule collision.", OverrideNativeName = "EnableRagdoll"))
		  void  EnableRagdoll ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Update character\'s state setting values.", OverrideNativeName = "UpdateStateSettings"))
		  void  UpdateStateSettings (/*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure, meta = (Category = "Interactions|Combat", Tooltip = "Returns true if the character can block attack.", OverrideNativeName = "CheckBlocking"))
		  void  CheckBlocking (float  DamageTarget, const UDamageType*  DamageTypeTarget, AController*  InstigatedByTarget, FHitResult  HitInfoTarget, /*out*/ bool&  IsBlockingTarget);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Combat", Tooltip = "Actions when attack was blocked.", OverrideNativeName = "HitBlocked"))
		  void  HitBlocked (float  Damage , const UDamageType*  DamageType  , AController*  InstigatedBy , FHitResult  HitInfo , /*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Combat", Tooltip = "Actions when the character takes damage.", OverrideNativeName = "DamageTaken"))
		  void  DamageTaken (float  Damage , const UDamageType*  DamageType  , AController*  InstigatedBy , FHitResult  HitInfo , /*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Combat", Tooltip = "Calculating the damage taken by the character.", OverrideNativeName = "CalculateTakenDamage"))
		  float   CalculateTakenDamage (float  Damage );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Update state widget\'s information and visibility.", OverrideNativeName = "UpdateStateWidget"))
		  void  UpdateStateWidget ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Rotate state widget\'s face to the local player controller.", OverrideNativeName = "UpdateStateWidgetRotation"))
		  void  UpdateStateWidgetRotation ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Combat", Tooltip = "Try to attack or continue attack.", OverrideNativeName = "TryAttack"))
		  void  TryAttack (/*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Update relationship settings for target determination and AI.", OverrideNativeName = "UpdateRelationships"))
		  void  UpdateRelationships ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "AI", Tooltip = "Update perception target and determinate it as target or as threat.", OverrideNativeName = "UpdatePerceptionTarget"))
		  void  UpdatePerceptionTarget (AActor*  Actor , FAIStimulus  Stimulus , bool  Override );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Update walk speed depending on the movement variables.", OverrideNativeName = "UpdateWalkSpeed"))
		  void  UpdateWalkSpeed (/*out*/ bool&  Success );
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Set character interaction state.", OverrideNativeName = "SetInteractionState"))
	//	  void  SetInteractionState (E_InteractionState   Selection , bool  State );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Try to interact with player controller.", OverrideNativeName = "TryInteract"))
		  void  TryInteract (bool  Release , APlayerController*  PlayerController , /*out*/ bool&  Success );
//	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Force set max walk speed for character.", OverrideNativeName = "OverrideWalkSpeed"))
//		  void  OverrideWalkSpeed (bool  ShouldOverrideWalkSpeedTarget, float  OverridedWalkSpeedTarget, float  OverridedWalkInterpSpeedTarget);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Dialogue", Tooltip = "Start dialogue with player controller.", OverrideNativeName = "StartDialogue"))
		  void  StartDialogue (APlayerController*  PlayerController , /*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Dialogue", Tooltip = "Finish dialogue with player controller.", OverrideNativeName = "FinishDialogue"))
		  void  FinishDialogue (APlayerController*  PlayerController , /*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Actions when the character dies.", OverrideNativeName = "Death"))
		  void  Death (AController*  KillerController , /*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Update character\'s state by tick.", OverrideNativeName = "UpdateTick"))
		  void  UpdateTick (float  DeltaSeconds , /*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Check fall distance and do damage if it is greater than a certain value.", OverrideNativeName = "CheckFallingDamage"))
		  void  CheckFallingDamage (/*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Movement mode changed actions.", OverrideNativeName = "MovementModeChanged"))
		  void  MovementModeChanged (EMovementMode  PrevMovementMode , EMovementMode  NewMovementMode , /*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Actions when character falls into the water.", OverrideNativeName = "FallIntoWater"))
		  void  FallIntoWater (/*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Init character\'s references and settings.", OverrideNativeName = "InitCharacter"))
		  void  InitCharacter (/*out*/ bool&  Success );
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Play animation.", OverrideNativeName = "PlayAnimation"))
	//	  void  PlayAnimation (FSTR_AnimMontagePlayData const&  AnimMontage  );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Stop animation.", OverrideNativeName = "StopAnimation"))
		  void  StopAnimation (float  InBlendOutTime , FName  SlotNodeName );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Try to do taunt actions.", OverrideNativeName = "TryTaunt"))
		  void  TryTaunt (/*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Try to do AFK actions.", OverrideNativeName = "TryAFK"))
		  void  TryAFK (/*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Enable or disable capsule collision.", OverrideNativeName = "EnableCapsuleCollision"))
		  void EnableCapsuleCollision(bool  Enabled );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "State", Tooltip = "Set character name on the server.", OverrideNativeName = "SetCharacterName"))
		  void SetCharacterName(const FText&  CharacterNameTarget);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Base", Tooltip = "Event when character died.", OverrideNativeName = "DestroyCharacterOnDeath"))
		  void DestroyCharacterOnDeath();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "OnRep_CharacterName"))
		  void OnRep_CharacterName();
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Dialogue", Tooltip = "Play dialogue wave for dialogue reply.", OverrideNativeName = "PlayDialogueReply"))
	//	  void PlayDialogueReply(FSTR_DialogueReply  DialogueReply , FDialogueContext  DialogueContext , /*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Dialogue", Tooltip = "Update talking state. Overridden in child class.", OverrideNativeName = "UpdateTalkingState"))
		  void UpdateTalkingState(/*out*/ bool&  Success );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category, OverrideNativeName = "OnRep_IsTalking"))
		  void  OnRep_IsTalking ();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Dialogue", Tooltip = "Set dialogue sound.", OverrideNativeName = "PlayDialogueSound"))
		  void PlayDialogueSound(USoundBase*  NewSound );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "Interactions|Dialogue", Tooltip = "Stop dialogue sound.", OverrideNativeName = "StopDialogueSound"))
		  void StopDialogueSound();
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|Interactions", CppFromBpEvent, OverrideNativeName = "GetInteractionState_BPI"))
	//	  void GetInteractionState_BPI(E_InteractionState   IteractionState , /*out*/ bool&  State );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "GetHealthInfo_BPI"))
		  void GetHealthInfo_BPI(/*out*/ float&  HealthTarget , /*out*/ float&  MaxHealthTarget, /*out*/ float&  HealthRegenerationTarget);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "GetEnergyInfo_BPI"))
		  void bGetEnergyInfo_BPI(/*out*/ float&  EnergyTarget, /*out*/ float&  MaxEnergyTarget, /*out*/ float&  EnergyRegenerationTarget);
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "GetAttributes_BPI"))
	//	  void GetAttributes_BPI(/*out*/ TArray<FSTR_Attribute>&  Attributes );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "IsAlive_BPI"))
		  void IsAlive_BPI(/*out*/ bool&  Result );
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "GetFraction_BPI"))
	//	  void GetFraction_BPI(/*out*/ E_Fraction &  Fraction );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "GetCharacterName_BPI"))
		  void GetCharacterName_BPI(/*out*/ FText&  NameTarget);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "GetDialogueVoice_BPI"))
		  void GetDialogueVoice_BPI(/*out*/ UDialogueVoice*&  DialogueVoiceTarget);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Character|State", CppFromBpEvent, OverrideNativeName = "GetCharacterIcon_BPI"))
		  void GetCharacterIcon_BPI(/*out*/ UTexture2D*&  CharacterIconTarget);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Interaction Object", CppFromBpEvent, OverrideNativeName = "IsTurnedOn_BPI"))
		  void IsTurnedOn_BPI(/*out*/ bool&  IsTurnedOn );
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Interaction Object", CppFromBpEvent, OverrideNativeName = "GetInteractionText_BPI"))
		  void GetInteractionText_BPI(APlayerController*  PlayerControllerTarget, /*out*/ FText&  InteractionTextTarget);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Interaction Object", CppFromBpEvent, OverrideNativeName = "GetInteractionObjectName_BPI"))
		  void GetInteractionObjectName_BPI(/*out*/ FText&  NameTarget);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, meta = (Category = "BPI Interaction Object", CppFromBpEvent, OverrideNativeName = "CheckCanInteract_BPI"))
		  void CheckCanInteract_BPI(APlayerController*  PlayerController , /*out*/ bool&  CanInteract );


};

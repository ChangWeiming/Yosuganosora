// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Styling/SlateBrush.h"
#include"Engine/DataTable.h"
#include"EasySurvivalRPG/Enumerations/E_Fraction.h"
#include"EasySurvivalRPG/Enumerations/E_InteractionState.h"
#include "Components/WidgetComponent.h"
#include "Character_Base.generated.h"

UCLASS()
class EASYSURVIVALRPG_API ACharacter_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacter_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
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
		bool ShouldAiming = false;
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
		float OverridedWalkSpeed = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		float OverridedWalkInterpSpeed = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State|Interactions")
		float TargetSpeed = 0.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,  meta = (DisplayName = "Is Enabled AI", Category = "State|AI", OverrideNativeName = "IsEnabledAI"))
		bool IsEnabledAI = true;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, meta = (DisplayName = "Guard Location", Category = "State|AI", OverrideNativeName = "GuardLocation"))
		//FVector GuardLocation = FVector(0.0, 0.0, 0.0);
	//PROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, meta = (DisplayName = "Is Scared", Category = "State|AI", OverrideNativeName = "IsScared"))
		//bool IsScared = false;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, meta = (DisplayName = "Threat Actor", Category = "State|AI", OverrideNativeName = "ThreatActor"))
		//AActor* ThreatActor;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, meta = (DisplayName = "Target Actor", Category = "State|AI", OverrideNativeName = "TargetActor"))
		//AActor* TargetActor;
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, meta = (DisplayName = "Aggressive Actors", Category = "State|AI", OverrideNativeName = "AggressiveActors"))
		//TArray<AActor*> AggressiveActors;

	
public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing = "OnRep_CharacterName", meta = (DisplayName = "Character Name", Category = "Settings|Base", OverrideNativeName = "CharacterName"))
		//FText CharacterName = FText::FromString("Character");
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Character Icon", Category = "Settings|Base", OverrideNativeName = "CharacterIcon"))
		//FSlateBrush CharacterIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Show Character State", Category = "Settings|Base", OverrideNativeName = "ShowCharacterState"))
		bool ShowCharacterState = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Show Only Name", Category = "Settings|Base", OverrideNativeName = "ShowOnlyName"))
		bool ShowOnlyName = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Experience for Killing", Category = "Settings|Base", OverrideNativeName = "ExperienceForKilling"))
		float ExperienceForKilling = 100.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Walk Speed", Category = "Settings|Base", OverrideNativeName = "WalkSpeed"))
		float WalkSpeed = 200.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Run Speed", Category = "Settings|Base", OverrideNativeName = "RunSpeed"))
		float RunSpeed = 400.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Ragdoll Bone", Category = "Settings|Base", OverrideNativeName = "RagdollBone"))
		FName RagdollBone = "pelvis";
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Destroy Character Timer", Category = "Settings|Base", OverrideNativeName = "DestroyCharacterTimer"))
		//float DestroyCharacterTimer = 60.0;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Fraction", Category = "Settings|Base", OverrideNativeName = "Fraction"))
		//EE_Fraction Fraction = EE_Fraction::Player;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Is Dashing", Category = "Interactions|Base", MultiLine = "true", OverrideNativeName = "isDashing"))
		bool isDashing = false;

public:
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta = (Category = "Components", OverrideNativeName = "StateWidget"))
		UWidgetComponent* StateWidget;



public:

	UFUNCTION(BlueprintCallable, Category = "State")
		void SetHealthValues(float MaxHealthtemp, float HealthRegenerationtemp);

	UFUNCTION(BlueprintCallable, Category = "State")
		void SetEnergyValues(float MaxEnegytemp, float EnergyRegenerationtemp);

	//Update character\'s state by tick.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent,meta = (Category = "State",OverrideNativeName = "UpdateTick"))
		void UpdateTick(float DeltaSeconds, 
			/*out*/ bool& Success);
	
	//Movement mode changed actions.
	UFUNCTION(BlueprintCallable, meta = (Category = "State",  OverrideNativeName = "MovementModeChanged"))
		virtual void MovementModeChanged(EMovementMode PrevMovementMode, EMovementMode NewMovementMode, 
			/*out*/ bool& Success);

	//Force set max walk speed for character.
	UFUNCTION(BlueprintCallable, meta = (Category = "State", OverrideNativeName = "OverrideWalkSpeed"))
		virtual void OverrideWalkSpeed(bool ShouldOverrideWalkSpeed_temp, float OverridedWalkSpeed_temp, float OverridedWalkInterpSpeed_temp);

	//Update walk speed depending on the movement variables.
	UFUNCTION(BlueprintCallable, meta = (Category = "State", OverrideNativeName = "UpdateWalkSpeed"))
		virtual void UpdateWalkSpeed(/*out*/ bool& Success);

	//Change health value
	UFUNCTION(BlueprintCallable, meta = (Category = "State", OverrideNativeName = "ChangeHealth"))
		virtual void ChangeHealth(float Value, bool Percent, AController* InstigatedBy,
			/*out*/ bool& Success);
	
	UFUNCTION(BlueprintCallable, Category = "State")
		bool ChangeEnergy(float Value, bool Percent);


	//Rotate state widget's face to the local player controller.
	UFUNCTION(BlueprintCallable, meta = (Category = "State", OverrideNativeName = "UpdateStateWidgetRotation"))
		virtual void UpdateStateWidgetRotation();

	//Enable AI.
	UFUNCTION(BlueprintCallable, meta = (Category = "AI", OverrideNativeName = "EnableAI"))
		virtual void EnableAI();

	//Disable AI
	UFUNCTION(BlueprintCallable, meta = (Category = "AI", OverrideNativeName = "DisableAI"))
		virtual void DisableAI();

	//Returns true if character can interact.
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Interactions|Base", OverrideNativeName = "IsCanInteract"))
		virtual void IsCanInteract(/*out*/ bool& CanInteract);

	//Check fall distance and do damage if it is greater than a certain value
	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base",OverrideNativeName = "CheckFallingDamage"))
		virtual void CheckFallingDamage(/*out*/ bool& Success);

	//Enable or disable capsule collision.
	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base", OverrideNativeName = "EnableCapsuleCollision"))
		virtual void EnableCapsuleCollision(bool Enabled);

	//Enable ragdoll and disable capsule collision.
	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base",OverrideNativeName = "EnableRagdoll"))
		virtual void EnableRagdoll();

	//Set character interaction state.
	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base", OverrideNativeName = "SetInteractionState"))
		virtual void SetInteractionState(EE_InteractionState Selection, bool State);

	//Try to attack or continue attack.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (Category = "Interactions|Combat", OverrideNativeName = "TryAttack"))
		void TryAttack(/*out*/ bool& Success);

	//NATIVE EVENT
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Death(AController* KillerController,/*out*/ bool& Success);
};

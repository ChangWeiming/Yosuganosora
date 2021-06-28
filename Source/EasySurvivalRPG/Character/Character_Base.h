// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Styling/SlateBrush.h"
#include"Engine/DataTable.h"
#include"EasySurvivalRPG/Enumerations/E_Fraction.h"
#include"EasySurvivalRPG/Enumerations/E_InteractionState.h"
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

	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, meta = (DisplayName = "Is Enabled AI", Category = "State|AI", OverrideNativeName = "IsEnabledAI"))
		//bool IsEnabledAI = true;
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

	/*
public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing = "OnRep_CharacterName", meta = (DisplayName = "Character Name", Category = "Settings|Base", OverrideNativeName = "CharacterName"))
		//FText CharacterName = FText::FromString("Character");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Character Icon", Category = "Settings|Base", OverrideNativeName = "CharacterIcon"))
		FSlateBrush CharacterIcon;
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
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Loot Handle", Category = "Settings|Base", OverrideNativeName = "LootHandle"))
		//FDataTableRowHandle LootHandle;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Ragdoll Bone", Category = "Settings|Base", OverrideNativeName = "RagdollBone"))
		//FName RagdollBone;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Destroy Character Timer", Category = "Settings|Base", OverrideNativeName = "DestroyCharacterTimer"))
		float DestroyCharacterTimer = 60.0;
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Fraction", Category = "Settings|Base", OverrideNativeName = "Fraction"))
		EE_Fraction Fraction;
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Is Dashing", Category = "Interactions|Base", MultiLine = "true", OverrideNativeName = "isDashing"))
		bool isDashing = false;

	





public:
	UFUNCTION(BlueprintCallable, Category = "State")
		void SetHealthValues(float MaxHealthtemp, float HealthRegenerationtemp);

	UFUNCTION(BlueprintCallable, Category = "State")
		void SetEnergyValues(float MaxEnegytemp, float EnergyRegenerationtemp);
	
	//UFUNCTION(BlueprintCallable, meta = (Category = "State", Tooltip = "Change health value.", OverrideNativeName = "ChangeHealth"))
		//virtual void ChangeHealth(float Value, bool Percent, AController* InstigatedBy, /*输出*/ bool& Success);
	
	UFUNCTION(BlueprintCallable, Category = "State")
		bool ChangeEnergy(float Value, bool Percent);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Interactions|Base", Tooltip = "Returns true if character can interact.", OverrideNativeName = "IsCanInteract"))
		virtual void IsCanInteract(/*输出*/ bool& CanInteract);

	UFUNCTION(BlueprintCallable, meta = (Category = "Interactions|Base", Tooltip = "Set character interaction state.", OverrideNativeName = "SetInteractionState"))
		virtual void SetInteractionState(EE_InteractionState Selection, bool State);
};

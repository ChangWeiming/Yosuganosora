// Easy Systems

#include "Character_Base.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "GeneratedCodeHelpers.h"
#include<algorithm>

using namespace std;

// Sets default values
ACharacter_Base::ACharacter_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacter_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacter_Base::SetHealthValues(float MaxHealthtemp, float HealthRegenerationtemp)
{
	MaxHealth = MaxHealthtemp;
	HealthRegeneration = HealthRegenerationtemp;
	Health = 100;
	if (Health >= MaxHealth)
		Health = MaxHealth;
}

void ACharacter_Base::SetEnergyValues(float MaxEnegytemp, float EnergyRegenerationtemp)
{
	MaxEnergy = MaxEnegytemp;
	HealthRegeneration = EnergyRegenerationtemp;
	if (Energy >= MaxEnergy)
		Energy = MaxEnergy;
}

void ACharacter_Base::UpdateTick_Implementation(float DeltaSeconds, bool & Success)
{
	UpdateStateWidgetRotation();
	float temp_float{};
	bool temp_bool{};
	bool ChangeHealth_Return{};
	bool ChangeEnergy_Return{};
	if (IsAlive)
	{
		//Change Health
		temp_float = UKismetMathLibrary::Multiply_FloatFloat(DeltaSeconds, HealthRegeneration);
		ChangeHealth(temp_float, false, ((AController*)nullptr), ChangeHealth_Return);

		//Change Energy
		temp_float = UKismetMathLibrary::Multiply_FloatFloat(DeltaSeconds, EnergyRegeneration);
		ChangeEnergy_Return = ChangeEnergy(temp_float, false);

		temp_bool = UKismetMathLibrary::BooleanOR(IsAttacking, ShouldBlocking);
		temp_bool = UKismetMathLibrary::BooleanOR(temp_bool, ShouldAiming);
		if (temp_bool)
		{
			RunSpeed = 200.0;
		}
		else
		{
			if (isDashing)
			{
				AddMovementInput(AActor::GetActorForwardVector(), 1.0, false);
			}
			else
			{
				RunSpeed = 400.0;
			}
		}
		Success = true;
	}
}

void ACharacter_Base::MovementModeChanged(EMovementMode PrevMovementMode, EMovementMode NewMovementMode, bool & Success)
{
	bool CheckFallingDamage_Return{};
	if (NewMovementMode == EMovementMode::MOVE_Falling)
	{
		StartFallingLocation = AActor::GetActorLocation();
		StartFallingTime = UKismetMathLibrary::Now();
	}
	else
	{
		if ((PrevMovementMode == EMovementMode::MOVE_Falling) && (NewMovementMode == EMovementMode::MOVE_Walking))
		{
			CheckFallingDamage(CheckFallingDamage_Return);
		}
	}
	Success = true;
}

void ACharacter_Base::OverrideWalkSpeed(bool ShouldOverrideWalkSpeed_temp, float OverridedWalkSpeed_temp, float OverridedWalkInterpSpeed_temp)
{
	ShouldOverrideWalkSpeed = ShouldOverrideWalkSpeed_temp;
	if (ShouldOverrideWalkSpeed)
		OverridedWalkSpeed = OverridedWalkSpeed_temp;
	else
		OverridedWalkSpeed = 0.0;
	OverridedWalkInterpSpeed = OverridedWalkInterpSpeed_temp;
}

void ACharacter_Base::UpdateWalkSpeed(bool & Success)
{
	float ReturnValue{};
	float DeltaTime{};
	float Current{};
	if (ShouldRun)
		ReturnValue = RunSpeed;
	else
		ReturnValue = WalkSpeed;
	if (ShouldOverrideWalkSpeed)
		ReturnValue = OverridedWalkSpeed;
	TargetSpeed = ReturnValue;
	if (ShouldOverrideWalkSpeed)
		ReturnValue = OverridedWalkInterpSpeed;
	else
		ReturnValue = 5.0;
	DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	Current = (this->GetCharacterMovement())->MaxWalkSpeed;
	ReturnValue = UKismetMathLibrary::FInterpTo(Current, TargetSpeed, DeltaTime, ReturnValue);
	(this->GetCharacterMovement())->MaxWalkSpeed = ReturnValue;
	Success = true;

}



void ACharacter_Base::ChangeHealth(float Value, bool Percent, AController * InstigatedBy, bool & Success)
{
	bool Death_Success{};
	if (IsAlive)
	{
		float temp = UKismetMathLibrary::Multiply_FloatFloat(Value, MaxHealth);
		if (!Percent)
			temp = Value;
		temp = UKismetMathLibrary::Add_FloatFloat(Health, temp);
		Health = UKismetMathLibrary::FClamp(temp, 0.0, MaxHealth);
		if (Health <= 0)
		{
			Death(InstigatedBy, /*out*/ Death_Success);
			Success = true;
		}
		else
			Success = true;
	}
	else
	{
		Success = true;
	}

}

bool ACharacter_Base::ChangeEnergy(float Value, bool Percent)
{
	if (Percent == true)
	{
		Energy = max(Value*MaxEnergy + Energy, float(0.0));
		Energy = min(Value*MaxEnergy + Energy, MaxEnergy);
	}
	else
	{
		Energy = max(Value + Energy, float(0.0));
		Energy = min(Value + Energy, MaxEnergy);
	}
	return true;
}



void ACharacter_Base::UpdateStateWidgetRotation()
{
	FVector GetCameraLocation_ReturnValue(EForceInit::ForceInit);
	FVector GetComponentLocation_ReturnValue(EForceInit::ForceInit);
	FRotator FindLookAtRotation_ReturnValue(EForceInit::ForceInit);
	FHitResult SetWorldRotation_SweepHitResult{};
	APlayerCameraManager* GetPlayerCameraManager_ReturnValue{};
	if (::IsValid(StateWidget))
	{
		if (StateWidget->IsVisible())
		{
			StateWidget->USceneComponent::SetHiddenInGame(!IsAlive, false);
		}
		GetPlayerCameraManager_ReturnValue = UGameplayStatics::GetPlayerCameraManager(this, 0);
		if (::IsValid(GetPlayerCameraManager_ReturnValue))
		{
			GetCameraLocation_ReturnValue = GetPlayerCameraManager_ReturnValue->GetCameraLocation();
			GetComponentLocation_ReturnValue = StateWidget->USceneComponent::GetComponentLocation();
			FindLookAtRotation_ReturnValue = UKismetMathLibrary::FindLookAtRotation(GetComponentLocation_ReturnValue, GetCameraLocation_ReturnValue);
			StateWidget->USceneComponent::K2_SetWorldRotation(FindLookAtRotation_ReturnValue, false, /*out*/ SetWorldRotation_SweepHitResult, false);
		}
	}
}

void ACharacter_Base::EnableAI()
{
	FName MakeLiteralName_ReturnValue{};
	UBlackboardComponent* GetBlackboard_ReturnValue{};
	bool IsValid_ReturnValue{};

	GetBlackboard_ReturnValue = UAIBlueprintHelperLibrary::GetBlackboard(this);
	IsValid_ReturnValue = UKismetSystemLibrary::IsValid(GetBlackboard_ReturnValue);
	if (!IsValid_ReturnValue)
	{

	}
	else
	{
		IsEnabledAI = true;
		MakeLiteralName_ReturnValue = UKismetSystemLibrary::MakeLiteralName(FName(TEXT("IsEnabledAI")));
		GetBlackboard_ReturnValue->UBlackboardComponent::SetValueAsBool(MakeLiteralName_ReturnValue, IsEnabledAI);
	}
}

void ACharacter_Base::DisableAI()
{
	FName MakeLiteralName_ReturnValue{};
	UBlackboardComponent* GetBlackboard_ReturnValue{};
	bool IsValid_ReturnValue{};

	GetBlackboard_ReturnValue = UAIBlueprintHelperLibrary::GetBlackboard(this);
	IsValid_ReturnValue = UKismetSystemLibrary::IsValid(GetBlackboard_ReturnValue);
	if (!IsValid_ReturnValue)
	{

	}
	else
	{
		IsEnabledAI = false;
		MakeLiteralName_ReturnValue = UKismetSystemLibrary::MakeLiteralName(FName(TEXT("IsEnabledAI")));
		GetBlackboard_ReturnValue->UBlackboardComponent::SetValueAsBool(MakeLiteralName_ReturnValue, IsEnabledAI);
	}
}

void ACharacter_Base::IsCanInteract(bool & CanInteract)
{
	bool IsPlayingRootMotion_ReturnValue{};
	bool IsSwimming_ReturnValue{};
	bool IsFalling_ReturnValue{};
	isDashing = UKismetMathLibrary::Not_PreBool(isDashing);
	UpperBody = UKismetMathLibrary::Not_PreBool(UpperBody);
	IsPlayingRootMotion_ReturnValue = ACharacter::IsPlayingRootMotion();
	IsPlayingRootMotion_ReturnValue = UKismetMathLibrary::Not_PreBool(IsPlayingRootMotion_ReturnValue);

	if (IsValid(this->GetCharacterMovement()))
	{
		IsSwimming_ReturnValue = (this->GetCharacterMovement())->IsSwimming();
	}
	IsSwimming_ReturnValue = UKismetMathLibrary::Not_PreBool(IsSwimming_ReturnValue);
	if(IsValid(this->GetCharacterMovement()))
	{
		IsFalling_ReturnValue = (this->GetCharacterMovement())->IsFalling();
	}
	IsFalling_ReturnValue = UKismetMathLibrary::Not_PreBool(IsFalling_ReturnValue);
	CanInteract = UKismetMathLibrary::BooleanAND(IsFalling_ReturnValue, IsSwimming_ReturnValue);
	CanInteract = UKismetMathLibrary::BooleanAND(CanInteract, IsPlayingRootMotion_ReturnValue);
	CanInteract = UKismetMathLibrary::BooleanAND(CanInteract, UpperBody);
	CanInteract = UKismetMathLibrary::BooleanAND(CanInteract, isDashing);
}
void ACharacter_Base::CheckFallingDamage(bool & Success)
{
	FDateTime bpfv__CallFunc_Now_ReturnValue__pf{};
	FTimespan bpfv__CallFunc_Subtract_DateTimeDateTime_ReturnValue__pf{};
	FVector bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf(EForceInit::ForceInit);
	float bpfv__CallFunc_GetTotalMilliseconds_ReturnValue__pf{};
	FVector bpfv__CallFunc_Subtract_VectorVector_ReturnValue__pf(EForceInit::ForceInit);
	bool bpfv__CallFunc_GreaterEqual_FloatFloat_ReturnValue__pf{};
	float bpfv__CallFunc_BreakVector_X__pf{};
	float bpfv__CallFunc_BreakVector_Y__pf{};
	float bpfv__CallFunc_BreakVector_Z__pf{};
	float bpfv__CallFunc_MapRangeClamped_ReturnValue__pf{};
	bool bpfv__CallFunc_GreaterEqual_FloatFloat_ReturnValue_1__pf{};
	float bpfv__CallFunc_Multiply_FloatFloat_ReturnValue__pf{};
	bool bpfv__CallFunc_BooleanAND_ReturnValue__pf{};
	bool bpfv__CallFunc_ChangeHealth_Success__pf{};
	int32 __CurrentState = 4;

	FDateTime Now_Value{};
	FTimespan Subtract_FallingTime{};
	float TotalMilliseconds{};
	FVector ActorLocation_Value{};
	FVector Subtract_FallingLocation{};
	float Subtract_FallingLocation_X{};
	float Subtract_FallingLocation_Y{};
	float Subtract_FallingLocation_Z{};
	bool FallingLocation_judge{};
	bool FallingTime_judge{};
	bool Falling_judge{};
	float DamageValue{};
	bool ChangeHealth_Success{};

	//Falling time judge
	Now_Value = UKismetMathLibrary::Now();
	Subtract_FallingTime = UKismetMathLibrary::Subtract_DateTimeDateTime(Now_Value, StartFallingTime);
	TotalMilliseconds = UKismetMathLibrary::GetTotalMilliseconds(Subtract_FallingTime);
	FallingTime_judge = UKismetMathLibrary::GreaterEqual_FloatFloat(TotalMilliseconds, 1200.000000);

	//Falling location judge
	ActorLocation_Value = AActor::GetActorLocation();
	Subtract_FallingLocation = UKismetMathLibrary::Subtract_VectorVector(StartFallingLocation, ActorLocation_Value);
	UKismetMathLibrary::BreakVector(Subtract_FallingLocation, Subtract_FallingLocation_X, Subtract_FallingLocation_Y, Subtract_FallingLocation_Z);
	FallingLocation_judge = UKismetMathLibrary::GreaterEqual_FloatFloat(Subtract_FallingLocation_Z, 300.0);
	
	//Falling judge and take damage
	Falling_judge = FallingTime_judge && FallingLocation_judge;
	if (Falling_judge)
	{
		DamageValue=UKismetMathLibrary::MapRangeClamped(Subtract_FallingLocation_Z, 300.000000, 1000.000000, 0.250000, 1.000000);
	}
	ChangeHealth(-1.0*DamageValue, true, ((AController*)nullptr), ChangeHealth_Success);
	
}
void ACharacter_Base::EnableCapsuleCollision(bool Enabled)
{
	(this->GetCapsuleComponent())->SetEnableGravity(Enabled);
	if (Enabled)
	{
		(this->GetCapsuleComponent())->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		(this->GetCapsuleComponent())->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void ACharacter_Base::EnableRagdoll()
{
	(this->GetCharacterMovement())->SetMovementMode(EMovementMode::MOVE_None, 0);
	EnableCapsuleCollision(false);
	(this->GetMesh())->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	(this->GetMesh())->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	(this->GetMesh())->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Block);
	(this->GetMesh())->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	(this->GetMesh())->SetAllBodiesBelowSimulatePhysics(RagdollBone, true, true);
}

/*
void ACharacter_Base::Death(AController * KillerController, bool & Success)
{
	TScriptInterface<IBPI_Player_C> bpfv__K2Node_DynamicCast_AsBPI_Player__pf{};
	bool bpfv__K2Node_DynamicCast_bSuccess__pf{};
	FTimerDynamicDelegate bpfv__K2Node_CreateDelegate_OutputDelegate__pf{};
	FTimerHandle bpfv__CallFunc_K2_SetTimerDelegate_ReturnValue__pf{};
	AAIController* bpfv__CallFunc_GetAIController_ReturnValue__pf{};
	bool bpfv__CallFunc_IsValid_ReturnValue__pf{};
	int32 __CurrentState = 17;
	do
	{
		switch (__CurrentState)
		{
		case 17:
		{
		}
		case 1:
		{
			AActor::FlushNetDormancy();
		}
		case 2:
		{
			IsAlive= false;
		}
		case 3:
		{
			AActor::FlushNetDormancy();
		}
		case 4:
		{
			bCanBeDamaged = false;
		}
		case 5:
		{
			OnDeath.Broadcast(this, bpp__KillerController__pf);
		}
		case 6:
		{
			if (bpp__KillerController__pf && bpp__KillerController__pf->GetClass()->ImplementsInterface(UBPI_Player_C::StaticClass()))
			{
				bpfv__K2Node_DynamicCast_AsBPI_Player__pf.SetObject(bpp__KillerController__pf);
				void* IAddress = bpp__KillerController__pf->GetInterfaceAddress(UBPI_Player_C::StaticClass());
				bpfv__K2Node_DynamicCast_AsBPI_Player__pf.SetInterface(IAddress);
			}
			else
			{
				bpfv__K2Node_DynamicCast_AsBPI_Player__pf.SetObject(nullptr);
			}
			bpfv__K2Node_DynamicCast_bSuccess__pf = (bpfv__K2Node_DynamicCast_AsBPI_Player__pf != nullptr);;
			if (!bpfv__K2Node_DynamicCast_bSuccess__pf)
			{
				__CurrentState = 8;
				break;
			}
		}
		case 7:
		{
			if (::IsValid(bpfv__K2Node_DynamicCast_AsBPI_Player__pf))
			{
				IBPI_Player_C::Execute_bpf__PlayerKillCharacter_BPI__pf(bpfv__K2Node_DynamicCast_AsBPI_Player__pf.GetObject(), this);
			}
		}
		case 8:
		{
			bpf__StopAnimationxxMulticastx__pfTLK(0.000000, FName(TEXT("None")));
		}
		case 9:
		{
			bpfv__K2Node_CreateDelegate_OutputDelegate__pf.BindUFunction(this, FName(TEXT("DestroyCharacterOnDeath")));
			bpfv__CallFunc_K2_SetTimerDelegate_ReturnValue__pf = UKismetSystemLibrary::K2_SetTimerDelegate(bpfv__K2Node_CreateDelegate_OutputDelegate__pf, bpv__DestroyCharacterTimer__pf, false, 0.000000, 0.000000);
		}
		case 10:
		{
		}
		case 11:
		{
		}
		case 12:
		{
			bpfv__CallFunc_GetAIController_ReturnValue__pf = UAIBlueprintHelperLibrary::GetAIController(this);
			bpfv__CallFunc_IsValid_ReturnValue__pf = UKismetSystemLibrary::IsValid(bpfv__CallFunc_GetAIController_ReturnValue__pf);
			if (!bpfv__CallFunc_IsValid_ReturnValue__pf)
			{
				__CurrentState = 16;
				break;
			}
		}
		case 13:
		{
		}
		case 14:
		{
			DisableAI();
		}
		case 15:
		{
			Success = true;
			__CurrentState = -1;
			break;
		}
		case 16:
		{
			__CurrentState = 15;
			break;
		}
		default:
			break;
		}
	} while (__CurrentState != -1);
}
*/
void ACharacter_Base::SetInteractionState(EE_InteractionState Selection, bool State)
{
	bool SwitchOnEnum_IsSuccess{};
	int32 CurrentState = 12;
	do
	{
		switch (CurrentState)
		{
		case 12:
		{
		}

		case 1:
		{
			SwitchOnEnum_IsSuccess = UKismetMathLibrary::NotEqual_ByteByte(static_cast<uint8>(Selection), static_cast<uint8>(EE_InteractionState::Attacking));
			if (!SwitchOnEnum_IsSuccess)
			{
				CurrentState = 2;
				break;
			}
			SwitchOnEnum_IsSuccess = UKismetMathLibrary::NotEqual_ByteByte(static_cast<uint8>(Selection), static_cast<uint8>(EE_InteractionState::ContinueAttck));
			if (!SwitchOnEnum_IsSuccess)
			{
				CurrentState = 3;
				break;
			}
			SwitchOnEnum_IsSuccess = UKismetMathLibrary::NotEqual_ByteByte(static_cast<uint8>(Selection), static_cast<uint8>(EE_InteractionState::UpperBody));
			if (!SwitchOnEnum_IsSuccess)
			{
				CurrentState = 4;
				break;
			}
			SwitchOnEnum_IsSuccess = UKismetMathLibrary::NotEqual_ByteByte(static_cast<uint8>(Selection), static_cast<uint8>(EE_InteractionState::Blocking));
			if (!SwitchOnEnum_IsSuccess)
			{
				CurrentState = 5;
				break;
			}
			SwitchOnEnum_IsSuccess = UKismetMathLibrary::NotEqual_ByteByte(static_cast<uint8>(Selection), static_cast<uint8>(EE_InteractionState::BlockRotating));
			if (!SwitchOnEnum_IsSuccess)
			{
				CurrentState = 6;
				break;
			}
			SwitchOnEnum_IsSuccess = UKismetMathLibrary::NotEqual_ByteByte(static_cast<uint8>(Selection), static_cast<uint8>(EE_InteractionState::UsingItem));
			if (!SwitchOnEnum_IsSuccess)
			{
				CurrentState = 7;
				break;
			}
			SwitchOnEnum_IsSuccess = UKismetMathLibrary::NotEqual_ByteByte(static_cast<uint8>(Selection), static_cast<uint8>(EE_InteractionState::ShouldBlocking));
			if (!SwitchOnEnum_IsSuccess)
			{
				CurrentState = 8;
				break;
			}
			SwitchOnEnum_IsSuccess = UKismetMathLibrary::NotEqual_ByteByte(static_cast<uint8>(Selection), static_cast<uint8>(EE_InteractionState::ShouldAiming));
			if (!SwitchOnEnum_IsSuccess)
			{
				CurrentState = 9;
				break;
			}
			SwitchOnEnum_IsSuccess = UKismetMathLibrary::NotEqual_ByteByte(static_cast<uint8>(Selection), static_cast<uint8>(EE_InteractionState::Aiming));
			if (!SwitchOnEnum_IsSuccess)
			{
				CurrentState = 10;
				break;
			}
			SwitchOnEnum_IsSuccess = UKismetMathLibrary::NotEqual_ByteByte(static_cast<uint8>(Selection), static_cast<uint8>(EE_InteractionState::Dashing));
			if (!SwitchOnEnum_IsSuccess)
			{
				CurrentState = 11;
				break;
			}
			CurrentState = -1;
			break;
		}
		case 2:
		{
			IsAttacking= State;
			CurrentState = -1;
			break;
		}

		case 3:
		{
			TryContinueAttack = State;
			CurrentState = -1;
			break;
		}

		case 4:
		{
			UpperBody= State;
			CurrentState = -1;
			break;
		}

		case 5:
		{
			IsBlocking = State;
			CurrentState = -1;
			break;
		}

		case 6:
		{
			IsBlockRotation = State;
			CurrentState = -1;
			break;
		}

		case 7:
		{
			IsUsingItem = State;
			CurrentState = -1;
			break;
		}

		case 8:
		{
			ShouldBlocking = State;
			CurrentState = -1;
			break;
		}

		case 9:
		{
			ShouldAiming = State;
			CurrentState = -1;
			break;
		}

		case 10:
		{
			IsAiming = State;
			CurrentState = -1;
			break;
		}
		case 11:
		{
			isDashing = State;
			CurrentState = -1;
			break;
		}
		default:
			break;
		}
	} while (CurrentState != -1);
}

void ACharacter_Base::TryAttack_Implementation(bool & Success)
{
	bool CanInteract{};
	if (IsAttacking)
	{
		TryContinueAttack = true;
		Success = true;
	}
	else
	{
		IsCanInteract(CanInteract);
		if (CanInteract)
		{
			TryContinueAttack = false;
		}
		else
			Success = false;
	}
}


void ACharacter_Base::Death_Implementation(AController * KillerController, bool & Success)
{

}

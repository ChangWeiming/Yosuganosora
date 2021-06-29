// Easy Systems

#include "Character_Base.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Camera/PlayerCameraManager.h"
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
/*
void ACharacter_Base::UpdateStateWidgetRotation()
{
	
}
*/
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

void ACharacter_Base::TryAttack(bool & Success)
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

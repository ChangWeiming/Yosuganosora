// Easy Systems


#include "Character_Base.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
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

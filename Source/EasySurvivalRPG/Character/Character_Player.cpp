// Easy Systems
#include "Character_Player.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h" 
#include "GeneratedCodeHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"

#include <algorithm>




// Sets default values
ACharacter_Player::ACharacter_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacter_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacter_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacter_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacter_Player::CheckSprint()
{
	if (this->ShouldSprint) {
		FVector vel = GetVelocity();
		FRotator rotator = UKismetMathLibrary::NormalizedDeltaRotator(UKismetMathLibrary::Conv_VectorToRotator(vel), AActor::K2_GetActorRotation());
		if (-30.0f <= rotator.Yaw && rotator.Yaw <= 30.0f) {
			if (!IsOverloaded && !IsTired && !UpperBody && !shouldAiming && !ShouldBlocking) {
				this->IsSprinting = true;
				return;
			}
		}
	} 

	this->IsSprinting = false;
}

void ACharacter_Player::UpdateCharacterRotation()
{
	if (this->ShouldUpdateCharacterRotation) {
		auto rotation = APawn::GetControlRotation();
		auto newRotation = UKismetMathLibrary::MakeRotator(0.000000, 0.000000, rotation.Yaw);
		this->PlayerControlRotation = rotation;
		this->TargetCharacterRotation = newRotation;

		if (!this->IsBlockRotation && !this->IsSleep) {
			this->CharacterRotation = UKismetMathLibrary::RInterpTo(CharacterRotation, TargetCharacterRotation, UGameplayStatics::GetWorldDeltaSeconds(this), 5.000000);
		}
		AActor::K2_SetActorRotation(CharacterRotation, true);
	}
}

void ACharacter_Player::CheckEnergy()
{
	if (this->Energy < 5.0) {
		this->IsTired = true;
	}
	float deltaEnergy = 0.0f;
	if (this->IsSprinting) {
		deltaEnergy = UGameplayStatics::GetWorldDeltaSeconds(this) * this->SprintEnergyConsumption;
	}
	else {
		deltaEnergy = UGameplayStatics::GetWorldDeltaSeconds(this) * this->BaseEnergyRestoration;
	}
	bool success = false;
	this->ChangeEnergy(deltaEnergy, false, success);
}
/*
void ACharacter_Player::UpdateWalkSpeed(bool &Success)
{
	float targetWalkSpeed = 0.0f;
	if (ShouldOverrideWalkSpeed) {
		targetWalkSpeed = OverrideWalkSpeed;
	}
	else {
		if (IsSprinting) {
			targetWalkSpeed = SprintSpeed;
		}
		else {
			targetWalkSpeed = RunSpeed;
		}

		if (!ShouldRun) {
			targetWalkSpeed = WalkSpeed;
		}
	}

	if (IsOverloaded) {
		targetWalkSpeed = std::max(0.0f, targetWalkSpeed);
		targetWalkSpeed = std::min(300.0f, targetWalkSpeed);
	}

	this->TargetSpeed = targetWalkSpeed;

	auto movement = *(AccessPrivateProperty<UCharacterMovementComponent* >((this), ACharacter::__PPO__CharacterMovement()));
	auto seconds = UGameplayStatics::GetWorldDeltaSeconds(this);
	auto speed = UKismetMathLibrary::FInterpTo(movement->MaxWalkSpeed, targetWalkSpeed, seconds,
		ShouldOverrideWalkSpeed ? OverrideWalkInterpSpeed : 5.0f);
	movement->MaxWalkSpeed = speed;
	Success = true;
}

void ACharacter_Player::CheckSwimming()
{
	auto movement = *(AccessPrivateProperty<UCharacterMovementComponent* >((this), ACharacter::__PPO__CharacterMovement()));

	if (movement->IsSwimming()) {
		if (ShouldDive) {
			AddMovementInput(FVector(0.000000, 0.000000, -1.000000), 1.000000, false);
		}
		else {
			auto location = AActor::K2_GetActorLocation();
			auto start = FVector(location.X, location.Y, location.Z - 50.0),
				end = FVector(location.X, location.Y, location.Z + 50.0);

			//auto collision = UKismetSystemLibrary::LineTraceSingleForObjects(this, start, end, bpfv__K2Node_MakeArray_Array_1__pf, false, bpfv__Temp_object_Variable_1__pf, EDrawDebugTrace::None, bpfv__CallFunc_LineTraceSingleForObjects_OutHit_1__pf, true, FLinearColor(1.000000, 0.000000, 0.000000, 1.000000), FLinearColor(0.000000, 1.000000, 0.000000, 1.000000), 5.000000);

		}
	}
	else {
		this->ConsumeOxygen = false;
	}
}

*/
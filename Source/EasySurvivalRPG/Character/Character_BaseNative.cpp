// Easy Systems


#include "Character_BaseNative.h"

// Sets default values
ACharacter_BaseNative::ACharacter_BaseNative()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacter_BaseNative::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacter_BaseNative::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacter_BaseNative::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacter_BaseNative::UserConstructionScript() {

}
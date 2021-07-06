// Easy Systems


#include "Ability_Base.h"

// Sets default values
AAbility_Base::AAbility_Base()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	//RootComponent = DefaultSceneRoot;
	SetRootComponent(SceneRoot);
	//DefaultSceneRoot->CreationMethod = EComponentCreationMethod::Native;
}

// Called when the game starts or when spawned
void AAbility_Base::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAbility_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAbility_Base::Use_Implementation()
{
	AActor::K2_DestroyActor();
	return;
}

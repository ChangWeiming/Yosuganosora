// Easy Systems


#include "S_Ability_Base.h"
#include"GeneratedCodeHelpers.h"
// Sets default values
AS_Ability_Base::AS_Ability_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	DefaultSceneRoot->CreationMethod = EComponentCreationMethod::Native;
	static TWeakObjectPtr<UProperty> Local1{};
	const UProperty* Local0 = Local1.Get();
	if (nullptr == Local0)
	{
		Local0 = (UActorComponent::StaticClass())->FindPropertyByName(FName(TEXT("bCanEverAffectNavigation")));
		check(Local0);
		Local1 = Local0;
	}
	(((UBoolProperty*)Local0)->SetPropertyValue_InContainer((DefaultSceneRoot), false, 0));
    AbilityText = FText::GetEmpty();
	auto& Local = (*(AccessPrivateProperty<EActorUpdateOverlapsMethod >((this), AActor::__PPO__DefaultUpdateOverlapsMethodDuringLevelStreaming())));
	Local = EActorUpdateOverlapsMethod::OnlyUpdateMovable;

}

// Called when the game starts or when spawned
void AS_Ability_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AS_Ability_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



/*Execute for use ability. Override it in child class.
Look at BP_Ability_ChangeState for example.*/
void AS_Ability_Base::Use()
{
	AActor::K2_DestroyActor();
}

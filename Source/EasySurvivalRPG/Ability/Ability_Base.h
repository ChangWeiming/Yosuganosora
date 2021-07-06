// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "Ability_Base.generated.h"

UCLASS()
class EASYSURVIVALRPG_API AAbility_Base : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAbility_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//,BlueprintImplementableEvent
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Use();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Ability Text", Category = "Ability", tooltip = "Ability description."))
		FText AbilityText;
	UPROPERTY()
		USceneComponent* SceneRoot;
};

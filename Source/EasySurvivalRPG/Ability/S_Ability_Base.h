// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "S_Ability_Base.generated.h"

UCLASS()
class EASYSURVIVALRPG_API AS_Ability_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AS_Ability_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		virtual void Use();
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent* DefaultSceneRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (DisplayName = "Ability Text", Category = "Ability", tooltip = "Ability description."))
		FText AbilityText;

};

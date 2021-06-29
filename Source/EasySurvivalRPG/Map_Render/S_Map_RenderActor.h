// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include"Components/SceneCaptureComponent2D.h"
#include "GameFramework/Actor.h"
#include "S_Map_RenderActor.generated.h"

UCLASS(Blueprintable)
class EASYSURVIVALRPG_API AS_Map_RenderActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AS_Map_RenderActor();

	UFUNCTION(BlueprintCallable)
		void SetRenderLocation(FVector NewLocation);

	UFUNCTION(BlueprintCallable)
		void SetRenderWidth(float Width = 3000.0, bool Clamp = true);

	UFUNCTION(BlueprintCallable)
		void UpdateLocation();

	UFUNCTION(BlueprintCallable)
		void SetFollowToTarget(bool FollowTarget);

	UFUNCTION(BlueprintCallable)
		void UpdateRenderMode();

	UFUNCTION(BlueprintCallable)
		void SetSelectedActor(AActor* Actor);

	UFUNCTION(BlueprintCallable)
		void ChangeRenderOffset(FVector DeltaLocation);

	UFUNCTION(BlueprintCallable)
		void ChangeRenderWidth(float DeltaWidth);

	UFUNCTION(BlueprintCallable)
		void RenderMinimap();

	UFUNCTION(BlueprintCallable)
		void RenderMap();

	UFUNCTION(BlueprintCallable)
		virtual void AddActorToRenderList(AActor* Actor, bool& Success);
	/*
	UFUNCTION(BlueprintCallable, meta = (Category = "д╛хо", OverrideNativeName = "SetRenderSettings"))
		virtual void SetRenderSettings(AActor* MapSpriteActor, bool ClampRenderLocation, FVector lampBoxOrigin, FVector lampBoxExtent);*/

	UFUNCTION(BlueprintCallable)
		virtual void ClearMapSelection();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		bool MapIsOpen = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		bool FollowToTarget = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		float CurrentRenderWidth = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		AActor* SelectedActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		AActor* SelectedMapSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		bool ClampRender;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		FVector SelectedMapBoxOrigin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		FVector SelectedMapBoxExtent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float MinRenderWidth = 6000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float MaxRenderWidth = 15000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float MinimapRenderWidth = 4200;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float MapRenderWidth = 8000;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Components")
		USceneCaptureComponent2D* MyMapSceneCapture = (USceneCaptureComponent2D*)nullptr;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USpringArmComponent* MyRenderArm;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Category = "Settings", ExposeOnSpawn = "true", OverrideNativeName = "TargetActor"))
		AActor* TargetActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		bool RenderOnlySprite = true;

};

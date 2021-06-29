// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include"GameFramework/Character.h"
#include"Components/SceneComponent.h"
#include"Components/BillboardComponent.h"
#include"Components/WidgetComponent.h"
#include "My_UI_WorldMark.h"
#include "GameFramework/Actor.h"
#include "My_MapMark.generated.h"

UCLASS()
class EASYSURVIVALRPG_API AMy_MapMark : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMy_MapMark();



public://组件声明
	
	UPROPERTY(BlueprintReadWrite, NonTransactional)
		USceneComponent* S_SceneRoot = (USceneComponent*)nullptr;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly)
		UWidgetComponent* S_MapWidget = (UWidgetComponent*)nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UWidgetComponent* S_WorldWidget = (UWidgetComponent*)nullptr;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UBillboardComponent* S_Billboard = (UBillboardComponent*) nullptr;


public://函数声明
	UFUNCTION(BlueprintCallable, meta = (Category = "Mark", Tooltip = "Try to attach mark to target actor."))
		virtual void TryAttachToTarget();

	UFUNCTION(BlueprintCallable, meta = (Category = "Mark", Tooltip = "Detach mark from actor."))
		virtual void Detach();

	UFUNCTION(BlueprintCallable, meta = (Category = "Mark", Tooltip = "Set map is open state and update map mark visibility."))
		virtual void SetMapIsOpen(bool IsOpen);

	UFUNCTION(BlueprintCallable, meta = (Category = "Mark", Tooltip = "Update mark location."))
		virtual void UpdateMarkLocation();

	UFUNCTION(BlueprintCallable, meta = (Category = "Mark", Tooltip = "Update world widget."))
		virtual void UpdateWorldMark();

	UFUNCTION(BlueprintCallable, meta = (Category = "Mark", Tooltip = "Update mark distance in world widget."))
		virtual void UpdateMarkDistance(ACharacter* Character);

	UFUNCTION(BlueprintCallable, meta = (Category = "Mark", Tooltip = "Update map widget."))
		virtual void UpdateMapMark();


	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (Category = "Mark", Tooltip = "Update mark visibility depending on current state and game settings."))
		void UpdateMarkVisibility();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta = (Category = "Mark", Tooltip = "Update mark position and state."))
		void UpdateMark();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		FName MarkTag = FName();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		FText MarkName = FText::GetEmpty();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		bool ShowWorldMark = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		bool ShowMinimapMark = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		bool ShowMapMark = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		bool ShowDistance = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		AActor* TargetActor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		float TargetHeight = 100.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		bool RotateMark = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State")
		bool MapIsOpen = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State")
		float Distance = 0.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State")
		bool RenderOnMap = false;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		UMy_UI_WorldMark* WorldWidgetReference = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mark Settings")
		UMy_UI_WorldMark* MapWidgetReference = nullptr;
};

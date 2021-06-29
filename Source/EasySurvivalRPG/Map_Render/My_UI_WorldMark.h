// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include"Engine/Texture2D.h"
#include"Components/Image.h"
#include"Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "My_UI_WorldMark.generated.h"

/**
 * 
 */
UCLASS()
class EASYSURVIVALRPG_API UMy_UI_WorldMark : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		virtual void SetIcon(UTexture2D* Texture);
	UFUNCTION(BlueprintCallable)
	    virtual void SetDistanceVisibility(bool Visible);
	UFUNCTION(BlueprintCallable)
		virtual void SetDistance(float Distance);
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UImage* MyMarkIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextBlock* MyDistanceText;

};

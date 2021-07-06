// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Ability_Base.h"
#include "Ability_AddBlueprint.generated.h"

/**
 *
 */
UCLASS()
class EASYSURVIVALRPG_API AAbility_AddBlueprint : public AAbility_Base
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Ability", OverrideNativeName = "TargetBlueprintList"))
		FDataTableRowHandle TargetBlueprintList;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Ability", OverrideNativeName = "TargetBlueprint"))
		FDataTableRowHandle TargetBlueprint;

	UFUNCTION(BlueprintCallable)
		void CallAddUse();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void CallAddBlueprintToList_BPI(UObject* Target, const FDataTableRowHandle& TargetList, const FDataTableRowHandle& Blueprint);

};
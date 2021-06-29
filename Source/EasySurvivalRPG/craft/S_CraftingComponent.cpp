// Easy Systems


#include "S_CraftingComponent.h"
#include"Kismet/KismetArrayLibrary.h"
#include"GeneratedCodeHelpers.h"
// Sets default values for this component's properties
US_CraftingComponent::US_CraftingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	ActivePlayers = TArray<APlayerController*>();
	BlueprintsQueue = TArray<FSTR_QueueBlueprint>();
	SaveID = 0;

	//CraftingListHandle.DataTable = CastChecked<UDataTable>(CastChecked<UDynamicClass>(US_CraftingComponent::StaticClass())->UsedAssets[0], ECastCheckedType::NullAllowed);
	CraftingEnabled = true;
	CraftingTickTime = 0.100000f;
	MulticraftCount = 1;
	CompleteEventBinds = false;
	Autocrafting = false;
	// ...
}


// Called when the game starts
void US_CraftingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void US_CraftingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void US_CraftingComponent::UpdateQueueBlueprint_Implementation(int32 IndexInQueue, FSTR_QueueBlueprint QueueBlueprint)
{

}

void US_CraftingComponent::CompleteCrafting_Implementation(FSTR_Blueprint Blueprint, int32 Amount)
{

}


void US_CraftingComponent::RemoveBlueprintFromQueue_Implementation(int32 IndexInQueue)
{
}

void US_CraftingComponent::CraftingTick()
{
	int32 Array_length = FCustomThunkTemplates::Array_Length(BlueprintsQueue);
	int32 MyLength;
	int32 Index;

	FSTR_Blueprint MyBlueprint;

	if (CraftingEnabled)
	{
		MyLength = Array_length - 1;

		for (int32 i = 0; i <= MyLength; i++)
		{
			Index = MyLength - i;
			if (Index < MulticraftCount)
			{
				FS_STR_QueueBlueprint QueueBlueprint;

				QueueBlueprint = BlueprintsQueue[Index];

				if (QueueBlueprint.TimeRemaining - CraftingTickTime > 0.0)
				{
					QueueBlueprint.TimeRemaining = QueueBlueprint.TimeRemaining - CraftingTickTime;
					
					UpdateQueueBlueprint(Index, QueueBlueprint);
				}
				else
				{
					MyBlueprint = QueueBlueprint.Blueprint;

					if (QueueBlueprint.AmountRemaining - 1 > 0)
					{
						QueueBlueprint.AmountRemaining = QueueBlueprint.AmountRemaining - 1;
						
						QueueBlueprint.TimeRemaining = QueueBlueprint.Blueprint.RequiredTime;
						
						UpdateQueueBlueprint(Index, QueueBlueprint);

						CompleteCrafting(MyBlueprint, 1);
					}
					else
					{
						RemoveBlueprintFromQueue(Index);
						
						CompleteCrafting(MyBlueprint, 1);
					}


				}
			}
		}
	}
}
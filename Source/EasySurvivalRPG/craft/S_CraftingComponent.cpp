// Easy Systems


#include "S_CraftingComponent.h"
#include "Engine/DataTable.h"
#include "Kismet/KismetArrayLibrary.h"
#include "GeneratedCodeHelpers.h"
// Sets default values for this component's properties
US_CraftingComponent::US_CraftingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	ActivePlayers = TArray<APlayerController*>();
	BlueprintsQueue = TArray<FS_STR_QueueBlueprint>();
	SaveID = 0;

	//CraftingListHandle.DataTable = nullptr;
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


//更新制作队列
void US_CraftingComponent::UpdateQueueBlueprint(int32 IndexInQueue,FS_STR_QueueBlueprint QueueBlueprint)
{
	for (APlayerController*& ActivePlayer : ActivePlayers)
	{
		CallUpdateCraftingQueueBlueprint_BPI(ActivePlayer, IndexInQueue, QueueBlueprint);
	}
}


//完成制作后，添加结果物品到背包
void US_CraftingComponent::CompleteCrafting(FS_STR_Blueprint Blueprint, int32 Amount)
{
	FS_STR_Blueprint LocalBlueprint;
	int32 LocalAmount;
	TArray<FS_STR_Item> ResultItem;

	LocalBlueprint = Blueprint;
	LocalAmount = Amount;

	//根据传入的结果物品和它的数量，将其相乘得到最终需要添加到背包的数量
	CallMultiplyItems(LocalBlueprint.ResultItems, UKismetMathLibrary::Conv_IntToFloat(LocalAmount), ResultItem);

	//尝试将物品加入到背包中，//如果在默认放弃的位置则放弃将物品加入
	CallTryAddItemsorDrop(ResultItem);

	if (CompleteEventBinds)
	{
		CCOnCraftingCompleted(LocalBlueprint, LocalAmount);
	}
	else
	{
		for (APlayerController* ActivePlayer : ActivePlayers)
		{
			CallCompleteCrafting_BPI(ActivePlayer, LocalBlueprint, LocalAmount);
		}
	}
}

//将制作队列中对应的需要制作的物品移除，一般调用于制作完成(CraftingTick)或者取消制作(CancelCrafting)后
void US_CraftingComponent::RemoveBlueprintFromQueue(int32 IndexInQueue)
{
	//将数组队列中中对应的需要制作的物品移除
	FCustomThunkTemplates::Array_Remove(BlueprintsQueue, IndexInQueue);

	for (APlayerController* ActivePlayer : ActivePlayers)
	{
		//更新每个当前活跃玩家的制作列表
		CallUpdateCraftingQueue_BPI(ActivePlayer);
	}

	if (FCustomThunkTemplates::Array_Length(BlueprintsQueue) == 0)
	{
		//清楚之前设置的函数委托定时器
		UKismetSystemLibrary::K2_ClearAndInvalidateTimerHandle(this, CraftingTickTimerHandle);

		CCOnCraftingEnded();
		if (Autocrafting)
		{
			AutoStartCrafting();
		}
	}

};

//接口，将物品加入背包
void US_CraftingComponent::CallTryAddItemsorDrop_Implementation(const TArray<FS_STR_Item>& TryItem)
{
}

//接口，更新玩家的制作列表
void US_CraftingComponent::CallUpdateCraftingQueue_BPI_Implementation(APlayerController* ActivePlayer)
{

}

void US_CraftingComponent::CallGetBlueprintFromHandle_Implementation(const FDataTableRowHandle& TableHandle, FS_STR_Blueprint & ReturnBlueprint)
{
	
}

//检测制作物品需要的项目需要的
void US_CraftingComponent::CallCheckRequiredItems_Implementation(const TArray<FS_STR_Item>& STR_Item, bool & Reslut)
{

}

void US_CraftingComponent::CallOverRmoveRequiredItems_Implementation(const TArray<FS_STR_Item>& Items)
{

}

void US_CraftingComponent::CallStartCrafting_Implementation(const FS_STR_Blueprint& Blueprint, const int32& Amount)
{

}

/*
void US_CraftingComponent::GetCraftingBlueprints_Implementation(TArray<FDataTableRowHandle>& Blueprints)
{
}*/

//更新制作剩余时间，并在制作结束后调用添加背包函数和更新队列的相关函数(remove等)
void US_CraftingComponent::CraftingTick()
{
	int32 Array_length = FCustomThunkTemplates::Array_Length(BlueprintsQueue);
	int32 MyLength;
	int32 Index;//localLength

	FS_STR_Blueprint MyBlueprint;


	if (CraftingEnabled)//如果CraftingEnabled为true则表明可以开始制作
	{
		MyLength = Array_length - 1;//获取当前要制作的制作队列长度

		for (int32 i = 0; i <= MyLength; i++)
		{
			Index = MyLength - i;//当前剩余需要制作的物品
			if (Index < MulticraftCount)
			{
				//获取当前被制作的物品中的一类
				//此处必须要用引用传递，否则不会真正改变剩余需要制作时间，制作时剩余时间不会改变
				FS_STR_QueueBlueprint& QueueBlueprint = BlueprintsQueue[Index];

				if (QueueBlueprint.TimeRemaining - CraftingTickTime > 0.0)
				{
					//甚于制作时间还能减去制作计量单位时间时，减去一个单位的制作时间，同时更新制作蓝图队列
					//主要是更新制作队列里的制作时间
					QueueBlueprint.TimeRemaining = QueueBlueprint.TimeRemaining - CraftingTickTime;
					UpdateQueueBlueprint(Index, QueueBlueprint);
				}
				else
				{
					MyBlueprint = QueueBlueprint.Blueprint;//当前被制作的物品

					//当一个物品剩余制作时间为0，就代表它被制作成功，此时判断是否还有相同种类的剩余物品需要制作
					if (QueueBlueprint.AmountRemaining - 1 > 0)
					{
						//需要被制作的该类物品的数量减1；
						QueueBlueprint.AmountRemaining = QueueBlueprint.AmountRemaining - 1;

						//下一个被制作的该类物品的剩余制作所需时间设置为制作该类物品的所需时间
						QueueBlueprint.TimeRemaining = QueueBlueprint.Blueprint.RequiredTime;

						//更新制作列表，传入要制作的物品蓝图(包含剩余时间和剩余数量的那种)和它的编号
						UpdateQueueBlueprint(Index, QueueBlueprint);

						//完成一次该物品的制作，传入该物品以及它的数量
						CompleteCrafting(MyBlueprint, 1);
					}
					else
					{
						//如果没有，则将该物品从制作列表中移除，然后结束该种类物品的制作
						RemoveBlueprintFromQueue(Index);
						CompleteCrafting(MyBlueprint, 1);
					}


				}
			}
		}
	}
}

//执行取消制作后的一系列操作，计算需要返还的消耗物品数量，重新将其加入背包，之后将被取消制作的物品从制作列表中移除
void US_CraftingComponent::CancelCrafting(int32 IndexInQueue)
{
	int32 LocalIndex;
	LocalIndex = IndexInQueue;

	//从制作队列中获取被取消制作的物品
	FS_STR_QueueBlueprint TempBlueprint;
	FCustomThunkTemplates::Array_Get(BlueprintsQueue, IndexInQueue, TempBlueprint);//获取的是副本

	TArray<FS_STR_Item> ReturnItem;

	//根据传入的被取消制作的物品和其数量，获取需要返还的之前需要被消耗的物品
	CallMakeBlueprintRequiredItems(TempBlueprint.Blueprint, TempBlueprint.AmountRemaining, ReturnItem);

	//将返还的物品重新加入背包；
	CallTryAddItemsorDrop(ReturnItem);

    //从制作列表中移除被取消制作的物品
	RemoveBlueprintFromQueue(LocalIndex);
}


//创建需要制作的物品的蓝图将其加入制作队列，随后创建CraftingTick函数定时事件开始制作，最后更新玩家制作列表
void US_CraftingComponent::AddBlueprintToQueue(FS_STR_Blueprint Blueprint, int32 Amount)
{
	FS_STR_QueueBlueprint TempQueue;

	//创建当前要制作的物品的蓝图，设置其需要制作的数量，和单个物品的制作剩余时间
	TempQueue.Blueprint = Blueprint;
	TempQueue.AmountRemaining = Amount;
	TempQueue.TimeRemaining = Blueprint.RequiredTime;


	//将当前需要制作的物品蓝图加入制作列表
	FCustomThunkTemplates::Array_Add(BlueprintsQueue, TempQueue);
	//获取当前制作列表的长度
	int32 ArrayLength = FCustomThunkTemplates::Array_Length(BlueprintsQueue);


	FTimerDynamicDelegate  Timer{};

	if (ArrayLength == 1)
	{
		Timer.BindUFunction(this, FName(TEXT("CraftingTick")));//绑定函数，创建事件

		//设置一个定时器来执行函数委托(CraftingTick)。设置现有计时器将使用更新的参数重置该计时器。
		//Timer为要执行的事件，也就是说要执行CraftingTick函数， CraftingTickTime为要在执行委托之前等待多长时间，以秒为单位
		//True 表示每隔 CraftingTickTime 秒继续执行委托,第四个参数为初始启动延迟；
		CraftingTickTimerHandle = UKismetSystemLibrary::K2_SetTimerDelegate(Timer, CraftingTickTime, true, 0.0f, 0.0f);

		//开启制作
		CCOnCraftingStarted();
	}

	for (APlayerController* ActivePlayer : ActivePlayers)
	{
		//更新每个当前活跃玩家的制作列表
		CallUpdateCraftingQueue_BPI(ActivePlayer);
	}

}

void US_CraftingComponent::AutoStartCrafting()
{
	int32 QueueLength;

	FS_STR_Blueprint LocalBlueprint;

	FTimerDynamicDelegate Timer{};


	//获取蓝图队列长度
	QueueLength = FCustomThunkTemplates::Array_Length(BlueprintsQueue);

	int32 BigState = 0;

	do
	{
		switch (BigState)
		{
		case 0:
		{
			if (QueueLength < MulticraftCount && CraftingEnabled)
			{

				TArray<FDataTableRowHandle> Blueprints;
				
				GetCraftingBlueprints(Blueprints);

				for (FDataTableRowHandle& TableHandle : Blueprints)
				{
					FS_STR_Blueprint ReturnBlueprint;

					CallGetBlueprintFromHandle(TableHandle, ReturnBlueprint);

					LocalBlueprint = ReturnBlueprint;

					TArray<FS_STR_Item> STRItem;

					CallMakeBlueprintRequiredItems(LocalBlueprint, 1, STRItem);

					bool CheckResult;

					CallCheckRequiredItems(STRItem, CheckResult);

					int32 state = 0;

					do
					{
						switch (state)
						{
						case 0:
						{
							if (CheckResult)
							{
								CallStartCrafting(LocalBlueprint, 1);

								if (FCustomThunkTemplates::Array_Length(BlueprintsQueue) > MulticraftCount)
								{
									return;
									state = -1;
									break;
								}
								else
								{
									state = 0; break;
								}
							}
							else
							{
								state = -1;

								break;
							}
						}

						default:
						{
							state = -1;
							break;
						}
						}
					} while (state != -1);
				};

				BigState = 1;
				break;
			}
			else
			{
				BigState = 1;
				break;
			}
		}
		case 1:
		{
			if (Autocrafting)
			{
				Timer.BindUFunction(this, FName(TEXT("AutoStartCrafting")));
				UKismetSystemLibrary::K2_SetTimerDelegate(Timer, 1, false, 0.0f, 0.0f);
				BigState = -1;
				break;
			}
		}

		}

	} while (BigState != -1);

	return;
}

//设置可否进行制作
void US_CraftingComponent::SetCraftingEnabled(bool Enable)
{
	CraftingEnabled = Enable;
}
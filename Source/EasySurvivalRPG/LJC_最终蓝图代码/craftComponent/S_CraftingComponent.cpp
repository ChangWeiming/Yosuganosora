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


//������������
void US_CraftingComponent::UpdateQueueBlueprint(int32 IndexInQueue,FS_STR_QueueBlueprint QueueBlueprint)
{
	for (APlayerController*& ActivePlayer : ActivePlayers)
	{
		CallUpdateCraftingQueueBlueprint_BPI(ActivePlayer, IndexInQueue, QueueBlueprint);
	}
}


//�����������ӽ����Ʒ������
void US_CraftingComponent::CompleteCrafting(FS_STR_Blueprint Blueprint, int32 Amount)
{
	FS_STR_Blueprint LocalBlueprint;
	int32 LocalAmount;
	TArray<FS_STR_Item> ResultItem;

	LocalBlueprint = Blueprint;
	LocalAmount = Amount;

	//���ݴ���Ľ����Ʒ������������������˵õ�������Ҫ��ӵ�����������
	CallMultiplyItems(LocalBlueprint.ResultItems, UKismetMathLibrary::Conv_IntToFloat(LocalAmount), ResultItem);

	//���Խ���Ʒ���뵽�����У�//�����Ĭ�Ϸ�����λ�����������Ʒ����
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

//�����������ж�Ӧ����Ҫ��������Ʒ�Ƴ���һ��������������(CraftingTick)����ȡ������(CancelCrafting)��
void US_CraftingComponent::RemoveBlueprintFromQueue(int32 IndexInQueue)
{
	//������������ж�Ӧ����Ҫ��������Ʒ�Ƴ�
	FCustomThunkTemplates::Array_Remove(BlueprintsQueue, IndexInQueue);

	for (APlayerController* ActivePlayer : ActivePlayers)
	{
		//����ÿ����ǰ��Ծ��ҵ������б�
		CallUpdateCraftingQueue_BPI(ActivePlayer);
	}

	if (FCustomThunkTemplates::Array_Length(BlueprintsQueue) == 0)
	{
		//���֮ǰ���õĺ���ί�ж�ʱ��
		UKismetSystemLibrary::K2_ClearAndInvalidateTimerHandle(this, CraftingTickTimerHandle);

		CCOnCraftingEnded();
		if (Autocrafting)
		{
			AutoStartCrafting();
		}
	}

};

//�ӿڣ�����Ʒ���뱳��
void US_CraftingComponent::CallTryAddItemsorDrop_Implementation(const TArray<FS_STR_Item>& TryItem)
{
}

//�ӿڣ�������ҵ������б�
void US_CraftingComponent::CallUpdateCraftingQueue_BPI_Implementation(APlayerController* ActivePlayer)
{

}

void US_CraftingComponent::CallGetBlueprintFromHandle_Implementation(const FDataTableRowHandle& TableHandle, FS_STR_Blueprint & ReturnBlueprint)
{
	
}

//���������Ʒ��Ҫ����Ŀ��Ҫ��
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

//��������ʣ��ʱ�䣬�������������������ӱ��������͸��¶��е���غ���(remove��)
void US_CraftingComponent::CraftingTick()
{
	int32 Array_length = FCustomThunkTemplates::Array_Length(BlueprintsQueue);
	int32 MyLength;
	int32 Index;//localLength

	FS_STR_Blueprint MyBlueprint;


	if (CraftingEnabled)//���CraftingEnabledΪtrue��������Կ�ʼ����
	{
		MyLength = Array_length - 1;//��ȡ��ǰҪ�������������г���

		for (int32 i = 0; i <= MyLength; i++)
		{
			Index = MyLength - i;//��ǰʣ����Ҫ��������Ʒ
			if (Index < MulticraftCount)
			{
				//��ȡ��ǰ����������Ʒ�е�һ��
				//�˴�����Ҫ�����ô��ݣ����򲻻������ı�ʣ����Ҫ����ʱ�䣬����ʱʣ��ʱ�䲻��ı�
				FS_STR_QueueBlueprint& QueueBlueprint = BlueprintsQueue[Index];

				if (QueueBlueprint.TimeRemaining - CraftingTickTime > 0.0)
				{
					//��������ʱ�仹�ܼ�ȥ����������λʱ��ʱ����ȥһ����λ������ʱ�䣬ͬʱ����������ͼ����
					//��Ҫ�Ǹ������������������ʱ��
					QueueBlueprint.TimeRemaining = QueueBlueprint.TimeRemaining - CraftingTickTime;
					UpdateQueueBlueprint(Index, QueueBlueprint);
				}
				else
				{
					MyBlueprint = QueueBlueprint.Blueprint;//��ǰ����������Ʒ

					//��һ����Ʒʣ������ʱ��Ϊ0���ʹ������������ɹ�����ʱ�ж��Ƿ�����ͬ�����ʣ����Ʒ��Ҫ����
					if (QueueBlueprint.AmountRemaining - 1 > 0)
					{
						//��Ҫ�������ĸ�����Ʒ��������1��
						QueueBlueprint.AmountRemaining = QueueBlueprint.AmountRemaining - 1;

						//��һ���������ĸ�����Ʒ��ʣ����������ʱ������Ϊ����������Ʒ������ʱ��
						QueueBlueprint.TimeRemaining = QueueBlueprint.Blueprint.RequiredTime;

						//���������б�����Ҫ��������Ʒ��ͼ(����ʣ��ʱ���ʣ������������)�����ı��
						UpdateQueueBlueprint(Index, QueueBlueprint);

						//���һ�θ���Ʒ���������������Ʒ�Լ���������
						CompleteCrafting(MyBlueprint, 1);
					}
					else
					{
						//���û�У��򽫸���Ʒ�������б����Ƴ���Ȼ�������������Ʒ������
						RemoveBlueprintFromQueue(Index);
						CompleteCrafting(MyBlueprint, 1);
					}


				}
			}
		}
	}
}

//ִ��ȡ���������һϵ�в�����������Ҫ������������Ʒ���������½�����뱳����֮�󽫱�ȡ����������Ʒ�������б����Ƴ�
void US_CraftingComponent::CancelCrafting(int32 IndexInQueue)
{
	int32 LocalIndex;
	LocalIndex = IndexInQueue;

	//�����������л�ȡ��ȡ����������Ʒ
	FS_STR_QueueBlueprint TempBlueprint;
	FCustomThunkTemplates::Array_Get(BlueprintsQueue, IndexInQueue, TempBlueprint);//��ȡ���Ǹ���

	TArray<FS_STR_Item> ReturnItem;

	//���ݴ���ı�ȡ����������Ʒ������������ȡ��Ҫ������֮ǰ��Ҫ�����ĵ���Ʒ
	CallMakeBlueprintRequiredItems(TempBlueprint.Blueprint, TempBlueprint.AmountRemaining, ReturnItem);

	//����������Ʒ���¼��뱳����
	CallTryAddItemsorDrop(ReturnItem);

    //�������б����Ƴ���ȡ����������Ʒ
	RemoveBlueprintFromQueue(LocalIndex);
}


//������Ҫ��������Ʒ����ͼ��������������У���󴴽�CraftingTick������ʱ�¼���ʼ��������������������б�
void US_CraftingComponent::AddBlueprintToQueue(FS_STR_Blueprint Blueprint, int32 Amount)
{
	FS_STR_QueueBlueprint TempQueue;

	//������ǰҪ��������Ʒ����ͼ����������Ҫ�������������͵�����Ʒ������ʣ��ʱ��
	TempQueue.Blueprint = Blueprint;
	TempQueue.AmountRemaining = Amount;
	TempQueue.TimeRemaining = Blueprint.RequiredTime;


	//����ǰ��Ҫ��������Ʒ��ͼ���������б�
	FCustomThunkTemplates::Array_Add(BlueprintsQueue, TempQueue);
	//��ȡ��ǰ�����б�ĳ���
	int32 ArrayLength = FCustomThunkTemplates::Array_Length(BlueprintsQueue);


	FTimerDynamicDelegate  Timer{};

	if (ArrayLength == 1)
	{
		Timer.BindUFunction(this, FName(TEXT("CraftingTick")));//�󶨺����������¼�

		//����һ����ʱ����ִ�к���ί��(CraftingTick)���������м�ʱ����ʹ�ø��µĲ������øü�ʱ����
		//TimerΪҪִ�е��¼���Ҳ����˵Ҫִ��CraftingTick������ CraftingTickTimeΪҪ��ִ��ί��֮ǰ�ȴ��೤ʱ�䣬����Ϊ��λ
		//True ��ʾÿ�� CraftingTickTime �����ִ��ί��,���ĸ�����Ϊ��ʼ�����ӳ٣�
		CraftingTickTimerHandle = UKismetSystemLibrary::K2_SetTimerDelegate(Timer, CraftingTickTime, true, 0.0f, 0.0f);

		//��������
		CCOnCraftingStarted();
	}

	for (APlayerController* ActivePlayer : ActivePlayers)
	{
		//����ÿ����ǰ��Ծ��ҵ������б�
		CallUpdateCraftingQueue_BPI(ActivePlayer);
	}

}

void US_CraftingComponent::AutoStartCrafting()
{
	int32 QueueLength;

	FS_STR_Blueprint LocalBlueprint;

	FTimerDynamicDelegate Timer{};


	//��ȡ��ͼ���г���
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

//���ÿɷ��������
void US_CraftingComponent::SetCraftingEnabled(bool Enable)
{
	CraftingEnabled = Enable;
}
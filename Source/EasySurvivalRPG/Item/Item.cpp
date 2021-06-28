// Easy Systems
#include "Item.h"
#include "ItemsLibrary.h"
 #include "Kismet/KismetSystemLibrary.h"



// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


//every Decay ticks will call the function
void AItem::DecayTick()
{
	//if (ItemData.Decay - 0.1 <= 0) {
	//	ItemData.Decay = ItemData.DecayTime;
	//	if (Amount - 1 == 0) {
	//		this->~AItem();
	//	}
	//	else {
	//		ItemData.Amount -= 1;
	//		if (ItemData.CanDecay) {
	//			bool itemDataIsValid{};
	//			UItemsLibrary::ItemIsValid(ItemData.ItemHandle, itemDataIsValid);

	//			if (ItemData.DecayItem.DataTable != nullptr &&
	//				itemDataIsValid) {
	//				UWorld* const World = GetWorld(); 
	//				if (World)
	//				{
	//					// added a new actor to the world
	//					World->SpawnActor<AItem>(
	//						this->GetActorTransform(),
	//						ItemData.ItemHandle, -1, -1, -1.0f, -1,
	//						this->SimulatePhysics, true, false
	//						);
	//				}
	//			}
	//		}
	//	}
	//}
	//else {
	//	ItemData.Decay -= 0.1;
	//}
	//bool bpfv__CallFunc_ItemCanDecay_CanDecay__pf{};
	//float bpfv__CallFunc_ItemCanDecay_Decay__pf{};
	//float bpfv__CallFunc_ItemCanDecay_DecayTime__pf{};
	//FDataTableRowHandle bpfv__CallFunc_ItemCanDecay_DecayItem__pf{};
	//bool bpfv__CallFunc_ItemHandleIsValid_IsValid__pf{};
	//bool bpfv__CallFunc_ItemCanDecay_CanDecay_1__pf{};
	//float bpfv__CallFunc_ItemCanDecay_Decay_1__pf{};
	//float bpfv__CallFunc_ItemCanDecay_DecayTime_1__pf{};
	//FDataTableRowHandle bpfv__CallFunc_ItemCanDecay_DecayItem_1__pf{};
	//float bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf{};
	//FTransform bpfv__CallFunc_GetTransform_ReturnValue__pf{};
	//AActor* bpfv__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf{};
	//bool bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue__pf{};
	//ABP_Item_C__pf364775414* bpfv__CallFunc_FinishSpawningActor_ReturnValue__pf{};
	//int32 bpfv__CallFunc_GetItemAmount_Amount__pf{};
	//int32 bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf{};
	//bool bpfv__CallFunc_EqualEqual_IntInt_ReturnValue__pf{};
	//int32 __CurrentState = 13;
	//do
	//{
	//	switch (__CurrentState)
	//	{
	//	case 13:
	//	{
	//	}
	//	case 1:
	//	{
	//		UDEPRECATED_BP_ItemsLibrary_C__pf2791831416::bpf__ItemCanDecay__pf(bpv__ItemData__pf, this, /*out*/ bpfv__CallFunc_ItemCanDecay_CanDecay_1__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_Decay_1__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_DecayTime_1__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_DecayItem_1__pf);
	//		bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Subtract_FloatFloat(bpfv__CallFunc_ItemCanDecay_Decay_1__pf, 0.100000);
	//		bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue__pf = UKismetMathLibrary::LessEqual_FloatFloat(bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf, 0.000000);
	//		if (!bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue__pf)
	//		{
	//			__CurrentState = 11;
	//			break;
	//		}
	//	}
	//	case 2:
	//	{
	//		UDEPRECATED_BP_ItemsLibrary_C__pf2791831416::bpf__ItemCanDecay__pf(bpv__ItemData__pf, this, /*out*/ bpfv__CallFunc_ItemCanDecay_CanDecay_1__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_Decay_1__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_DecayTime_1__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_DecayItem_1__pf);
	//		bpv__ItemData__pf.bpv__Decay_68_E490FBE7490669BCE570D8A5710506E6__pf = bpfv__CallFunc_ItemCanDecay_DecayTime_1__pf;
	//	}
	//	case 3:
	//	{
	//		auto __Local__16 = FDEPRECATED_STR_ItemData__pf2029040651{};
	//		UDEPRECATED_BP_ItemsLibrary_C__pf2791831416::bpf__GetItemAmount__pf(__Local__16, this, /*out*/ bpfv__CallFunc_GetItemAmount_Amount__pf);
	//		bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf = UKismetMathLibrary::Subtract_IntInt(bpfv__CallFunc_GetItemAmount_Amount__pf, 1);
	//		bpfv__CallFunc_EqualEqual_IntInt_ReturnValue__pf = UKismetMathLibrary::EqualEqual_IntInt(bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf, 0);
	//		if (!bpfv__CallFunc_EqualEqual_IntInt_ReturnValue__pf)
	//		{
	//			__CurrentState = 12;
	//			break;
	//		}
	//	}
	//	case 4:
	//	{
	//		K2_DestroyActor();
	//	}
	//	case 5:
	//	{
	//		UItemsLibrary::ItemCanDecay(bpv__ItemData__pf, this, /*out*/ bpfv__CallFunc_ItemCanDecay_CanDecay__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_Decay__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_DecayTime__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_DecayItem__pf);
	//		UDEPRECATED_BP_ItemsLibrary_C__pf2791831416::bpf__ItemHandleIsValid__pf(bpfv__CallFunc_ItemCanDecay_DecayItem__pf, this, /*out*/ bpfv__CallFunc_ItemHandleIsValid_IsValid__pf);
	//		if (!bpfv__CallFunc_ItemHandleIsValid_IsValid__pf)
	//		{
	//			__CurrentState = -1;
	//			break;
	//		}
	//	}
	//	case 6:
	//	{
	//		bpfv__CallFunc_GetTransform_ReturnValue__pf = AActor::GetTransform();
	//		bpfv__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, GetClass(), bpfv__CallFunc_GetTransform_ReturnValue__pf, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn, ((AActor*)nullptr));
	//	}
	//	case 7:
	//	{
	//		UDEPRECATED_BP_ItemsLibrary_C__pf2791831416::bpf__ItemCanDecay__pf(bpv__ItemData__pf, this, /*out*/ bpfv__CallFunc_ItemCanDecay_CanDecay__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_Decay__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_DecayTime__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_DecayItem__pf);
	//		FCustomThunkTemplates::SetStructurePropertyByName(bpfv__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf, FName(TEXT("ItemHandle")), bpfv__CallFunc_ItemCanDecay_DecayItem__pf);
	//	}
	//	case 8:
	//	{
	//		UKismetSystemLibrary::SetIntPropertyByName(bpfv__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf, FName(TEXT("Amount")), 1);
	//	}
	//	case 9:
	//	{
	//		UKismetSystemLibrary::SetBoolPropertyByName(bpfv__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf, FName(TEXT("SimulatePhysics")), bpv__SimulatePhysics__pf);
	//	}
	//	case 10:
	//	{
	//		bpfv__CallFunc_GetTransform_ReturnValue__pf = AActor::GetTransform();
	//		bpfv__CallFunc_FinishSpawningActor_ReturnValue__pf = CastChecked<ABP_Item_C__pf364775414>(UGameplayStatics::FinishSpawningActor(bpfv__CallFunc_BeginDeferredActorSpawnFromClass_ReturnValue__pf, bpfv__CallFunc_GetTransform_ReturnValue__pf), ECastCheckedType::NullAllowed);
	//		__CurrentState = -1;
	//		break;
	//	}
	//	case 11:
	//	{
	//		UDEPRECATED_BP_ItemsLibrary_C__pf2791831416::bpf__ItemCanDecay__pf(bpv__ItemData__pf, this, /*out*/ bpfv__CallFunc_ItemCanDecay_CanDecay_1__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_Decay_1__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_DecayTime_1__pf, /*out*/ bpfv__CallFunc_ItemCanDecay_DecayItem_1__pf);
	//		bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Subtract_FloatFloat(bpfv__CallFunc_ItemCanDecay_Decay_1__pf, 0.100000);
	//		bpv__ItemData__pf.bpv__Decay_68_E490FBE7490669BCE570D8A5710506E6__pf = bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf;
	//		__CurrentState = -1;
	//		break;
	//	}
	//	case 12:
	//	{
	//		auto __Local__17 = FDEPRECATED_STR_ItemData__pf2029040651{};
	//		UDEPRECATED_BP_ItemsLibrary_C__pf2791831416::bpf__GetItemAmount__pf(__Local__17, this, /*out*/ bpfv__CallFunc_GetItemAmount_Amount__pf);
	//		bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf = UKismetMathLibrary::Subtract_IntInt(bpfv__CallFunc_GetItemAmount_Amount__pf, 1);
	//		bpv__ItemData__pf.bpv__Amount_63_A266101D46331E1C405B5BBCCD66B5AB__pf = bpfv__CallFunc_Subtract_IntInt_ReturnValue__pf;
	//		__CurrentState = 5;
	//		break;
	//	}
	//	default:
	//		break;
	//	}
	//} while (__CurrentState != -1);
}

void AItem::DestoryItem()
{

}

void AItem::PlayDropSound_Implementation() {

}

void AItem::ConstructionInit()
{
	//FSTR_ItemInstance* item = ItemHandle.DataTable.FindRow<AItem>(ItemHandle.RowName);
	////not exists;
	//if (!item) {
	//	if (this->HasAuthority()) {
	//		KismetSystemLibrary::PrintText("Item <<" + ItemHandle.RowName.ToString() + ">> not found on the table");
	//	}
	//}
	//else {
	//	if (IsValid(item)) {
	//		if (this->Amount < 0) {
	//			this->Amount = item->MaxStack;
	//		}
	//		if (this->Charges < 0) {
	//			this->Charges = 0;
	//		}
	//		if (this->Durability < 0) {
	//			this->Amount = item->MaxDurability;
	//		}
	//		if (this->Decay < 0 && CanDecay) {
	//			this->Decay = item->DecayTime;
	//		}
	//		else {
	//			this->Decay = 0;
	//		}

	//		STR_ItemData* ItemData = UItemsLibrary::MakeItem(item,
	//			this->Amount, this->Charges, this->Durability, this->Decay);
	//		this->ItemData = ItemData;
	//		this->StaticMesh = ItemData->StaticMesh;
	//		this->StaticMesh->SetSimulatePhysics(SimulatePhysics);
	//	}
	//}
}

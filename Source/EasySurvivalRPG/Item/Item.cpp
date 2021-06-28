// Easy Systems
#include "Item.h"
#include "ItemsLibrary.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetTextLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "GeneratedCodeHelpers.h" 
// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
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
	if (ItemData.Decay - 0.1 <= 0) {
		ItemData.Decay = ItemData.DecayTime;
		if (Amount - 1 == 0) {
			K2_DestroyActor();
		}
		else {
			ItemData.Amount -= 1;
			if (ItemData.CanDecay) {
				bool itemDataIsValid{};
				
				UItemsLibrary::ItemIsValid(ItemData, nullptr, itemDataIsValid);

				if (ItemData.DecayItem.DataTable != nullptr &&
					itemDataIsValid) {
					auto trans = AActor::GetTransform();
					auto actorSpawn = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, GetClass(), trans, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn, ((AActor*)nullptr));
					CastChecked<AItem>(UGameplayStatics::FinishSpawningActor(actorSpawn, trans), ECastCheckedType::NullAllowed);

				}
			}
		}
	}
	else {
		ItemData.Decay -= 0.1;
	}
}

void AItem::DestoryItem()
{

}

void AItem::PlayDropSound_Implementation() {

}

void AItem::ConstructionInit()
{
	FSTR_ItemInstance* item{};

	FCustomThunkTemplates::GetDataTableRowFromName(const_cast<UDataTable*>(ItemHandle.DataTable), ItemHandle.RowName, 
		item);
	//not exists;
	if (!item) {
		if (this->HasAuthority()) {
			auto text = UKismetTextLibrary::Conv_NameToText(ItemHandle.RowName);
			FFormatArgumentData formatArgumentData{};
			TArray<FFormatArgumentData> formatArray{};
			formatArgumentData.ArgumentName = FString(TEXT("ID"));
			formatArgumentData.ArgumentValueType = EFormatArgumentType::Text;
			formatArgumentData.ArgumentValue = text;
			formatArgumentData.ArgumentValueInt = 0;
			formatArgumentData.ArgumentValueFloat = 0.000000;
			formatArgumentData.ArgumentValueGender = ETextGender::Masculine;
			formatArray.SetNum(1, true);
			formatArray[0] = formatArgumentData;
			auto format = UKismetTextLibrary::Format(FTextStringHelper::CreateFromBuffer(
				TEXT("Item << {ID} >> does not found in data table!\")")), formatArray);
			UKismetSystemLibrary::PrintText(this, format, true, true, FLinearColor(1.000000, 0.000000, 0.000000, 1.000000), 5.000000);
		}
	}
	else {
		if (IsValid(this)) {
			if (this->Amount < 0) {
				this->Amount = item->MaxStack;
			}
			if (this->Charges < 0) {
				this->Charges = 0;
			}
			if (this->Durability < 0) {
				this->Amount = item->MaxDurability;
			}
			if (this->Decay < 0 && CanDecay) {
				this->Decay = item->DecayTime;
			}
			else {
				this->Decay = 0;
			}

			UItemsLibrary::MakeItem(*item,
				this->Amount, this->Charges, this->Durability, this->Decay, nullptr,
				this->ItemData);

			UStaticMesh* meshResult{};
			UItemsLibrary::GetItemDropMesh(this->ItemData, this, 
				meshResult);
			if (IsValid(this->StaticMesh))
			{
				this->StaticMesh->SetStaticMesh(meshResult);
			}

			this->StaticMesh->SetSimulatePhysics(SimulatePhysics);
		}
	}
}

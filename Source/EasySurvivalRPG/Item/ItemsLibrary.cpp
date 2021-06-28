// Easy Systems


#include "ItemsLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "GeneratedCodeHelpers.h"

bool UItemsLibrary::ItemHandle(FDataTableRowHandle itemHandle) {
	return itemHandle.RowName != "None" &&
		IsValid(itemHandle.DataTable);
}

void UItemsLibrary::ItemIsValid(FSTR_ItemData Item, UObject* WorldContext, 
	/*输出*/ bool& IsValid)
{
	IsValid = UKismetMathLibrary::NotEqual_NameName(Item.ItemHandle.RowName, FName(TEXT("None")));
}

void UItemsLibrary::ItemInstanceIsValid(FSTR_ItemInstance ItemInstance, UObject* WorldContext,
	/*输出*/ bool& IsValid)
{
	IsValid = UKismetMathLibrary::NotEqual_NameName(ItemInstance.ItemHandle.RowName, FName(TEXT("None")));
}

//void UItemsLibrary::GetItemDropMesh(FSTR_ItemData Item, UObject* WorldContext,
//	/*输出*/ UStaticMesh*& StaticMesh)
//{
//	TArray<UStaticMesh*> staticMeshes;
//	UStaticMesh* resMesh;
//	staticMeshes.Reset();
//
//	FCustomThunkTemplates::Map_Values(Item.StaticMeshes, 
//		staticMeshes);
//
//	FCustomThunkTemplates::Array_Get(staticMeshes, 0,
//		resMesh);
//
//	StaticMesh = resMesh;
//}
//
//void UItemsLibrary::GetItemIcon(FSTR_ItemData Item, UObject* WorldContext, 
//	/*输出*/ UTexture2D*& Icon)
//{
//	Icon = Item.Icon;
//}
//
//void UItemsLibrary::GetItemAmount(FSTR_ItemData Item, UObject* WorldContext, 
//	/*输出*/ int32& Amount)
//{
//	Amount = Item.Amount;
//}
//
////unimplemented.
//void UItemsLibrary::MakeItem(FSTR_ItemInstance ItemInstance, int32 Amount, int32 Charges, float Durability, float Decay, UObject* WorldContext,
//	/*输出*/ FSTR_ItemData& Item)
//{
//
//	//float bpfv__CallFunc_MakeItemDecay_ResultDecay__pf{};
//	//float bpfv__CallFunc_MakeItemDurability_ResultDurability__pf{};
//	//int32 bpfv__CallFunc_MakeItemCharges_ResultCharges__pf{};
//	//int32 bpfv__CallFunc_MakeItemAmount_ResultAmount__pf{};
//	//FSTR_ItemData bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf{};
//	//UBP_ItemsLibrary_C__pf2791831416::bpf__MakeItemDecay__pf(bpp__ItemInstance__pf, bpp__Decay__pf, bpp____WorldContext__pf, /*out*/ bpfv__CallFunc_MakeItemDecay_ResultDecay__pf);
//	//UBP_ItemsLibrary_C__pf2791831416::bpf__MakeItemDurability__pf(bpp__ItemInstance__pf, bpp__Durability__pf, bpp____WorldContext__pf, /*out*/ bpfv__CallFunc_MakeItemDurability_ResultDurability__pf);
//	//UBP_ItemsLibrary_C__pf2791831416::bpf__MakeItemCharges__pf(bpp__ItemInstance__pf, bpp__Charges__pf, bpp____WorldContext__pf, /*out*/ bpfv__CallFunc_MakeItemCharges_ResultCharges__pf);
//	//UBP_ItemsLibrary_C__pf2791831416::bpf__MakeItemAmount__pf(bpp__ItemInstance__pf, bpp__Amount__pf, bpp____WorldContext__pf, /*out*/ bpfv__CallFunc_MakeItemAmount_ResultAmount__pf);
//	//
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__ItemHandle_60_EFC3446F4BEB3A00026CE2A9EAC341F7__pf = bpp__ItemInstance__pf.bpv__ItemHandle_60_EFC3446F4BEB3A00026CE2A9EAC341F7__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__Amount_63_A266101D46331E1C405B5BBCCD66B5AB__pf = bpfv__CallFunc_MakeItemAmount_ResultAmount__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__Charges_71_A809A459457F6D92E0E74AB2D742ADB8__pf = bpfv__CallFunc_MakeItemCharges_ResultCharges__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__Durability_66_D195200D4BAEAC1676AF609078EDE41E__pf = bpfv__CallFunc_MakeItemDurability_ResultDurability__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__Decay_68_E490FBE7490669BCE570D8A5710506E6__pf = bpfv__CallFunc_MakeItemDecay_ResultDecay__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__Name_6_4BDAD3B24B564228353D28A42C703448__pf = bpp__ItemInstance__pf.bpv__Name_6_4BDAD3B24B564228353D28A42C703448__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__Description_8_4DA029524B4A3B9B74B569AF7F7F5DB0__pf = bpp__ItemInstance__pf.bpv__Description_8_4DA029524B4A3B9B74B569AF7F7F5DB0__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__Icon_11_F8EF38624C72890DA50093880E07917C__pf = bpp__ItemInstance__pf.bpv__Icon_11_F8EF38624C72890DA50093880E07917C__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__ItemClass_14_AA51AFF34BD012A351C36281D08F9B78__pf = bpp__ItemInstance__pf.bpv__ItemClass_14_AA51AFF34BD012A351C36281D08F9B78__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__MaxStack_17_A4F940864DC6C3A24983778907BB130E__pf = bpp__ItemInstance__pf.bpv__MaxStack_17_A4F940864DC6C3A24983778907BB130E__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__MaxCharges_73_357A31704B4E589ACF82A18CD67D16E3__pf = bpp__ItemInstance__pf.bpv__MaxCharges_63_D792FD1F4FDC22176F4DA8BAC079893A__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__MaxDurability_20_1F5A413E4DE4565794CBD38CAAF2CAD9__pf = bpp__ItemInstance__pf.bpv__MaxDurability_20_1F5A413E4DE4565794CBD38CAAF2CAD9__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__StaticMeshes_25_A44D2C0C4E832E870564D19516B88B6C__pf = bpp__ItemInstance__pf.bpv__StaticMeshes_25_A44D2C0C4E832E870564D19516B88B6C__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__SkeletalMeshes_28_87099CA448794492DB1D77A7109F9F85__pf = bpp__ItemInstance__pf.bpv__SkeletalMeshes_28_87099CA448794492DB1D77A7109F9F85__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__Sounds_31_76D5931E49F01DCACD53A7AF5063E60D__pf = bpp__ItemInstance__pf.bpv__Sounds_31_76D5931E49F01DCACD53A7AF5063E60D__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__Handles_79_D505B92D40B7AE8A2E9A87956B714B48__pf = bpp__ItemInstance__pf.bpv__Handles_68_3096FD37466273FC863D41933A1A1E1C__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__ItemTags_35_3503C2784ACEE59E3DACB1B8942FF342__pf = bpp__ItemInstance__pf.bpv__ItemTags_35_3503C2784ACEE59E3DACB1B8942FF342__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__CostValue_38_AA83680B4E31011115A326BE65A10D1F__pf = bpp__ItemInstance__pf.bpv__CostValue_38_AA83680B4E31011115A326BE65A10D1F__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__EquipmentAttributes_42_EA72711E462B319EAEF758964FF2416D__pf = bpp__ItemInstance__pf.bpv__EquipmentAttributes_42_EA72711E462B319EAEF758964FF2416D__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__CanDecay_46_96E3158549B32F3C6EEBCCAC8295D6F7__pf = bpp__ItemInstance__pf.bpv__CanDecay_46_96E3158549B32F3C6EEBCCAC8295D6F7__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__DecayTime_49_86CE08D946E11088D8954BB60A4A0B52__pf = bpp__ItemInstance__pf.bpv__DecayTime_49_86CE08D946E11088D8954BB60A4A0B52__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__DecayItem_52_161D62BC415C10968590E3A537C23426__pf = bpp__ItemInstance__pf.bpv__DecayItem_52_161D62BC415C10968590E3A537C23426__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__Weight_55_C78AF7A54A57615655795E9CE6AAF111__pf = bpp__ItemInstance__pf.bpv__Weight_55_C78AF7A54A57615655795E9CE6AAF111__pf;
//	//bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf.bpv__UseAbilityClass_58_C99871DC465C861810BA07B35CF2FD7F__pf = bpp__ItemInstance__pf.bpv__UseAbilityClass_58_C99871DC465C861810BA07B35CF2FD7F__pf;
//	//bpp__Item__pf = bpfv__K2Node_MakeStruct_DEPRECATED_STR_ItemData__pf;
//}

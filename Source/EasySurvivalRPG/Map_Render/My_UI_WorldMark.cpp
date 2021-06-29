// Easy Systems


#include "My_UI_WorldMark.h"
#include"Kismet/KismetTextLibrary.h"
#include"GeneratedCodeHelpers.h"


//设置图像
void UMy_UI_WorldMark::SetIcon(UTexture2D* Texture)
{
	if (::IsValid(MyMarkIcon))
	{
		MyMarkIcon->SetBrushFromTexture(Texture, false);
	}
}


void UMy_UI_WorldMark::SetDistanceVisibility(bool Visible)
{
	bool MyVisible;
	ESlateVisibility IsVisible;
	ESlateVisibility IsCollapsed;
	//ESlateVisibility DefaultSelect;

	MyVisible = Visible;

	IsVisible = ESlateVisibility::Visible;
	IsCollapsed = ESlateVisibility::Collapsed;

	/*
	if (::IsValid(MyDistanceText))
	{
		MyDistanceText->SetVisibility(
			TSwitchValue<bool, ESlateVisibility >
			(MyVisible, DefaultSelect, 2, TSwitchPair<bool, ESlateVisibility >(false, IsCollapsed), 
			TSwitchPair<bool, ESlateVisibility >(true, IsVisible)));
	}*/

	if (::IsValid(MyDistanceText))
	{
		if (MyVisible)
		{
			MyDistanceText->SetVisibility(IsVisible);
		}
		else
		{
			MyDistanceText->SetVisibility(IsCollapsed);
		}
	}

}



void UMy_UI_WorldMark::SetDistance(float Distance)
{
	FFormatArgumentData Struct_FormatArgumentData1;
	FFormatArgumentData Struct_FormatArgumentData2;
	TArray<FFormatArgumentData> Struct_FormatArgumentData1Array;
	TArray<FFormatArgumentData> Struct_FormatArgumentData2Array;

	float Distance1 = Distance / 100;

	float Distance2 = Distance1 / 1000;

	//浮点转换为文本
	FText text1 = UKismetTextLibrary::Conv_FloatToText(Distance1, ERoundingMode::HalfToEven, false, true, 1, 324, 0, 0);
	FText text2 = UKismetTextLibrary::Conv_FloatToText(Distance2, ERoundingMode::HalfToEven, false, true, 1, 324, 1, 0);

	//格式化文本1，设置参数
	Struct_FormatArgumentData1.ArgumentName = FString(TEXT("Distance"));
	Struct_FormatArgumentData1.ArgumentValueType = EFormatArgumentType::Text;
	Struct_FormatArgumentData1.ArgumentValue = text1;
	Struct_FormatArgumentData1.ArgumentValueInt = 0;
	Struct_FormatArgumentData1.ArgumentValueFloat = 0.000000;
	Struct_FormatArgumentData1.ArgumentValueGender = ETextGender::Masculine;


	Struct_FormatArgumentData1Array.SetNum(1, true);
	Struct_FormatArgumentData1Array[0] = Struct_FormatArgumentData2;

    FText Ftext1= UKismetTextLibrary::Format(FTextStringHelper::CreateFromBuffer(
		TEXT("NSLOCTEXT(\"[34757D054E43E64028441FAD98A7CFAE]\", \"647E9C944039E8ED0393398AAF792060\", \"{Distance} m\")")), Struct_FormatArgumentData1Array);

	//格式化文本2，设置参数
	Struct_FormatArgumentData2.ArgumentName = FString(TEXT("Distance"));
	Struct_FormatArgumentData2.ArgumentValueType = EFormatArgumentType::Text;
	Struct_FormatArgumentData2.ArgumentValue = text2;
	Struct_FormatArgumentData2.ArgumentValueInt = 0;
	Struct_FormatArgumentData2.ArgumentValueFloat = 0.000000;
	Struct_FormatArgumentData2.ArgumentValueGender = ETextGender::Masculine;


	Struct_FormatArgumentData2Array.SetNum(1, true);
	Struct_FormatArgumentData2Array[0] = Struct_FormatArgumentData2;

	FText Ftext2 = UKismetTextLibrary::Format(FTextStringHelper::CreateFromBuffer(
		TEXT("NSLOCTEXT(\"[34757D054E43E64028441FAD98A7CFAE]\", \"DE8867554170DFA24F3DFE850DAF8F90\", \"{Distance} km\")")), Struct_FormatArgumentData2Array);

	if (Distance1 >= 1.0)
	{
		if (Distance1 < 1000.0)
		{
			if(::IsValid(MyDistanceText))
				MyDistanceText->SetText(Ftext1);
		}
		else
		{
			if (::IsValid(MyDistanceText))
				MyDistanceText->SetText(Ftext2);
		}
	}
	else
	{
		//将文本设置为空
		if (::IsValid(MyDistanceText))
			MyDistanceText->SetText(FText::GetEmpty());
	}

}


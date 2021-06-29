// Easy Systems


#include "S_Map_RenderActor.h"
#include"Kismet/KismetArrayLibrary.h"
#include"GeneratedCodeHelpers.h"
#include "Engine/World.h"
#include"Kismet/GameplayStatics.h"
#include"Kismet/KismetMathLibrary.h"

// Sets default values
AS_Map_RenderActor::AS_Map_RenderActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	MyRenderArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MyRenderArm"));
	MyMapSceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("MyMapSceneCapture"));
	//MyMapSceneCapture2 = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("MyMapSceneCapture"));

	TargetActor = CreateDefaultSubobject<AActor>(TEXT("TargetActor"));

	SelectedActor = CreateDefaultSubobject<AActor>(TEXT("SelectedActor"));

	SelectedMapSprite = CreateDefaultSubobject<AActor>(TEXT("SelectedMapSprite"));

	SetRootComponent(Root);
	MyMapSceneCapture->SetupAttachment(MyRenderArm);
	MyRenderArm->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AS_Map_RenderActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AS_Map_RenderActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AS_Map_RenderActor::SetRenderLocation(FVector NewLocation)
{
	if (MapIsOpen)
	{
		if (ClampRender)
		{
			float Width = CurrentRenderWidth / 2;
			float CurrentX = NewLocation.X;
			float CurrentY = NewLocation.Y;

			FVector ActorLocation;

			if (Width < CurrentX && Width < CurrentY)
			{
				FVector JundgeVector = SelectedMapBoxExtent - CurrentRenderWidth / 2;

				ActorLocation.X = NewLocation.X;

				if (ActorLocation.X < (SelectedMapBoxOrigin.X - JundgeVector.X))
					ActorLocation.X = SelectedMapBoxOrigin.X - JundgeVector.X;

				if (ActorLocation.X > (SelectedMapBoxOrigin.X + JundgeVector.X))
					ActorLocation.X = SelectedMapBoxOrigin.X + JundgeVector.X;


				ActorLocation.Y = NewLocation.Y;
				if (ActorLocation.Y < (SelectedMapBoxOrigin.Y - JundgeVector.Y))
					ActorLocation.Y = SelectedMapBoxOrigin.Y - JundgeVector.Y;

				if (ActorLocation.Y > (SelectedMapBoxOrigin.Y + JundgeVector.Y))
					ActorLocation.Y = SelectedMapBoxOrigin.Y + JundgeVector.Y;



				ActorLocation.Z = NewLocation.Z;
				//K2_SetActorLocation(NewLocation, false, NONE, true);
				SetActorLocation(NewLocation, false, nullptr, TeleportFlagToEnum(true));

			}
			else
			{

				ActorLocation.X = SelectedMapBoxOrigin.X;
				ActorLocation.Y = SelectedMapBoxOrigin.Y;
				ActorLocation.Z = NewLocation.Z;
				SetActorLocation(NewLocation, false, nullptr, TeleportFlagToEnum(true));
			}


		}
		else
		{
			SetActorLocation(NewLocation, false, nullptr, TeleportFlagToEnum(true));
		}

	}
	else
	{
		SetActorLocation(NewLocation, false, nullptr, TeleportFlagToEnum(true));
		//TeleportPhysics
	}
}


void AS_Map_RenderActor::SetRenderWidth(float Width, bool Clamp)
{
	float W = Width;

	if (Clamp)
	{

		if (Width < MinRenderWidth)
			W = MinRenderWidth;
		if (Width > MaxRenderWidth)
			W = MaxRenderWidth;

		MyMapSceneCapture->OrthoWidth = W;

		CurrentRenderWidth = MyMapSceneCapture->OrthoWidth;

		SetRenderLocation(GetActorLocation());

	}
	else
	{
		MyMapSceneCapture->OrthoWidth = W;
	}

	CurrentRenderWidth = MyMapSceneCapture->OrthoWidth;
	SetRenderLocation(GetActorLocation());
}


void AS_Map_RenderActor::UpdateLocation()
{
	FVector NewLocation;
	if (FollowToTarget)
	{
		NewLocation = TargetActor->GetActorLocation();
		SetRenderLocation(NewLocation);
	}
	else
	{

		UWorld* world = GetWorld();

		if (IsValid(SelectedActor))
		{
			NewLocation = UKismetMathLibrary::VInterpTo(K2_GetActorLocation(), SelectedActor->K2_GetActorLocation(), world->GetDeltaSeconds(), 5.0);
			SetRenderLocation(NewLocation);
		}

	}
}

//设置FollowTarget
void AS_Map_RenderActor::SetFollowToTarget(bool FollowTarget)
{
	FollowToTarget = FollowTarget;
	SelectedActor = ((AActor*)nullptr);
}

void AS_Map_RenderActor::UpdateRenderMode()
{
	int32 CurrentState = 2;
	do
	{
		switch (CurrentState)
		{
		case 2:
		{

		}
		case 1:
		{
			if (!RenderOnlySprite)
			{
				CurrentState = -1;
				break;
			}
			CurrentState = -1;
			break;
		}
		default:
			break;
		}
	} while (CurrentState != -1);
}

//设置SelectedActor
void AS_Map_RenderActor::SetSelectedActor(AActor* Actor)
{
	SelectedActor = Actor;
}

//改变渲染偏移量
void AS_Map_RenderActor::ChangeRenderOffset(FVector DeltaLocation)
{
	FVector newLocation;

	newLocation = K2_GetActorLocation() + DeltaLocation;

	SetRenderLocation(newLocation);
}

//更新渲染宽度
void AS_Map_RenderActor::ChangeRenderWidth(float DeltaWidth)
{
	float width;

	width = CurrentRenderWidth - DeltaWidth;

	SetRenderWidth(width, true);
}

//渲染层级纹理
void AS_Map_RenderActor::RenderMinimap()
{
	MapIsOpen = false;

	SetFollowToTarget(true);

	SetRenderWidth(MinimapRenderWidth, false);
}

//渲染纹理
void AS_Map_RenderActor::RenderMap()
{
	MapIsOpen = false;

	SetFollowToTarget(true);

	SetRenderWidth(MapRenderWidth, false);
}


void AS_Map_RenderActor::AddActorToRenderList(AActor * Actor, bool & Success)
{

	int32 ArrayValue;

	TArray<AActor*>  ActorArray = {};

	if (ClampRender)
	{
		FVector ActorLocation;
		if (::IsValid(Actor))
		{
			ActorLocation = Actor->GetActorLocation();
		}
		
		bool IsPointInBox = UKismetMathLibrary::IsPointInBox(ActorLocation, SelectedMapBoxOrigin, SelectedMapBoxExtent);

		if (IsPointInBox)
		{

			if (::IsValid(MyMapSceneCapture))
			{
				ArrayValue = FCustomThunkTemplates::Array_AddUnique(MyMapSceneCapture->ShowOnlyActors, Actor);
				//ArrayValue = UKismetArrayLibrary::Array_AddUnique(MyMapSceneCapture->ShowOnlyActors,)
			}
			else
			{
				ArrayValue = FCustomThunkTemplates::Array_AddUnique(ActorArray, Actor);
			}

			Success = true;
		}
		else
		{
			Success = false;
		}
	}
	else
	{
		
		if (::IsValid(MyMapSceneCapture))
		{
			ArrayValue = FCustomThunkTemplates::Array_AddUnique(MyMapSceneCapture->ShowOnlyActors, Actor);
		}
		else
		{
			ArrayValue = FCustomThunkTemplates::Array_AddUnique(ActorArray, Actor);
		}

		Success = true;
	}


}

/*
void AS_Map_RenderActor::SetRenderSettings(AActor * MapSpriteActor, bool ClampRenderLocation, FVector lampBoxOrigin, FVector lampBoxExtent)
{
	bool success;//作为返回的引用参数表达式使用；

	if (::IsValid(MapSpriteActor))
	{
		SelectedMapSprite = MapSpriteActor;
	}

	ClampRender = ClampRenderLocation;

	SelectedMapBoxOrigin = lampBoxOrigin;

	SelectedMapBoxExtent = lampBoxExtent;

	//UKismetArrayLibrary::Array_AddUnique();

	//UKismetArrayLibrary::Array_Clear(MyMapSceneCapture->ShowOnlyActors);
	FCustomThunkTemplates::Array_Clear(MyMapSceneCapture->ShowOnlyActors);

	if (::IsValid(SelectedMapSprite))
	{
		AddActorToRenderList(SelectedMapSprite, success);//success后不加{}会报错
		if (::IsValid(MyMapSceneCapture))
		{
			MyMapSceneCapture->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
		}
	}
	else
	{
		if (::IsValid(MyMapSceneCapture))
		{
			MyMapSceneCapture->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_LegacySceneCapture;
		}
	}
}*/


void AS_Map_RenderActor::ClearMapSelection()
{
	ClampRender = false;

	FCustomThunkTemplates::Array_Clear(MyMapSceneCapture->ShowOnlyActors);

}
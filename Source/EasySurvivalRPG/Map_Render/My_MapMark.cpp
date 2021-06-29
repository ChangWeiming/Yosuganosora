// Easy Systems


#include "My_MapMark.h"
#include"Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AMy_MapMark::AMy_MapMark()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	TargetActor = CreateDefaultSubobject<AActor>(TEXT("TargetActor"));
	
	//创建组件；
	S_SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("S_SceneRoot"));
	
	S_MapWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("S_MapWidget"));
	S_WorldWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("S_WorldWidget"));
	S_Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("S_Billboard"));

	SetRootComponent(S_SceneRoot);
	S_MapWidget->SetupAttachment(S_SceneRoot);
	S_WorldWidget->SetupAttachment(S_SceneRoot);
	S_Billboard->SetupAttachment(S_SceneRoot);

	


}

// Called when the game starts or when spawned
void AMy_MapMark::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMy_MapMark::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMy_MapMark::TryAttachToTarget()
{
	bool ISVALID = ::IsValid(TargetActor);

	if(ISVALID)
	{
		AActor::K2_AttachToActor(TargetActor, "",EAttachmentRule::SnapToTarget, 
			EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
	}

}

void AMy_MapMark::Detach()
{
	AActor::K2_DetachFromActor(EDetachmentRule::KeepWorld, 
		EDetachmentRule::KeepWorld, EDetachmentRule::KeepRelative);

}

void AMy_MapMark::SetMapIsOpen(bool IsOpen)
{
	MapIsOpen = IsOpen;

	if (MapIsOpen)
	{
		FRotator Rotation = FRotator(0.0, 180.0, 0.0);
		AActor::K2_SetActorRotation(Rotation, true);

		S_MapWidget->SetHiddenInGame(!ShowMapMark, false);
	}
	else
	{
		S_MapWidget->SetHiddenInGame(!ShowMinimapMark, false);
	}
}

void AMy_MapMark::UpdateMarkLocation()
{
	bool IsTargetctorValid = ::IsValid(TargetActor);

	FHitResult SweepHitResult{};

	if (IsTargetctorValid)
	{
		FVector NewLocaion = TargetActor->K2_GetActorLocation();

		AActor::K2_SetActorLocation(NewLocaion, false, SweepHitResult,true);
	}

}

void AMy_MapMark::UpdateWorldMark()
{
	if (ShowWorldMark)
	{
		if (ShowDistance)
		{
			WorldWidgetReference->SetDistance(Distance);
		}
	}
}

void AMy_MapMark::UpdateMarkDistance(ACharacter * Character)
{
	if (ShowDistance)
	{
		FVector Chara_Location = Character->K2_GetActorLocation();

		FVector Actor_Location = AActor::K2_GetActorLocation();

		FVector NewLocation = Chara_Location - Actor_Location;

		float Length = UKismetMathLibrary::VSize(NewLocation);

		Distance = Length;
	}

}

void AMy_MapMark::UpdateMapMark()
{
	if (ShowMinimapMark || ShowMapMark)
	{
		if (::IsValid(MapWidgetReference))
		{
			if (ShowDistance)
			{
				MapWidgetReference->SetDistance(Distance);
			}

			if (::IsValid(TargetActor))
			{
				if (RotateMark)
				{
					FRotator TargetRotation;

					float TargetRoll;
					float TargetPitch;
					float TargetYaw;

					TargetRotation = TargetActor->K2_GetActorRotation();

					//拆分旋转体
					UKismetMathLibrary::BreakRotator(TargetRotation, TargetRoll,TargetPitch,TargetYaw);

					float NewYaw = TargetYaw + 180.0f;
					FRotator NewRotater = UKismetMathLibrary::MakeRotator(0.0f, 0.0f, NewYaw);

					//为Actor设置新的旋转体
					AActor::K2_SetActorRotation(NewRotater, true);
				}
				else
				{
					if (!MapIsOpen)
					{
						APlayerController* PlayerController;
						PlayerController = UGameplayStatics::GetPlayerController(this, 0);

						if (::IsValid(PlayerController->PlayerCameraManager) && ::IsValid(PlayerController->PlayerCameraManager))
						{
							FRotator CameraRotation = PlayerController->PlayerCameraManager->K2_GetActorRotation();

							float CameraRoll;
							float CameraPitch;
							float CameraYaw;

							UKismetMathLibrary::BreakRotator(CameraRotation, CameraRoll, CameraPitch, CameraYaw);

							float NewCameraYaw = CameraYaw + 180.0f;
							FRotator CameraRotater = UKismetMathLibrary::MakeRotator(0.0f, 0.0f, NewCameraYaw);

							//为Actor设置新的旋转体
							AActor::K2_SetActorRotation(CameraRotater, true);

						}

					}
				}
			}
			else
			{
				if (!MapIsOpen)
				{
					APlayerController* PlayerController;
					PlayerController = UGameplayStatics::GetPlayerController(this, 0);

					if (::IsValid(PlayerController->PlayerCameraManager) && ::IsValid(PlayerController->PlayerCameraManager))
					{
						FRotator CameraRotation = PlayerController->PlayerCameraManager->K2_GetActorRotation();

						float CameraRoll;
						float CameraPitch;
						float CameraYaw;

						UKismetMathLibrary::BreakRotator(CameraRotation, CameraRoll, CameraPitch, CameraYaw);

						float NewCameraYaw = CameraYaw + 180.0f;
						FRotator CameraRotater = UKismetMathLibrary::MakeRotator(0.0f, 0.0f, NewCameraYaw);

						//为Actor设置新的旋转体
						AActor::K2_SetActorRotation(CameraRotater, true);

					}

				}
			}

		}
	}
}


void AMy_MapMark::UpdateMarkVisibility_Implementation()
{

}

void AMy_MapMark::UpdateMark_Implementation()
{
}
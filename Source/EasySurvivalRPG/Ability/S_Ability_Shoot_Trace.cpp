// Easy Systems


#include "S_Ability_Shoot_Trace.h"
#include "Kismet/GameplayStatics.h"
#include "K2Node_CreateDelegate.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

AS_Ability_Shoot_Trace::AS_Ability_Shoot_Trace(const FObjectInitializer& ObjectInitializer) : Super()
{
	ShootingRange = 2500.000000f;
	BaseDamage = 10.000000f;
	TreeDamage = 10.000000f;
	MineDamage = 10.000000f;
	CriticalDamageMultiplier = 20.000000f;
}



void AS_Ability_Shoot_Trace::Use()
{
	FTimerHandle TimerHandle;

	//AS_Ability_Base::Use();
	UpdateShootingAttributes();

	AController* InstigatorController = AActor::GetInstigatorController();

	APlayerController* PlayerController = Cast<APlayerController>(InstigatorController);

	APlayerCameraManager*  PlayerCameraManager = PlayerController->PlayerCameraManager;


	FVector CameraLocation = PlayerCameraManager->GetCameraLocation();
	FRotator CameraRotation = PlayerCameraManager->GetCameraRotation();

	FHitResult HitResult;
	bool WasHit;

    TryShootTrace(CameraLocation, CameraRotation, ShootingRange,HitResult,WasHit);

	if (WasHit)
	{
		CheckHit(HitResult);
	}

	TimerDynamicDelegate.BindUFunction(this, FName(TEXT("K2_DestroyActor")));

	TimerHandle = UKismetSystemLibrary::K2_SetTimerDelegate(TimerDynamicDelegate,5.0,false,0.0,0.0);

}

void AS_Ability_Shoot_Trace::MyUse_Implementation()
{
	Use();
}

void AS_Ability_Shoot_Trace::UpdateShootingAttributes_Implementation()
{
	
}

void AS_Ability_Shoot_Trace::CheckHit_Implementation(FHitResult HitResult)
{

}

void AS_Ability_Shoot_Trace::TryShootTrace(FVector StartLocation, FRotator Rotation, float ShootingRange_S, FHitResult & HitResult, bool & WasHit)
{
	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(Rotation);

	FVector RangeForwardVector = UKismetMathLibrary::Multiply_VectorFloat(ForwardVector, ShootingRange_S);

	FVector EndTarce = StartLocation + RangeForwardVector;

	APawn* MyPawn = AActor::GetInstigator();

	//TArray<APawn*> My_PawnArray;

	//My_PawnArray.SetNum(1, true);

	//My_PawnArray[0] = MyPawn;

	//LineTraceSingle只能接收AActor*类型的数组，因此不能直接创建TArray<APawn*>
	TArray<AActor*> PawnArray{};
	PawnArray.SetNum(1, true);//初始化数组
	PawnArray[0] = *(AActor**)(&MyPawn);//转换类型并传入数组

	FHitResult MyHitResult;

	bool IsHit = UKismetSystemLibrary::LineTraceSingle(this, StartLocation, EndTarce,
		ETraceTypeQuery::TraceTypeQuery1, true, PawnArray, EDrawDebugTrace::None, 
		MyHitResult, true, FLinearColor(1.0, 0.0, 0.0, 1.0), FLinearColor(0.0, 1.0, 0.0, 1.0), 5.0);


	//输出
	HitResult = MyHitResult;
	WasHit = IsHit;

}

void AS_Ability_Shoot_Trace::DealDamageToTree(AActor * DamagedActor, FHitResult HitResult)
{
	bool BlockingHit{};
	bool InitialOverlap{};

	float Time{};
	float Distance{};

	FVector Location{};
	FVector ImpactPoint{};
	FVector Normal{};
	FVector ImpactNormal{};

	UPhysicalMaterial* PhysMat{};
    AActor* HitActor{};
    UPrimitiveComponent* HitComponent{};
    FName HitBoneName{};
    int32 HitItem{};
    int32 FaceIndex{};
    FVector TraceStart(EForceInit::ForceInit);
    FVector TraceEnd(EForceInit::ForceInit);

    UGameplayStatics::BreakHitResult(HitResult, BlockingHit, InitialOverlap, Time, Distance, Location,
		ImpactPoint, Normal,ImpactNormal,PhysMat,HitActor,HitComponent,HitBoneName,HitItem,FaceIndex, TraceStart,TraceEnd);


	APawn* MyPawn = AActor::GetInstigator();

	AController* MyPawnController = MyPawn->GetController();

	float MinTreeDamage = TreeDamage * 0.75;

	float MaxTreeDamage = TreeDamage * 1.25;

	float RandomDamage = UKismetMathLibrary::RandomFloatInRange(MinTreeDamage, MaxTreeDamage);

	UGameplayStatics::ApplyPointDamage(DamagedActor, RandomDamage, Normal, HitResult, 
		MyPawnController, MyPawn, ((UClass*)nullptr));

}


void AS_Ability_Shoot_Trace::DealDamageToMine(AActor * DamagedActor, FHitResult HitResult)
{
	bool BlockingHit{};
	bool InitialOverlap{};

	float Time{};
	float Distance{};

	FVector Location{};
	FVector ImpactPoint{};
	FVector Normal{};
	FVector ImpactNormal{};

	UPhysicalMaterial* PhysMat{};
	AActor* HitActor{};
	UPrimitiveComponent* HitComponent{};
	FName HitBoneName{};
	int32 HitItem{};
	int32 FaceIndex{};
	FVector TraceStart(EForceInit::ForceInit);
	FVector TraceEnd(EForceInit::ForceInit);

	UGameplayStatics::BreakHitResult(HitResult, BlockingHit, InitialOverlap, Time, Distance, Location,
		ImpactPoint, Normal, ImpactNormal, PhysMat, HitActor, HitComponent, HitBoneName, HitItem, FaceIndex, TraceStart, TraceEnd);


	APawn* MyPawn = AActor::GetInstigator();

	AController* MyPawnController = MyPawn->GetController();

	float MinMineDamage = MineDamage * 0.75;

	float MaxMineDamage = MineDamage * 1.25;

	float RandomDamage = UKismetMathLibrary::RandomFloatInRange(MinMineDamage, MaxMineDamage);

	UGameplayStatics::ApplyPointDamage(DamagedActor, RandomDamage, Normal, HitResult,
		MyPawnController, MyPawn, ((UClass*)nullptr));
}


void AS_Ability_Shoot_Trace::DealDamageToActor(AActor * DamagedActor, FHitResult HitResult)
{
	bool BlockingHit{};
	bool InitialOverlap{};

	float Time{};
	float Distance{};

	FVector Location{};
	FVector ImpactPoint{};
	FVector Normal{};
	FVector ImpactNormal{};

	UPhysicalMaterial* PhysMat{};
	AActor* HitActor{};
	UPrimitiveComponent* HitComponent{};
	FName HitBoneName{};
	int32 HitItem{};
	int32 FaceIndex{};
	FVector TraceStart(EForceInit::ForceInit);
	FVector TraceEnd(EForceInit::ForceInit);

	UGameplayStatics::BreakHitResult(HitResult, BlockingHit, InitialOverlap, Time, Distance, Location,
		ImpactPoint, Normal, ImpactNormal, PhysMat, HitActor, HitComponent, HitBoneName, HitItem, FaceIndex, TraceStart, TraceEnd);


	APawn* MyPawn = AActor::GetInstigator();

	AController* MyPawnController = MyPawn->GetController();

	float MinBaseDamage = BaseDamage * 0.75;

	float MaxBaseDamage = BaseDamage * 1.25;

	float RandomDamage = UKismetMathLibrary::RandomFloatInRange(MinBaseDamage, MaxBaseDamage);

	UGameplayStatics::ApplyPointDamage(DamagedActor, RandomDamage, Normal, HitResult,
		MyPawnController, MyPawn, ((UClass*)nullptr));
}

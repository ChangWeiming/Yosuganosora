// Easy Systems


#include "Ability_Shoot_Trace.h"
#include "Kismet/GameplayStatics.h"
#include "GeneratedCodeHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/EngineTypes.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


void AAbility_Shoot_Trace::TryShootTrace(FVector StartLocation, FRotator Rotation, float TShootingRange, /*out*/ FHitResult& HitResult, /*out*/ bool& WasHit)
{
	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(Rotation);

	FVector EndVector = TShootingRange * ForwardVector + StartLocation;

	APawn* MyPawn = AActor::GetInstigator();

	FHitResult MyHitResult;

	TArray<AActor*> IgnoreActors;
	IgnoreActors.SetNum(1, true);

	IgnoreActors[0] = *(AActor**)(&(MyPawn));

	WasHit = UKismetSystemLibrary::LineTraceSingle(this, StartLocation, EndVector,
		ETraceTypeQuery::TraceTypeQuery1, true, IgnoreActors, EDrawDebugTrace::None,
		MyHitResult, true, FLinearColor(1.0f, 0.0f, 0.0f, 1.0f),
		FLinearColor(0.0f, 1.0f, 0.0f, 1.000000), 5.0f);
	HitResult = MyHitResult;

	return;
}


void AAbility_Shoot_Trace::PlayHitEffects(FHitResult HitResult)
{
	TEnumAsByte<EPhysicalSurface> LocalSurface{};
	UPhysicalMaterial* CallFunc_BreakHitResult_PhysMat{};
	UParticleSystem* K2Node_Select_Default{};

	FVector HitLocation = HitResult.Location;
	FVector HitNormal = HitResult.Normal;

	FRotator ZHitRotation = UKismetMathLibrary::MakeRotFromZ(HitNormal);

	FRotator XHitRotation = UKismetMathLibrary::MakeRotFromX(HitNormal);

	USoundBase* SelectDefaultSound{};
	UParticleSystem* SelectDefaultParticle{};


	LocalSurface = EPhysicalSurface::SurfaceType_Default;

	EPhysicalSurface HitResultSurfaceType = UGameplayStatics::GetSurfaceType(HitResult);

	LocalSurface = HitResultSurfaceType;


	USoundBase* HitSound = TSwitchValue<TEnumAsByte<EPhysicalSurface>, USoundBase* >(LocalSurface, SelectDefaultSound, 6,
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, USoundBase* >(EPhysicalSurface::SurfaceType_Default, DefaultHitSound),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, USoundBase* >(EPhysicalSurface::SurfaceType1, GrassHitSound),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, USoundBase* >(EPhysicalSurface::SurfaceType2, SandHitSound),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, USoundBase* >(EPhysicalSurface::SurfaceType3, RockHitSound),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, USoundBase* >(EPhysicalSurface::SurfaceType4, WoodHitSound),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, USoundBase* >(EPhysicalSurface::SurfaceType5, FleshHitSound));

	if (::IsValid(HitSound))
	{
		CallPlaySoundAtLocation(HitSound, HitLocation);
	};

	//TSwitchValue<TEnumAsByte<EPhysicalSurface>, USoundBase* >()


	UParticleSystem*  HitParticle = TSwitchValue<TEnumAsByte<EPhysicalSurface>, UParticleSystem* >(LocalSurface, SelectDefaultParticle, 6,
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UParticleSystem* >(EPhysicalSurface::SurfaceType_Default, DefaultHitParticle),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UParticleSystem* >(EPhysicalSurface::SurfaceType1, GrassHitParticle),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UParticleSystem* >(EPhysicalSurface::SurfaceType2, SandHitParticle),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UParticleSystem* >(EPhysicalSurface::SurfaceType3, RockHitParticle),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UParticleSystem* >(EPhysicalSurface::SurfaceType4, WoodHitParticle),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UParticleSystem* >(EPhysicalSurface::SurfaceType5, FleshHitParticle));

	if (::IsValid(HitParticle))
	{
		CallSpawnParticleAtLocation(HitParticle, HitLocation, ZHitRotation, FVector(1.0f, 1.0f, 1.0f));
	};


	UMaterialInterface* SelectDefaultDecal{};

	UMaterialInterface* HitDecal = TSwitchValue<TEnumAsByte<EPhysicalSurface>, UMaterialInterface* >(LocalSurface, SelectDefaultDecal, 6,
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UMaterialInterface* >(EPhysicalSurface::SurfaceType_Default, DefaultHitDecal),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UMaterialInterface* >(EPhysicalSurface::SurfaceType1, GrassHitDecal),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UMaterialInterface* >(EPhysicalSurface::SurfaceType2, SandHitDecal),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UMaterialInterface* >(EPhysicalSurface::SurfaceType3, RockHitDecal),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UMaterialInterface* >(EPhysicalSurface::SurfaceType4, WoodHitDecal),
		TSwitchPair<TEnumAsByte<EPhysicalSurface>, UMaterialInterface* >(EPhysicalSurface::SurfaceType5, FleshHitDecal));

	if (::IsValid(HitDecal))
	{
		CallSpawnDecal(HitDecal, FVector(3.0f, 3.0f, 3.0f), HitLocation, XHitRotation, 30.0f);
	};


}

void AAbility_Shoot_Trace::DealDamageToActor(AActor * DamagedActor, FHitResult HitResult)
{
	float MaxDamage = BaseDamage * 1.25;
	float MinDamage = BaseDamage * 0.75;

	float Damage = UKismetMathLibrary::RandomFloatInRange(MinDamage, MaxDamage);

	APawn* MyInstigator = AActor::GetInstigator();
	AController* MyController = nullptr;

	if (::IsValid(MyInstigator))
	{
		MyController = MyInstigator->GetController();
	}

	UGameplayStatics::ApplyPointDamage(DamagedActor, Damage, HitResult.Normal, HitResult, MyController, MyInstigator, ((UClass*)nullptr));

}

void AAbility_Shoot_Trace::DealDamageToMine(AActor * DamagedActor, FHitResult HitResult)
{
	float MaxDamage = MineDamage * 1.25;
	float MinDamage = MineDamage * 0.75;

	float Damage = UKismetMathLibrary::RandomFloatInRange(MinDamage, MaxDamage);

	APawn* MyInstigator = AActor::GetInstigator();
	AController* MyController = nullptr;

	if (::IsValid(MyInstigator))
	{
		MyController = MyInstigator->GetController();
	}

	UGameplayStatics::ApplyPointDamage(DamagedActor, Damage, HitResult.Normal,
		HitResult, MyController, MyInstigator, ((UClass*)nullptr));

}


void AAbility_Shoot_Trace::DealDamageToTree(AActor * DamagedActor, FHitResult HitResult)
{

	float MaxDamage = TreeDamage * 1.25;
	float MinDamage = TreeDamage * 0.75;

	float Damage = UKismetMathLibrary::RandomFloatInRange(MinDamage, MaxDamage);

	APawn* MyInstigator = AActor::GetInstigator();
	AController* MyController = nullptr;

	if (::IsValid(MyInstigator))
	{
		MyController = MyInstigator->GetController();
	}

	UGameplayStatics::ApplyPointDamage(DamagedActor, Damage, HitResult.Normal,
		HitResult, MyController, MyInstigator, ((UClass*)nullptr));
}

void AAbility_Shoot_Trace::UpdateShootingAttributes()
{
	APawn* MyInstigate = AActor::GetInstigator();
	//UObject* InputObject;

	float TBaseDamage;
	float BaseCriticalDamage;
	float BaseShootingRange;
	float BaseWoodcuttingDamage;
	float BaseMiningDamage;
	if (::IsValid(MyInstigate))
	{
		CallGetAttributes_BPI(MyInstigate, TBaseDamage, BaseCriticalDamage, BaseShootingRange, BaseWoodcuttingDamage, BaseMiningDamage);
	}

	BaseDamage = TBaseDamage;
	CriticalDamageMultiplier = BaseCriticalDamage;
	ShootingRange = BaseShootingRange;
	TreeDamage = BaseWoodcuttingDamage;
	MineDamage = BaseMiningDamage;


}

void AAbility_Shoot_Trace::CallUse()
{
	UpdateShootingAttributes();

	APlayerController* PlayerController = Cast<APlayerController>(AActor::GetInstigatorController());

	if (::IsValid(PlayerController))
	{
		FVector CameraLocation;
		CameraLocation = PlayerController->PlayerCameraManager->GetCameraLocation();

		FRotator CameraRotation;
		CameraRotation = PlayerController->PlayerCameraManager->GetCameraRotation();

		FHitResult HitResult;
		bool WasHit;

		TryShootTrace(CameraLocation, CameraRotation, ShootingRange, HitResult, WasHit);

		if (WasHit)
		{
			CheckHit(HitResult);
		}

	}


	Timer.BindUFunction(this, FName(TEXT("K2_DestroyActor")));

	FTimerHandle MyTimerHandle = UKismetSystemLibrary::K2_SetTimerDelegate(Timer, 5.0f, false, 0.0f, 0.0f);

}

//霰弹枪效果计算
void AAbility_Shoot_Trace::CallBlunderbussUse()
{
	//更新射击属性
	UpdateShootingAttributes();

	APlayerController* MyController = Cast<APlayerController>(AActor::GetInstigatorController());

	if (::IsValid(MyController))
	{

		FVector CameraLocation = MyController->PlayerCameraManager->GetCameraLocation();

		FRotator CameraRotation = MyController->PlayerCameraManager->GetCameraRotation();

		//循环12次，在一定范围内获得12个随机位置应用点状伤害
		for (int i = 0; i < MaxCount; i++)
		{

			//以ShootingDispersion为中心获取随机射击范围
			float RandomRoll = UKismetMathLibrary::RandomFloatInRange(ShootingDispersion, (-1)*ShootingDispersion);
			float RandomPitch = UKismetMathLibrary::RandomFloatInRange(ShootingDispersion, (-1)*ShootingDispersion);
			float RandomYaw = UKismetMathLibrary::RandomFloatInRange(ShootingDispersion, (-1)*ShootingDispersion);

			FRotator RandomRotation = FRotator(RandomRoll, RandomPitch, RandomYaw);

			FRotator RandomRoom = UKismetMathLibrary::ComposeRotators(CameraRotation, RandomRotation);

			FHitResult HitResult;
			bool WasHit;


			//传入RandomRotation而非RandomRoom会出现错误；
		    //获得命中结果
			TryShootTrace(CameraLocation, RandomRoom, ShootingRange, HitResult, WasHit);

			//传入命中结果，CheckHit函数会根据命中结果中的属性判断命中的是植物还是Actor，计算其对应的伤害
			CheckHit(HitResult);

		}
	}

	BTimer.BindUFunction(this, FName(TEXT("K2_DestroyActor")));

	FTimerHandle MyTimerHandle = UKismetSystemLibrary::K2_SetTimerDelegate(BTimer, 5.0f, false, 0.0f, 0.0f);

}
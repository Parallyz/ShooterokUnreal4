// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"


// Sets default values
AEnemy::AEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	healthPoint = 100;
	damageFromBullets = 10;
	//DamageCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageCollision"));

	//DamageCollision->OnComponentBeginOverlap.Add(&AEnemy::OnHit)//.AddDynamic(this, );
	pooler = new ObjectPooler();

	
	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/Rifle/RifleB_Fire_Cue.RifleB_Fire_Cue'"));

	if (Sound.Succeeded())
	{
		FireSound = Sound.Object;
	}
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitPooler();
	expirienceByKill = 20;
	//GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AEnemy::Fire, 1.0f, true, 0.7f);

	// 

}


// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{

	//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));
}

void AEnemy::DealDamage(float damage)
{
	healthPoint -= damage;
	if (healthPoint <= 0)
	{
	//	Destroy();
	}
}

void AEnemy::Fire()
{
	if (ProjectileClass) {

		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);


		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(FVector(0.0f, 0.0f, 0.0f));

		FRotator MuzzleRotation = CameraRotation;

		if (pooler->IfInit())
		{
			currentProjectile = pooler->GetProjectileToShoot();
			if (currentProjectile != NULL)
			{
				currentProjectile->SetActorLocation(MuzzleLocation);
				//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, (TEXT("Hello %s"), currentProjectile->ProjectileMovementComponent->Velocity().ToString()));

				FVector LaunchDirection = MuzzleRotation.Vector();

				currentProjectile->FireInDirection(LaunchDirection);
				GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AEnemy::ResetProjectile, 1.0f, false, 0.5f);

				//	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green,(TEXT("Hello %s"), porjectile->GetActorLocation().ToString()));


			}

		}

	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, (TEXT("Projectile class doesn`t init")) );

	}


	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	/*if (FireAnimation != nullptr)
	{

		UAnimInstance* AnimInstance = FPSMesh->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}*/

}

void AEnemy::ResetProjectile()
{
	if (currentProjectile != NULL)
		currentProjectile->Reset();
}

void AEnemy::InitPooler()
{
	if (ProjectileClass)
	{

		FVector MuzzleLocation;
		FRotator MuzzleRotation;

		GetActorEyesViewPoint(MuzzleLocation, MuzzleRotation);

		UWorld* World = GetWorld();

		MuzzleLocation = FVector(MuzzleLocation.X + 100.f, MuzzleLocation.Y, MuzzleLocation.Z);
		if (World)
		{

			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();


			pooler->OnEnable(1	, ProjectileClass, *World, MuzzleLocation, MuzzleRotation, SpawnParams);
		}
	}
}




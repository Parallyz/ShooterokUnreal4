// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include <Shooterok/Public/MySaveGame.h>





// Sets default values
AMyCharacter::AMyCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(70.f, 80.0f);

	//BaseTurnRate = 45.f;
	//BaseLookUpRate = 45.f;


	PrimaryActorTick.bCanEverTick = true;

	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	//RootComponent=FPSCameraComponent;


	check(FPSMesh != nullptr);
	check(FPSCameraComponent != nullptr);


	FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	FPSCameraComponent->bUsePawnControlRotation = true;



	FPSMesh->SetOnlyOwnerSee(true);
	FPSMesh->SetupAttachment(FPSCameraComponent);
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	auto weaponBuilder = new RifleBuilder();
	weaponBuilder->CreateWeapon();
	weapon = weaponBuilder->GetWeapon();


	FPSMesh->SetRelativeLocation(FVector(6.8f, 8.75f, -17.47f));
	FPSMesh->SetRelativeRotation(FRotator(-0.43f, 4.98f, -10.01f));

	GetMesh()->SetOwnerNoSee(true);

	pooler = new ObjectPooler();

}



void AMyCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{

	Super::BeginPlay();
	InitPooler();
	FullHealth = 100.0f;
	Health = 30;

	BaseVolume = 1.f;
	Kills = 0;
	FullStamina = 100.0f;
	Stamina = FullStamina;
	isCanFire = true;
	Level = 1;

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJump);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacter::Fire);

	PlayerInputComponent->BindAction("SaveGame", IE_Pressed, this, &AMyCharacter::SaveGame);
	PlayerInputComponent->BindAction("LoadGame", IE_Pressed, this, &AMyCharacter::LoadGame);



	//PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AMyCharacter::ReloadWeapon);

}

void AMyCharacter::MoveForward(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, value);
}

void AMyCharacter::MoveRight(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, value);
}

void AMyCharacter::StartJump()
{
	bPressedJump = true;
}

void AMyCharacter::StopJump()
{
	bPressedJump = false;
}
void AMyCharacter::Fire()
{

	if (ProjectileClass && weapon->Fire() && isCanFire)
	{

		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);


		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(weapon->MuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;


		if (pooler->IfInit())
		{
			currentProjectile = pooler->GetProjectileToShoot();
			if (currentProjectile != NULL)
			{
				currentProjectile->SetActorLocation(MuzzleLocation);



				FVector LaunchDirection = MuzzleRotation.Vector();

				//currentProjectile->SetActorHiddenInGame(true);

				currentProjectile->FireInDirection(LaunchDirection);
				GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMyCharacter::ResetProjectile, 1.0f, false, 0.5f);

			}

		}

		if (weapon->FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, weapon->FireSound, GetActorLocation());
		}


	}

	else if (weapon->currentBulletsInMagazine == 0) {
		if (weapon->EmptyMagazineSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, weapon->EmptyMagazineSound, GetActorLocation());
		}
	}

}

void AMyCharacter::ResetProjectile()
{
	if (currentProjectile != NULL)
		currentProjectile->Reset();
}



void AMyCharacter::InitPooler()
{
	FVector CameraLocation;
	FRotator CameraRotation;

	GetActorEyesViewPoint(CameraLocation, CameraRotation);


	//FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(weapon->MuzzleOffset);



	UWorld* World = GetWorld();
	if (World)
	{

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();


		pooler->OnEnable(5, ProjectileClass, *World, CameraLocation, CameraRotation, SpawnParams);


	}
}

void AMyCharacter::PickUpAmmo()
{
	weapon->countBullets += weapon->maxBulletsInMagazine;
}


float AMyCharacter::PickUpHp()
{
	Health += 25;
	if (Health > 100)
		Health = 100;
	return Health;
}



void AMyCharacter::DealDamage(float Damage)
{
	Health -= Damage;
	if (Health < 0)
		Health = 0;
}



void AMyCharacter::LevelUp()
{
	Level += 1;
}





float AMyCharacter::GetBaseTurnRate()
{
	return BaseTurnRate;
}

float AMyCharacter::GetBaseUpRate()
{
	return BaseLookUpRate;
}

void AMyCharacter::SetBaseTurnRate(float value)
{
	BaseTurnRate = value;
}

void AMyCharacter::SetBaseUpRate(float value)
{
	BaseLookUpRate = value;
}

int AMyCharacter::GetMaxCountBullets()
{
	if (weapon != NULL)
	{
		return weapon->maxCountBullets;
	}
	return 0;
}



int AMyCharacter::GetBulletsInMagazine()
{
	if (weapon != NULL)
	{
		return weapon->currentBulletsInMagazine;
	}
	return NULL;
}
int AMyCharacter::GetCountBullets() {
	if (weapon != NULL)
	{
		return weapon->countBullets;
	}
	return NULL;
}

void AMyCharacter::GetExpirienceKill(int exp)
{
	Expirience += exp;
	if (Expirience >= 100)
	{

		LevelUp();
		Expirience -= 100;
	}
}


int AMyCharacter::GetDamageFromBullet()
{
	if (weapon != NULL)
	{
		return weapon->damageFromBullets;
	}
	return 0;
}

void AMyCharacter::ReloadWeapon()
{
	if (weapon->Reload())
	{
		if (weapon->ReloadSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, weapon->ReloadSound, GetActorLocation());
		}

	}

}



void AMyCharacter::SaveGame()
{
	
	if (weapon != NULL)
	{


		UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));


		SaveGameInstance->baseUpRate = BaseLookUpRate;
		SaveGameInstance->baseTurnRate = BaseTurnRate;
		SaveGameInstance->killsEnemy = Kills;
		SaveGameInstance->Bulletcount = weapon->countBullets;
		SaveGameInstance->bulletInMagazine = weapon->currentBulletsInMagazine;
		SaveGameInstance->baseVolume = BaseVolume;
		SaveGameInstance->exp = Expirience;
		SaveGameInstance->Level = Level;
		SaveGameInstance->hp = Health;
		SaveGameInstance->lastHeroLocation = GetActorLocation();
		SaveGameInstance->lastHeroWeapon = weapon;


		UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Slot1"), 0);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Game saved"));

	}
}

void AMyCharacter::LoadGame()
{

	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("Slot1", 0));

	weapon = SaveGameInstance->lastHeroWeapon;
	BaseLookUpRate = SaveGameInstance->baseUpRate;
	BaseTurnRate = SaveGameInstance->baseTurnRate;
	Kills = SaveGameInstance->killsEnemy;
	weapon->countBullets = SaveGameInstance->Bulletcount;
	weapon->currentBulletsInMagazine = SaveGameInstance->bulletInMagazine;
	BaseVolume = SaveGameInstance->baseVolume = BaseVolume;
	Expirience = SaveGameInstance->exp = Expirience;
	Level = SaveGameInstance->Level = Level;
	Health = SaveGameInstance->hp = Health;
	this->SetActorLocation(SaveGameInstance->lastHeroLocation);
	

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Game loaded"));

}

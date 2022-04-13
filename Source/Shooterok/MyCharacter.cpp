// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"





// Sets default values
AMyCharacter::AMyCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(70.f, 80.0f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	healthPoint = 100;

	PrimaryActorTick.bCanEverTick = true;

	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));


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
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
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

	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AMyCharacter::ReloadWeapon);

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

	if (ProjectileClass && weapon->Fire())
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

				GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("In magazine"));

				GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, (FString::FromInt(weapon->currentBulletsInMagazine)));

				GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Count"));

				GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, (FString::FromInt(weapon->countBullets)));



				FVector LaunchDirection = MuzzleRotation.Vector();

				currentProjectile->FireInDirection(LaunchDirection);
				GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMyCharacter::ResetProjectile, 1.0f, false, 0.5f);		

			}

		}

		if (weapon->FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, weapon->FireSound, GetActorLocation());
		}

		if (FireAnimation != nullptr)
		{

			UAnimInstance* AnimInstance = FPSMesh->GetAnimInstance();
			if (AnimInstance != nullptr)
			{
				AnimInstance->Montage_Play(FireAnimation, 1.f);
			}
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

	FVector MuzzleLocation = FVector(-10.0f, 0.0f, 0.0f);

	FRotator MuzzleRotation = CameraRotation;


	UWorld* World = GetWorld();
	if (World)
	{

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();


		pooler->OnEnable(5, ProjectileClass, *World, MuzzleLocation, MuzzleRotation, SpawnParams);


	}
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





// Fill out your copyright notice in the Description page of Project Settings.

#include <string> 
#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	CurrentGun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PersonGunMesh"));


	check(FPSMesh != nullptr);
	check(FPSCameraComponent != nullptr);
	check(CurrentGun != nullptr);


	FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

	FPSCameraComponent->bUsePawnControlRotation = true;


	FPSMesh->SetOnlyOwnerSee(true);

	// Attach the FPS mesh to the FPS camera.
	FPSMesh->SetupAttachment(FPSCameraComponent);

	// Disable some environmental shadows to preserve the illusion of having a single mesh.
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;


	CurrentGun->SetupAttachment(FPSMesh);
	CurrentGun->bCastDynamicShadow = false;
	CurrentGun->CastShadow = false;


	GetMesh()->SetOwnerNoSee(true);


	

	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	FirstBulletsInGunInit();

	healthPoint = 100;
	
	
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

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);

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
	if (ProjectileClass )
	{
		
		

		FVector CameraLocation;
		FRotator CameraRotation;

		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		// Set MuzzleOffset to spawn projectiles slightly in front of the camera.
		MuzzleOffset.Set(100.0f, 20.0f, 40.0f);


		// Transform MuzzleOffset from camera space to world space.
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);


		// Skew the aim to be slightly upwards.
		FRotator MuzzleRotation = CameraRotation;
		// MuzzleRotation.Pitch += 2.5f;


		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			// Spawn the projectile at the muzzle.
			AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				
				// Set the projectile's initial trajectory.
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
	
}

void AMyCharacter::FirstBulletsInGunInit() {

	maxBulletsInMagazine = 30;
	countBullets = maxBulletsInMagazine*4;
	currentBulletsInMagazine = maxBulletsInMagazine;
}

bool AMyCharacter::MagazineIsNotEmpty()	 { return currentBulletsInMagazine > 0; }

bool AMyCharacter::HaveBullets()  { return countBullets > 0; }

void AMyCharacter::ReloadWeapon()
{
	if (HaveBullets())
	{
		countBullets -= currentBulletsInMagazine;
		currentBulletsInMagazine = maxBulletsInMagazine;
	}
}



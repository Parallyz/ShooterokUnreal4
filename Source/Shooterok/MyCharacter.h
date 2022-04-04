// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "FPSProjectile.h"
#include "MyCharacter.generated.h"

UCLASS()
class SHOOTEROK_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* FPSCameraComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FPSMesh;
	// Gun muzzle offset from the camera location.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* CurrentGun;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int healthPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int expirience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int maxBulletsInMagazine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int countBullets;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int currentBulletsInMagazine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int damageFromBullets;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float value);

	UFUNCTION()
		void MoveRight(float value);

	UFUNCTION()
		void StartJump();


	UFUNCTION()
		void StopJump();


	UFUNCTION()
		void Fire();

	UFUNCTION()
		void FirstBulletsInGunInit();

	UFUNCTION()
		bool MagazineIsNotEmpty();

	UFUNCTION()
		bool HaveBullets();
	UFUNCTION()
		void ReloadWeapon();

};

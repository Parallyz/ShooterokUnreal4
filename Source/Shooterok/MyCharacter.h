// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FPSProjectile.h"
#include <WeaponBuilder.h>
#include "MyCharacter.generated.h"

UCLASS()
class SHOOTEROK_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* FPSCameraComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FPSMesh;
	// Gun muzzle offset from the camera location.
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	//	FVector MuzzleOffset;
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;

	Weapon* weapon;
	/*UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* CurrentGun;*/

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int healthPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int expirience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int level;





	

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* FireSound;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void TurnAtRate(float Rate);

	
	void LookUpAtRate(float Rate);
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
		void ReloadWeapon();

};

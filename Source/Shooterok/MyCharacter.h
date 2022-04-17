// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FPSProjectile.h"
#include <WeaponBuilder.h>
#include <Shooterok/Public/ObjectPooler.h>

#include <Runtime/Engine/Classes/Components/TimelineComponent.h>
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
	
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;

	Weapon* weapon;

	ObjectPooler* pooler;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		float HealthPrecentage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
		float FullHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stamina)
		float FullStamina;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stamina)
		float Stamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Health)
		FTimerHandle MemberTimerHandle;









	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int Expirience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		UAnimMontage* FireAnimation;

	AFPSProjectile* currentProjectile;





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void TurnAtRate(float Rate);

	void ResetProjectile();

	
	

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

	UFUNCTION(BlueprintCallable)
		void PickUpAmmo();

	UFUNCTION(BlueprintCallable,Category=Health)
		float PickUpHp();

	UFUNCTION(BlueprintPure, Category = Stamina)
		float GetStamina();

	UFUNCTION(BlueprintPure)
		int GetMaxCountBullets();


	UFUNCTION(BlueprintCallable)
		int GetDamageFromBullet();

	UFUNCTION()
		void ReloadWeapon();





	UFUNCTION()
		void SetStaminaValue();



	UFUNCTION(BlueprintCallable)
		int GetBulletsInMagazine();

	UFUNCTION(BlueprintCallable)
		int GetCountBullets();

	UFUNCTION(BlueprintCallable)
		void GetExpirienceKill(int exp);
	

	UFUNCTION()
		void DealDamage(float Damage);

	UFUNCTION(BlueprintCallable)
		void LevelUp();

	UFUNCTION()
		void InitPooler();
};

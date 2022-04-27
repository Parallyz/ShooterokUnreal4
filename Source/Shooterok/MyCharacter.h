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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		float BaseVolume;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* FPSCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		USkeletalMeshComponent* FPSMesh;
	
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;

	Weapon* weapon;

	ObjectPooler* pooler;

	WeaponBuilder* weaponBuilder;

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
		int Kills;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int isCanFire;

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


	UFUNCTION(BlueprintCallable)
		void Fire();



	UFUNCTION(BlueprintCallable)
		void PickUpAmmo();

	UFUNCTION(BlueprintCallable,Category=Health)
		float PickUpHp();

	

	UFUNCTION(BlueprintPure)
		float GetBaseTurnRate();

	UFUNCTION(BlueprintPure)
		float GetBaseUpRate();

	UFUNCTION(BlueprintCallable)
		void SetBaseTurnRate(float value);

	UFUNCTION(BlueprintCallable)
		void SetBaseUpRate(float value);

	UFUNCTION(BlueprintPure)
		int GetMaxCountBullets();


	UFUNCTION(BlueprintCallable)
		int GetDamageFromBullet();

	UFUNCTION(BlueprintCallable)
		void ReloadWeapon();

	UFUNCTION(BlueprintCallable)
		int GetBulletsInMagazine();

	UFUNCTION(BlueprintCallable)
		int GetCountBullets();

	UFUNCTION(BlueprintCallable)
		void SetBulletsInMagazine(int countInMagazine);

	UFUNCTION(BlueprintCallable)
		void SetCountBullets(int count);

	UFUNCTION(BlueprintCallable)
		void GetExpirienceKill(int exp);

	UFUNCTION(BlueprintCallable)
		
		bool FullMagazine();
	
	
	UFUNCTION(BlueprintCallable)
		int GetWeaponId();

	UFUNCTION(BlueprintCallable)
		void InitWeaponById(int id);


	UFUNCTION(BlueprintCallable)
		void DealDamage(float Damage);

	UFUNCTION(BlueprintCallable)
		void LevelUp();

	UFUNCTION()
		void InitPooler();

	UFUNCTION(BlueprintCallable)

		int GetMaxInMagazin();
		
	   
};

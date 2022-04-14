// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include <Shooterok/Public/ObjectPooler.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "Enemy.generated.h"

UCLASS()
class SHOOTEROK_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UPROPERTY(EditAnywhere)
	//	UBoxComponent* DamageCollision;


	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		UAnimMontage* FireAnimation;

	AFPSProjectile* currentProjectile;

	ObjectPooler* pooler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* FireSound;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, 
			FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int healthPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int expirienceByKill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int damageFromBullets;

	UFUNCTION(BlueprintCallable)
		void DealDamage(float damage);

	UFUNCTION(BlueprintCallable)
		void Fire();

	FTimerHandle MemberTimerHandle;

	void ResetProjectile();

	void InitPooler();
	
};

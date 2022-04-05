// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
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

	UPROPERTY(EditAnywhere)
		UBoxComponent* DamageCollision;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, 
			FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int healthPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int expirienceByKill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int damageFromBullets;

	UFUNCTION()
		void DealDamage(float damage);
};

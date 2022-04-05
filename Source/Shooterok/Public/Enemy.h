// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Enemy.generated.h"

UCLASS()
class SHOOTEROK_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* EnemyMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* EnemyGun;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int healthPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int expirienceByKill;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int damageFromBullets;

};

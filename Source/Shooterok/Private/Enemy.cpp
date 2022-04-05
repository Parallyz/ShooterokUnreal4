// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnemyPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("EnemyPersonMesh"));
	EnemyPersonGunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("EnemyPersonGunMesh"));

	check(EnemyPersonMesh != nullptr);
	check(EnemyPersonGunMesh != nullptr);


	EnemyPersonGunMesh->SetupAttachment(RootComponent);
	EnemyPersonGunMesh->bCastDynamicShadow = false;
	EnemyPersonGunMesh->CastShadow = false;

	EnemyPersonMesh->bCastDynamicShadow = false;
	EnemyPersonMesh->CastShadow = false;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


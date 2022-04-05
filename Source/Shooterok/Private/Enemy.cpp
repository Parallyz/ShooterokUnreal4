// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

//	EnemyMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("EnemyPersonMesh"));
//	EnemyGun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("EnemyPersonGunMesh"));

	//check(!EnemyMesh);
	//check(!EnemyGun);


	//EnemyGun->SetupAttachment(RootComponent);
//	EnemyGun->bCastDynamicShadow = false;
//	EnemyGun->CastShadow = false;

//	EnemyMesh->bCastDynamicShadow = false;
//	EnemyMesh->CastShadow = false;
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


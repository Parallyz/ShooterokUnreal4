// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <list>
#include <Shooterok/FPSProjectile.h>

/**
 * 
 */
class  ObjectPooler
{
	std::list<AFPSProjectile*>* pooledObjects;

public:
	ObjectPooler();
	~ObjectPooler();

	bool IfInit();
	
	void OnEnable(int countPool, TSubclassOf<class AFPSProjectile> ProjectileClass, 
		UWorld& World, FVector& MuzzleLocation, 
		FRotator& MuzzleRotation, FActorSpawnParameters& SpawnParams);

	AFPSProjectile* GetProjectileToShoot();

	void push(AFPSProjectile* proj);
};



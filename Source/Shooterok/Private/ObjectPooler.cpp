// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPooler.h"





#pragma region Pooler
ObjectPooler::ObjectPooler()
{
}

ObjectPooler::~ObjectPooler()
{
}

bool ObjectPooler::IfInit()
{
	return  pooledObjects == nullptr ? false : true;
}





void ObjectPooler::OnEnable(int countPool, TSubclassOf<class AFPSProjectile> ProjectileClass, UWorld& World, FVector& MuzzleLocation, FRotator& MuzzleRotation, FActorSpawnParameters& SpawnParams)
{
	pooledObjects = new std::list<AFPSProjectile*>();

	for (int i = 0;i < countPool;i++)
	{
		MuzzleLocation = FVector(MuzzleLocation.X, MuzzleLocation.Y, MuzzleLocation.Z - 1000 );
		AFPSProjectile* proj = World.SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
		//proj->Id = i;
		//proj->SetActorHiddenInGame(true);

		pooledObjects->push_back(proj);
	}

}
AFPSProjectile* ObjectPooler::GetProjectileToShoot()
{


	for (AFPSProjectile* var : *pooledObjects)
	{
		if (!var->isShooting)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 200, FColor::Green,(TEXT("Hello %s"), var->GetActorLocation().ToString()));
			var->isShooting = true;
			return var;
		}
	}
	
	for (AFPSProjectile* var : *pooledObjects)
	{
		var->Reset();

	}
	if (pooledObjects != NULL)
	{
		auto firstProj = *pooledObjects->begin();
		firstProj->isShooting = true;
		return firstProj;
	}
	return NULL;

}
void ObjectPooler::push(AFPSProjectile* proj)
{
	pooledObjects->push_back(proj);
}
void ObjectPooler::reset()
{
	if (pooledObjects != NULL) {

		for (AFPSProjectile* var : *pooledObjects)
		{
			var->Reset();
		}
	}
}
#pragma endregion








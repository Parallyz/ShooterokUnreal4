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
	return  pooledObjects == nullptr ? false: true;
}





void ObjectPooler::OnEnable(int countPool, TSubclassOf<class AFPSProjectile> ProjectileClass, UWorld& World, FVector &MuzzleLocation, FRotator &MuzzleRotation, FActorSpawnParameters &SpawnParams)
{
	pooledObjects = new std::list<AFPSProjectile*>();

	for (int i = 0;i < countPool;i++)
	{
		AFPSProjectile* proj = World.SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
		pooledObjects->push_back(proj);
	}

}
AFPSProjectile* ObjectPooler::GetProjectileToShoot()
{
	
	for (AFPSProjectile* var : *pooledObjects)
	{
		if (var->GetActorLocation() == var->resetPosition)
		{			
			//GEngine->AddOnScreenDebugMessage(-1, 200, FColor::Green,(TEXT("Hello %s"), var->GetActorLocation().ToString()));
			return var;
		}
	}
	return NULL;
}
void ObjectPooler::push(AFPSProjectile* proj)
{
	pooledObjects->push_back(proj);
}
#pragma endregion








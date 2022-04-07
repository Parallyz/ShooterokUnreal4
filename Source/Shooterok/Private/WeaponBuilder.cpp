// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBuilder.h"

#pragma region WeaponBuilder

WeaponBuilder::WeaponBuilder()
{

}

WeaponBuilder::~WeaponBuilder() {
	delete weapon;
}

void WeaponBuilder::SetFPSMesh() {}

void WeaponBuilder::SetMuzzleOffset() {}

void WeaponBuilder::SetGunMesh() {}

void WeaponBuilder::SetFireSound() {}

void WeaponBuilder::SetGunOffset() {}

void WeaponBuilder::SetCountBullet()
{
}


void WeaponBuilder::SetLevelOfWeapon() {}

void WeaponBuilder::SetmaxBulletsInMagazine() {}

void WeaponBuilder::SetdamageFromBullets() {}



Weapon* WeaponBuilder::GetWeapon() { return this->weapon; }

void WeaponBuilder::CreateWeapon(USkeletalMeshComponent* GunMesh)
{
	this->weapon = new Weapon( GunMesh);

	
}

#pragma endregion

#pragma region RifleBuilder


void RifleBuilder::SetFPSMesh()
{
	/*static ConstructorHelpers::FObjectFinder<USkeletalMesh>Mesh(TEXT("'/Game/Mesh/FPSArms_rigged.FPSArms_rigged'"));
	
	if (Mesh.Succeeded())
	{
		weapon->FPSMesh->SetSkeletalMesh(Mesh.Object);
	}*/
}
void RifleBuilder::SetMuzzleOffset()
{
	weapon->MuzzleOffset = FVector(120.0f, 18.0f, 36.0f);
}

void RifleBuilder::SetGunMesh()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>Mesh(TEXT("'/Game/MilitaryWeapDark/Weapons/Assault_Rifle_B.Assault_Rifle_B'"));
	
	if (Mesh.Succeeded())
	{
		weapon->GunMesh->SetSkeletalMesh(Mesh.Object);
	}
}

void RifleBuilder::SetFireSound()
{
	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/MilitaryWeapDark/Sound/Rifle/Wavs/RifleB_Fire_ST01.RifleB_Fire_ST01'"));

	if (Sound.Succeeded())
	{
		weapon->FireSound = Sound.Object;
	}
}

void RifleBuilder::SetLevelOfWeapon()
{
	weapon->level = 1;
}

void RifleBuilder::SetmaxBulletsInMagazine()
{
	weapon->maxBulletsInMagazine = 30;
}

void RifleBuilder::SetdamageFromBullets()
{
	weapon->damageFromBullets = 30;
}

void RifleBuilder::SetGunOffset()
{
 //weapon->GunOffset=(120.0f, 18.0f, 36.0f);
}

void RifleBuilder::SetCountBullet()
{
	weapon->countBullets = weapon->maxBulletsInMagazine * 4;
}



void RifleBuilder::CreateWeapon( USkeletalMeshComponent* GunMesh)
{
	WeaponBuilder::CreateWeapon( GunMesh);
	RifleBuilder::SetmaxBulletsInMagazine();
	RifleBuilder::SetdamageFromBullets();
	RifleBuilder::SetLevelOfWeapon();
	RifleBuilder::SetFireSound();
	RifleBuilder::SetGunMesh();
	RifleBuilder::SetMuzzleOffset();
	RifleBuilder::SetCountBullet();
}

#pragma endregion


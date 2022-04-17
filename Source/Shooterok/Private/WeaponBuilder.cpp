// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBuilder.h"

#pragma region WeaponBuilder

WeaponBuilder::WeaponBuilder()
{

}

WeaponBuilder::~WeaponBuilder() {
	delete weapon;
}



void WeaponBuilder::SetMuzzleOffset() {}



void WeaponBuilder::SetFireSound() {}

void WeaponBuilder::SetMagazineEmptySound()
{
}



void WeaponBuilder::SetGunOffset() {}

void WeaponBuilder::SetCountBullet()
{
}

void WeaponBuilder::SetMaxCountBullet()
{
}


void WeaponBuilder::SetLevelOfWeapon() {}

void WeaponBuilder::SetmaxBulletsInMagazine() {}

void WeaponBuilder::SetdamageFromBullets() {}



Weapon* WeaponBuilder::GetWeapon() { return this->weapon; }

void WeaponBuilder::CreateWeapon()
{
	this->weapon = new Weapon();

	
}

#pragma endregion

#pragma region RifleBuilder



void RifleBuilder::SetMuzzleOffset()
{
//	weapon->MuzzleOffset = FVector(120.0f, 30.0f, 36.0f);
	weapon->MuzzleOffset = FVector(0.0f, 0.0f, 50.0f);

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
	weapon->damageFromBullets = 25;
}

void RifleBuilder::SetGunOffset()
{
 //weapon->GunOffset=(120.0f, 18.0f, 36.0f);
}

void RifleBuilder::SetCountBullet()
{
	weapon->countBullets = weapon->maxBulletsInMagazine * 4;
}

void RifleBuilder::SetMagazineEmptySound()
{
	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/MilitaryWeapDark/Sound/Rifle/Wavs/Rifle_AmmoPickup.Rifle_AmmoPickup'"));

	if (Sound.Succeeded())
	{
		weapon->EmptyMagazineSound = Sound.Object;
	}
}

void RifleBuilder::SetReloadSound()
{
	
	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("/Game/MilitaryWeapDark/Sound/Rifle/Wavs/Rifle_Reload02.Rifle_Reload02"));

	if (Sound.Succeeded())
	{
		weapon->ReloadSound = Sound.Object;
	}
}



void RifleBuilder::CreateWeapon()
{
	WeaponBuilder::CreateWeapon();
	
	RifleBuilder::SetmaxBulletsInMagazine();
	RifleBuilder::SetdamageFromBullets();
	RifleBuilder::SetLevelOfWeapon();
	RifleBuilder::SetFireSound();
	RifleBuilder::SetMuzzleOffset();
	RifleBuilder::SetCountBullet();
	RifleBuilder::SetMagazineEmptySound();
	RifleBuilder::SetReloadSound();
	RifleBuilder::SetMaxCountBullet();


	weapon->currentBulletsInMagazine = weapon->maxBulletsInMagazine;

}

void RifleBuilder::SetMaxCountBullet()
{
	weapon->maxCountBullets = weapon->countBullets;
}

#pragma endregion


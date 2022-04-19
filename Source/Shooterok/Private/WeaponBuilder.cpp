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
	
	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/Rifle/RifleB_Fire_Cue.RifleB_Fire_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->FireSound = Sound.Object;
	}
}

void RifleBuilder::SetLevelOfWeapon()
{
	weapon->level = 10;
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
	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/Rifle/Rifle_AmmoPickup_Cue.Rifle_AmmoPickup_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->EmptyMagazineSound = Sound.Object;
	}
}

void RifleBuilder::SetReloadSound()
{
	
	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/Rifle/Rifle_Reload_Cue.Rifle_Reload_Cue'"));

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

#pragma region Pistol


void PistolBuilder::SetMuzzleOffset()
{	
	weapon->MuzzleOffset = FVector(0.0f, 0.0f, 50.0f);
}



void PistolBuilder::SetFireSound()
{

	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/Pistol/PistolB_Fire_Cue.PistolB_Fire_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->FireSound = Sound.Object;
	}
}

void PistolBuilder::SetLevelOfWeapon()
{
	weapon->level = 1;
}

void PistolBuilder::SetmaxBulletsInMagazine()
{
	weapon->maxBulletsInMagazine = 8;
}

void PistolBuilder::SetdamageFromBullets()
{
	weapon->damageFromBullets = 20;
}

void PistolBuilder::SetGunOffset()
{
	//weapon->GunOffset=(120.0f, 18.0f, 36.0f);
}

void PistolBuilder::SetCountBullet()
{
	weapon->countBullets = weapon->maxBulletsInMagazine * 4;
}

void PistolBuilder::SetMagazineEmptySound()
{
	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/Pistol/Pistol_ReloadEject_Cue.Pistol_ReloadEject_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->EmptyMagazineSound = Sound.Object;
	}
}

void PistolBuilder::SetReloadSound()
{

	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/Pistol/Pistol_ReloadInsert_Cue.Pistol_ReloadInsert_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->ReloadSound = Sound.Object;
	}
}



void PistolBuilder::CreateWeapon()
{
	WeaponBuilder::CreateWeapon();

	PistolBuilder::SetmaxBulletsInMagazine();
	PistolBuilder::SetdamageFromBullets();
	PistolBuilder::SetLevelOfWeapon();
	PistolBuilder::SetFireSound();
	PistolBuilder::SetMuzzleOffset();
	PistolBuilder::SetCountBullet();
	PistolBuilder::SetMagazineEmptySound();
	PistolBuilder::SetReloadSound();
	PistolBuilder::SetMaxCountBullet();


	weapon->currentBulletsInMagazine = weapon->maxBulletsInMagazine;

}

void PistolBuilder::SetMaxCountBullet()
{
	weapon->maxCountBullets = weapon->countBullets;
}
#pragma endregion

#pragma region ShotGun

void ShotGunBuilder::SetMuzzleOffset()
{
	weapon->MuzzleOffset = FVector(0.0f, 0.0f, 50.0f);
}



void ShotGunBuilder::SetFireSound()
{

	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/ShotGun/ShotgunB_Fire_Cue.ShotgunB_Fire_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->FireSound = Sound.Object;
	}
}

void ShotGunBuilder::SetLevelOfWeapon()
{
	weapon->level = 20;
}

void ShotGunBuilder::SetmaxBulletsInMagazine()
{
	weapon->maxBulletsInMagazine = 8;
}

void ShotGunBuilder::SetdamageFromBullets()
{
	weapon->damageFromBullets = 50;
}

void ShotGunBuilder::SetGunOffset()
{
	//weapon->GunOffset=(120.0f, 18.0f, 36.0f);
}

void ShotGunBuilder::SetCountBullet()
{
	weapon->countBullets = weapon->maxBulletsInMagazine * 4;
}

void ShotGunBuilder::SetMagazineEmptySound()
{
	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/ShotGun/Shotgun_Raise_Cue.Shotgun_Raise_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->EmptyMagazineSound = Sound.Object;
	}
}

void ShotGunBuilder::SetReloadSound()
{

	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/ShotGun/Shotgun_Reload_Cue.Shotgun_Reload_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->ReloadSound = Sound.Object;
	}
}

void ShotGunBuilder::SetMaxCountBullet()
{
	weapon->maxCountBullets = weapon->countBullets;
}

void ShotGunBuilder::CreateWeapon()
{
	WeaponBuilder::CreateWeapon();

	ShotGunBuilder::SetmaxBulletsInMagazine();
	ShotGunBuilder::SetdamageFromBullets();
	ShotGunBuilder::SetLevelOfWeapon();
	ShotGunBuilder::SetFireSound();
	ShotGunBuilder::SetMuzzleOffset();
	ShotGunBuilder::SetCountBullet();
	ShotGunBuilder::SetMagazineEmptySound();
	ShotGunBuilder::SetReloadSound();
	ShotGunBuilder::SetMaxCountBullet();


	weapon->currentBulletsInMagazine = weapon->maxBulletsInMagazine;

}


#pragma endregion

#pragma region Grenade

void GrenadeBuilder::SetMuzzleOffset()
{
	weapon->MuzzleOffset = FVector(0.0f, 0.0f, 50.0f);
}



void GrenadeBuilder::SetFireSound()
{

	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/Grenade/GrenadeLauncherB_Fire_Cue.GrenadeLauncherB_Fire_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->FireSound = Sound.Object;
	}
}

void GrenadeBuilder::SetLevelOfWeapon()
{
	weapon->level = 30;
}

void GrenadeBuilder::SetmaxBulletsInMagazine()
{
	weapon->maxBulletsInMagazine = 6;
}

void GrenadeBuilder::SetdamageFromBullets()
{
	weapon->damageFromBullets = 70;
}

void GrenadeBuilder::SetGunOffset()
{
	//weapon->GunOffset=(120.0f, 18.0f, 36.0f);
}

void GrenadeBuilder::SetCountBullet()
{
	weapon->countBullets = weapon->maxBulletsInMagazine * 4;
}

void GrenadeBuilder::SetMagazineEmptySound()
{
	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/Grenade/GrenadeLauncher_Raise_Cue.GrenadeLauncher_Raise_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->EmptyMagazineSound = Sound.Object;
	}
}

void GrenadeBuilder::SetReloadSound()
{

	static ConstructorHelpers::FObjectFinder<USoundBase>Sound(TEXT("'/Game/Sounds/Weapons/Grenade/GrenadeLauncher_ReloadInsert_Cue.GrenadeLauncher_ReloadInsert_Cue'"));

	if (Sound.Succeeded())
	{
		weapon->ReloadSound = Sound.Object;
	}
}

void GrenadeBuilder::SetMaxCountBullet()
{
	weapon->maxCountBullets = weapon->countBullets;
}

void GrenadeBuilder::CreateWeapon()
{
	WeaponBuilder::CreateWeapon();

	GrenadeBuilder::SetmaxBulletsInMagazine();
	GrenadeBuilder::SetdamageFromBullets();
	GrenadeBuilder::SetLevelOfWeapon();
	GrenadeBuilder::SetFireSound();
	GrenadeBuilder::SetMuzzleOffset();
	GrenadeBuilder::SetCountBullet();
	GrenadeBuilder::SetMagazineEmptySound();
	GrenadeBuilder::SetReloadSound();
	GrenadeBuilder::SetMaxCountBullet();


	weapon->currentBulletsInMagazine = weapon->maxBulletsInMagazine;

}
#pragma endregion
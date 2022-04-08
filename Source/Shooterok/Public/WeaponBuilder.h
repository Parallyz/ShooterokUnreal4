// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Shooterok/Public/Weapon.h>

/**
 *
 */
class  WeaponBuilder
{
protected:
	Weapon* weapon;
	
public:
	
	WeaponBuilder();
	~WeaponBuilder();
	
	virtual void SetMuzzleOffset() = 0;
	virtual void SetFireSound() = 0;
	virtual void SetLevelOfWeapon() = 0;
	virtual void SetmaxBulletsInMagazine() = 0;
	virtual void SetdamageFromBullets() = 0;
	virtual void SetGunOffset() = 0;
	virtual void SetCountBullet() = 0;


	

	
	virtual Weapon* GetWeapon();
	virtual void CreateWeapon();
};

class  RifleBuilder : public WeaponBuilder 
{
public:
	 
	 void SetMuzzleOffset();

	 void SetFireSound() ;
	 void SetLevelOfWeapon() ;
	 void SetmaxBulletsInMagazine() ;
	 void SetdamageFromBullets();
	 void SetGunOffset() ;
	  void SetCountBullet();


	 void CreateWeapon();
};
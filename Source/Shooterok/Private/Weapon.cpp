// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

Weapon::Weapon()
{
	//FireSound = new USoundBase();
}

Weapon::~Weapon()
{

}

Weapon::Weapon(int _damage)
{
	this->damageFromBullets = _damage;
	
}

bool Weapon::MagazineIsNotEmpty()
{
	return currentBulletsInMagazine > 0;
}

bool Weapon::HaveBullets()
{
	return countBullets > 0;
}
bool Weapon::IsMagazineFool()
{
	return currentBulletsInMagazine == maxBulletsInMagazine;
}
Weapon* Weapon::Clone(Weapon* _weapon)
{
	Weapon* copy = new Weapon();

	copy->countBullets = _weapon->countBullets;
	
	copy->level = _weapon->level;

	copy->maxBulletsInMagazine = _weapon->level;

	copy->damageFromBullets = _weapon->damageFromBullets;

	copy->currentBulletsInMagazine =  _weapon->damageFromBullets;

	return copy;
		

}
bool Weapon::Fire()
{
	if (MagazineIsNotEmpty())
	{
		currentBulletsInMagazine--;
		
		return true;
	}
	return false;
}

bool Weapon::Reload()
{
	if (HaveBullets() && !IsMagazineFool())
	{

		if (countBullets <= maxBulletsInMagazine)
		{
			currentBulletsInMagazine = countBullets;
			countBullets = 0;
		}
		else if (countBullets > maxBulletsInMagazine)
		{
			countBullets -= maxBulletsInMagazine - currentBulletsInMagazine;
			currentBulletsInMagazine = maxBulletsInMagazine;
		}
		
		return true;
	}
	return false;
}

void Weapon::SetDamage(int _damage)
{
	this->damageFromBullets = _damage;
}







// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

Weapon::Weapon()
{
	//FireSound = new USoundBase();
}

Weapon::~Weapon()
{

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

		if (countBullets < maxBulletsInMagazine)
		{
			currentBulletsInMagazine = countBullets;
			countBullets = 0;
		}
		else {

			countBullets -= maxBulletsInMagazine;
			currentBulletsInMagazine = maxBulletsInMagazine;
		}
		return true;
	}
	return false;
}







// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{

}

Weapon::Weapon(USkeletalMeshComponent* _GunMesh)
{
	GunMesh = _GunMesh;

	check(GunMesh != nullptr);



	/*static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/Mesh/FPSArms_D_Mat.FPSArms_D_Mat'"));
	if (Material.Succeeded())
	{
		auto MaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, FPSMesh);
		FPSMesh->SetMaterial(0, MaterialInstance);
		FPSMesh->SetMaterial(1, MaterialInstance);


	}*/


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







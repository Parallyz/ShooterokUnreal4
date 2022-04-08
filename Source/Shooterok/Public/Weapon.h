// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"

/**
 * 
 */

class SHOOTEROK_API Weapon
{

public:
	Weapon();
	~Weapon();
	
	

	// Gun muzzle offset from the camera location.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;


	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int maxBulletsInMagazine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int damageFromBullets;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int currentBulletsInMagazine;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		int countBullets;

	bool Fire();
	bool Reload();

	bool MagazineIsNotEmpty();

	bool HaveBullets();
	bool IsMagazineFool();
};

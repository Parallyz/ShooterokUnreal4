// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include <Shooterok/Public/Weapon.h>
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTEROK_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	int killsEnemy;
	int Bulletcount;
	int bulletInMagazine;
	float baseTurnRate;
	float baseUpRate;
	float baseVolume;
	int exp;
	int Level;

	int hp;
	FVector lastHeroLocation;
	Weapon* lastHeroWeapon;


	UMySaveGame();

	//void SetKills(int _killsEnemy);
	//void SetBulletcount(int _Bulletcount);
	//void SetbulletInMagazine(int _bulletInMagazine);
	//void SetbaseTurnRate(float _baseTurnRate);
	//void SetbaseUpRate(float _baseUpRate);
	//void SetbaseVolume(float _baseVolume);
	//void Setexp(int  _exp);
	//void SetLevel(int _Level);
	//void Sethp(int hp);
	//void SetlastHeroLocation(FVector lastHeroLocation);
	//void SetWeapon(Weapon* lastHeroWeapon);


	
};

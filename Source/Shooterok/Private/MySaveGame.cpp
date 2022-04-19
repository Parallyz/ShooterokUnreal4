// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"

UMySaveGame::UMySaveGame()
{
	this->baseTurnRate = 45.f;

	this->killsEnemy=0;
	this->Bulletcount=0;
	this->bulletInMagazine=0;
	this->baseUpRate=45.f;
	this->baseVolume=1.f;
	this->exp=0;
	this->Level=1;
	this->hp=1;
	this->lastHeroLocation=FVector(0.0f, 0.0f, 0.0f);
	
}
//
//void UMySaveGame::SetKills(int _killsEnemy)
//{
//	this->killsEnemy = _killsEnemy;
//}
//
//void UMySaveGame::SetBulletcount(int _Bulletcount)
//{
//	this->Bulletcount = _Bulletcount;
//
//}
//
//void UMySaveGame::SetbulletInMagazine(int _bulletInMagazine)
//{
//	this->bulletInMagazine = _bulletInMagazine;
//
//}
//
//void UMySaveGame::SetbaseTurnRate(float _baseTurnRate)
//{
//	this->baseTurnRate = _baseTurnRate;
//
//}
//
//void UMySaveGame::SetbaseUpRate(float _baseUpRate)
//{
//	this->baseUpRate = _baseUpRate;
//
//}
//
//void UMySaveGame::SetbaseVolume(float _baseVolume)
//{
//	this->baseVolume = _baseVolume;
//
//}
//
//void UMySaveGame::Setexp(int _exp)
//{
//	this->exp = _exp;
//
//}
//
//void UMySaveGame::SetLevel(int _Level)
//{
//	this->Level = _Level;
//
//}
//
//void UMySaveGame::Sethp(int _hp)
//{
//	this->hp = _hp;
//
//}
//
//void UMySaveGame::SetlastHeroLocation(FVector _lastHeroLocation)
//{
//	this->lastHeroLocation = _lastHeroLocation;
//
//}
//
//void UMySaveGame::SetWeapon(Weapon* _lastHeroWeapon)
//{
//	this->lastHeroWeapon = _lastHeroWeapon;
//
//}


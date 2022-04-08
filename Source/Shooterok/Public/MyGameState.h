// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Shooterok/Public/Weapon.h>
#include <list>
/**
 * 
 */
class SHOOTEROK_API MyGameState
{
public:
	MyGameState();
	~MyGameState();

	int _killsEnemy;
	int _hp;
	FVector lastHeroLocation;
	Weapon *lastHeroWeapon;
	


};

class SHOOTEROK_API GameMemento
{
private:
	 MyGameState* _state;
public:
	GameMemento();
	GameMemento(MyGameState* state);

	~GameMemento();


	MyGameState* getMemento();

};
class SHOOTEROK_API GameOriginator
{
	MyGameState* _state;
public:
	GameOriginator();
	~GameOriginator();


	void Play();
	GameMemento* SaveGame();
	void LoadGame(GameMemento memento);


};


class SHOOTEROK_API Caretaker
{
private:
	GameOriginator _game;
	std::list<GameMemento> _quickSaves;

public:

	Caretaker();
	~Caretaker();

	void Shoot();
	void F5();
	void F9();


};


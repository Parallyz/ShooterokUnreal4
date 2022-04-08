// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameState.h"

#pragma region GameSate



MyGameState::MyGameState()
{
}

MyGameState::~MyGameState()
{
}
#pragma endregion

#pragma region GameMemento

GameMemento::GameMemento()
{
}

GameMemento::GameMemento(MyGameState* state)
{
	_state = state;
}

GameMemento::~GameMemento()
{
}

MyGameState* GameMemento::getMemento()
{
	return _state;
}
#pragma endregion

#pragma region GameOriginator



GameOriginator::GameOriginator()
{
	
}

GameOriginator::~GameOriginator()
{
}

void GameOriginator::Play()
{
	_state = new MyGameState();
}

GameMemento* GameOriginator::SaveGame()
{
	return new GameMemento(_state);
}

void GameOriginator::LoadGame(GameMemento memento)
{
	_state = memento.getMemento();
}
#pragma endregion

#pragma region Caretaker

void Caretaker::Shoot()
{
	_game.Play();
}

void Caretaker::F5()
{
	_quickSaves.push_back(*_game.SaveGame());
}

void Caretaker::F9()
{
	_game.LoadGame(_quickSaves.back());
}
#pragma endregion



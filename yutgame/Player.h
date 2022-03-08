#pragma once
#include<string>
#include<iostream>
#include<array>
#include<random>
#include"Horse.h"
//#include"DrawMenu.h"

using namespace std;
class Player 
{
public:
	//DrawMenu drawMenu;
	string playerName;
	int playerPosition[21][21];
	int throwCount;
	int haveHolseCount;
	int yutCount;
	int currentHorseIdx;
	string yutPrint;
	//int horseState;
	array<int, 5> yutState;
	Horse horse[3];
public:
	Player();
	void ThrowYut(Map& map);
	//void MoveHorse(int yutCount);
	void GetHorseCount();
	void SetPlayerName();
	void CreateHorse();
	string GetYutCount(int yutCount);
	int GetRandomNumber();
	void SelectHorse();
};
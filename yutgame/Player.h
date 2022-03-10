#pragma once
#include<string>
#include<iostream>
#include<array>
#include<random>
#include "Map.h"
#include"Horse.h"

using namespace std;
class Player 
{

public:
	string playerName;
	int playerPosition[21][21];
	int throwCount;
	int haveHolseCount;
	int yutCount;
	int currentHorseIdx;
	string yutPrint;
	array<int, 5> yutState;
	Map map;
	Horse horse[3];
public:
	Player();
	void ThrowYut(Map& map);
	void GetHorseCount();
	void SetPlayerName();
	void CreateHorse();
	void SelectHorse();
	string GetYutCount(int yutCount);
	int GetRandomNumber();
};
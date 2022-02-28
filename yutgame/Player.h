#pragma once
#include<string>
#include<iostream>
#include<array>
#include<random>
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
	string GetYutCount(int yutCount);
	int GetRandomNumber();
};
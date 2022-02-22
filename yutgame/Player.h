#pragma once
#include<string>
#include<iostream>
#include<array>
#include<random>
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
	array<int, 5> yutState;
public:
	Player();
	void ThrowYut();
	void MoveHorse();
	void SetPlayerName();
	string GetYutCount(int yutCount);
	int GetRandomNumber();
};
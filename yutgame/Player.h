#pragma once
#include<string>
#include<iostream>
using namespace std;
class Player
{
public:
	string playerName;
	int playerPosition[21][21];
	int throwCount;
	int haveholseCount;
public:
	Player();
	void Throw_Yut();
	void Move_Player();
	void Set_PlayerName();
};
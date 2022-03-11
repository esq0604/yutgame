#pragma once
#include<string>
#include<iostream>
#include<array>
#include<random>
#include<conio.h>
#include "Map.h"
#include"Horse.h"
#include "Util.h"

enum eKEY
{
	KEY_LEFT = 75,
	KEY_RIGHT = 77,
	KEY_ENTER =13,
};
using namespace std;
class Player 
{
private:
	const int MIN_HORSE_IDX;
	const int MAX_HORSE_IDX;
	const int MAX_HORSE_POS;
	const int MIN_HORSE_POS;
	const int CURSOR_POINT_COLNUM;
	const int CURSOR_POINT_ROWNUM;
public:
	string playerName;
	string yutPrint;
	int playerPosition[21][21];
	int throwCount;
	int haveHolseCount;
	int yutCount;
	int currentHorseIdx;
	int selectHorseIdx;
	array<int, 5> yutState;
	Map map;
	Util util;
	Horse horse[3];
public:
	Player();
	void ThrowYut(Map& map);
	int GetHorseCount();
	void SetPlayerName();
	void CreateHorse();
	void SelectHorse();
	void SelectHorseCurssor(Horse *horse);
	string GetYutCount(int yutCount);
	int GetRandomNumber();
	void CheckHorseInMap(Map &map);
};
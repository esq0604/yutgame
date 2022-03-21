#pragma once
#include<string>
#include<iostream>
#include<array>
#include<random>
#include<conio.h>

#include "Map.h"
#include "Util.h"
#include"Horse.h"
#include"DrawMenu.h"
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
	const int ON_ONE_HORSE;
	const int ON_TWO_HORSE;
	const int ON_THREE_HORSE;
	int throwCount;
	int yutCount;
	int currentHorseIdx;
	int selectHorseIdx;
	int samePosHorseNum;
	array<int, 5> yutState;
	string playerName;
	string yutPrint;
	Map map;
	Util util;
	Horse* horse[3];
	DrawMenu menu;
	//int playerPosition[21][21];
	//void SelectHorse();
	//void SelectHorseCurssor(Horse* horse);
	string GetYutCount(int yutCount);
	int GetRandomNumber();
	int GetHorseInSamePos(Map& map, Horse horse);

public:
	int haveHolseCount;

public:
	Player();
	void ThrowYut(Map& map);
	int GetHorseCount();
	void SetPlayerName();
	void CreateHorse();
	void OnHorseSelect();
	void GetPlayerHaveHorse(int playerNum);
};
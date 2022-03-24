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
	static const int MIN_HORSE_IDX=0;
	static const int MAX_HORSE_IDX=2;
	static const int MAX_HORSE_POS=20;
	static const int MIN_HORSE_POS=0;
	static const int CURSOR_POINT_COLNUM=1;
	static const int CURSOR_POINT_ROWNUM=5;
	static const int ON_ONE_HORSE=1;
	static const int ON_TWO_HORSE=2;
	static const int ON_THREE_HORSE=3;
	static const int OFF_HORSE=0;
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
	Horse horse[3];
	DrawMenu menu;
	//int playerPosition[21][21];
	//void SelectHorse();
	//void SelectHorseCurssor(Horse* horse);
	string GetYutCount(int yutCount);
	int GetRandomNumber();
	void GetHorseInSamePos(Map& map, Horse horse);

public:
	int haveHolseCount;

public:
	Player();
	void ThrowYut(Map& map);
	int GetHorseCount();
	void SetPlayerName(int playNum);
	void CreateHorse();
	void OnHorseSelect();
	void GetPlayerHaveHorse(int playerNum);
	void MoveHorse(Map& map, Horse* horse);

};
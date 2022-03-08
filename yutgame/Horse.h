#pragma once
#include"Map.h"
#include"Util.h"
//#include"DrawMenu.h"
class Horse
{
public:
	Map map;
	Util util;
	//DrawMenu drawMenu;
	bool horseInMap=false;
	bool firstShortRoad;
	bool secondShortRoad;
	bool centerShortRoad;
	bool nomalRoad;
	bool horseOnState;
	int currentRowPos,currentColPos;

public:
	Horse();
	void MoveHorseSystem(int yutCount, Map& map, int currentRowPos, int currentColPos);
	void SetHorsePos(int row, int col);
	void MoveHorse(Map& map, int currentRowPos, int currentColPos, int loopTime);
	//void SetShortRoad(int currentRowPos, int currentColPos);
	void MoveShortHorse(Map& map, int currentRowPos, int currentColPos, int loopTime);
};
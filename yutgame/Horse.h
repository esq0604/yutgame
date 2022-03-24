#pragma once
#include"DrawMenu.h"
#include"Map.h"
#include"Util.h"
class Horse
{
private:
	static const int ON_HORSE=1;
	static const int ON_TWO_HORSE=2;
	static const int OFF_HORSE=0;
	static const int MOVE_HORSE=5;
	static const int MAX_POS=20;
	static const int MIN_POS=0;
	static const int CENTER_POS=10;
	static const int OUT_ROW_POS=25;
	static const int OUT_COL_POS=20;
	char inputShortRoad;
	bool firstShortRoad;
	bool secondShortRoad;
	bool centerShortRoad;
	bool nomalRoad;
	bool horseInMap = false;
	//int horseNum;
	Map map;
	Util util;
	DrawMenu menu;
	void SetHorsePos(int row, int col);
	void MoveShortHorse(Map& map, int currentRowPos, int currentColPos, int loopTime);
public:
	int currentRowPos,currentColPos;
	void MoveHorsePos(Map& map, int currentRowPos, int currentColPos, int loopTime);
	void MoveHorseSystem(int yutCount, Map& map, int currentRowPos, int currentColPos);
	bool GetShortRoadSelect();
	Horse();

};
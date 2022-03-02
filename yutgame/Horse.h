#pragma once
#include"Map.h"
#include"Util.h"
class Horse
{
public:
	Map map;
	Util util;
	bool horseInMap=false;
	int currentRowPos,currentColPos;

public:
	Horse();
	void MoveHorseSystem(int yutCount, Map& map, int currentRowPos, int currentColPos);
	void SetHorsePos(int row, int col);
	void MoveHorse(Map& map, int currentRowPos, int currentColPos, int loopTime);
};
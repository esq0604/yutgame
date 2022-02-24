#pragma once
#include"Map.h"
#include"Util.h"
class Horse
{
public:
	Map map;
	Util util;
	bool horseState=false;
	int currentRowPos,currentColPos;

public:
	//Horse();
	void MoveHorse(int yutCount, Map& map);
	//void SetHorsePos(int yutCount, int& row, int& col);
};
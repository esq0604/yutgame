#pragma once
#include"Map.h"
#include"Util.h"
class Horse
{
public:
	Map map;
	Util util;
	bool horseState=false;
	int currentRowPos=99,currentColPos=99;

public:
	//Horse();
	void MoveHorse(int yutCount, Map& map);
	void SetHorsePos(int row, int col);
};
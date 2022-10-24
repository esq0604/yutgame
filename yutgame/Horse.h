#pragma once
#include"DrawMenu.h"
#include"Map.h"
#include"Util.h"
class Horse
{
public:
	int n_horse; //말 이 겹쳤는지 이걸로 움직임.
	struct Pos
	{
		int x;
		int y;
	};
	Pos pos;
private:
	static const int ON_HORSE=1;
	static const int ON_TWO_HORSE=2;
	const wchar_t OFF_HORSE='0';
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
	void GetSamePosHorse(Map& map);
	void SetHorsePos(int row, int col);
	void MoveShortHorse(Map& map, Pos pos, int loopTime);
	//void Set_n_horse(Map& map, Horse& horse);
public:
	
	void MoveHorsePos(Map& map, Pos pos, int loopTime);
	void MoveHorseSystem(const int yutCount, Map& map, Pos pos);
	bool GetShortRoadSelect();
	Pos GetHorsePos();
	Horse();

};
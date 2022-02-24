#include "Horse.h"

void Horse::MoveHorse(int yutCount,Map& map)
{
	map.MAP[21][21];
	//탐색 후 , 위치 옮기기
	//cout <<"yutCount in Horse::MoveHorse " << yutCount;
	switch (yutCount)
	{
	case 0:
		//if(map.colIdx==20&& map.rowIdx<=20)
		map.MAP[5][20] = 1;
		break;
	case 1:
		
		map.MAP[20][20] = 1;
		break;
	case 2:
		map.MAP[15][20] = 1;
		break;
	case 3:
		map.MAP[10][20] = 1;
		break;
	case 4:
		map.MAP[5][20] = 1;
		break;
	}
	util.SetCursurPoint(0, 0);
	//map.DrawMap();
}
//void Horse::SetHorsePos(int yutCount,int& row, int& col)
//{
//	switch (yutCount)
//	{
//	case 0:
//		this->map.MAP[5][20] = 1;
//		break;
//	case 1:
//
//		this->map.MAP[20][20] = 1;
//		break;
//	case 2:
//		this->map.MAP[15][20] = 1;
//		break;
//	case 3:
//		this->map.MAP[10][20] = 1;
//		break;
//	case 4:
//		this->map.MAP[5][20] = 1;
//		break;
//	}
//}
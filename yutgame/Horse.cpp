#include "Horse.h"

void Horse::MoveHorse(int yutCount,Map& map)
{
	map.MAP[21][21];
	switch (yutCount)
	{
	case 0:
		if (currentColPos == 99 && currentRowPos == 99)
		{
			map.MAP[5][20] = 1;
			SetHorsePos(5, 20);
		}
		break;
	case 1:
		if (currentColPos == 99 && currentRowPos == 99)
		{
			map.MAP[20][20] = 1;
			SetHorsePos(20, 20);
		}
		break;
	case 2:
		if (currentColPos == 99 && currentRowPos == 99)
		{
			map.MAP[15][20] = 1;
			SetHorsePos(5, 20);
		}
		break;
	case 3:

		if (currentColPos == 99 && currentRowPos == 99)
		{
			map.MAP[10][20] = 1;
			SetHorsePos(10, 20);
		}
			break;
	case 4:
		if (currentColPos == 99 && currentRowPos == 99)
		{
			map.MAP[5][20] = 1;
			SetHorsePos(5, 20);
		}
		break;
	}
	util.SetCursurPoint(0, 0);

}
void Horse::SetHorsePos(int row, int col)
{
	currentRowPos = row;
	currentColPos = col;
}
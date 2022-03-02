#include "Horse.h"

Horse::Horse()
{
	//�ʱⰪ�� 99�� �ְ�, �ǿ� �÷����� ����.
	//horseState�� �Ǻ��Ͽ� if������ �־ �ɵ�?
	currentRowPos = 99;
	currentColPos = 99;
}

void Horse::MoveHorseSystem(int yutCount,Map& map,int currentRowPos,int currentColPos)
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
		MoveHorse(map, currentRowPos, currentColPos,4);
		break;
	case 1:
		if (currentColPos == 99 && currentRowPos == 99)
		{
			map.MAP[20][20] = 1;
			SetHorsePos(20, 20);
		}
		MoveHorse(map, currentRowPos, currentColPos, 1);
		break;
	case 2:
		if (currentColPos == 99 && currentRowPos == 99)
		{
			map.MAP[15][20] = 1;
			SetHorsePos(5, 20);
		}
		MoveHorse(map, currentRowPos, currentColPos, 2);
		break;
	case 3:

		if (currentColPos == 99 && currentRowPos == 99)
		{
			map.MAP[10][20] = 1;
			SetHorsePos(10, 20);
		}
		MoveHorse(map, currentRowPos, currentColPos, 3);
			break;
	case 4:
		if (currentColPos == 99 && currentRowPos == 99)
		{
			map.MAP[5][20] = 1;
			SetHorsePos(5, 20);
		}
		MoveHorse(map, currentRowPos, currentColPos, 4);
		break;
	}
	util.SetCursurPoint(0, 0);

}
void Horse::SetHorsePos(int row, int col)
{
	currentRowPos = row;
	currentColPos = col;
}

//
void Horse::MoveHorse(Map& map, int currentRowPos, int currentColPos,int loopTime)
{
	
	if (currentColPos == 20 && (currentRowPos <= 20 || currentRowPos >= 0))
	{
		map.MAP[currentRowPos][currentColPos] = 0;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentRowPos > 0)
				currentRowPos -= 5;
			else
				currentColPos -= 5;
		}
		map.MAP[currentRowPos][currentColPos] = 1;
		SetHorsePos(currentRowPos, currentColPos);
	}
	else if (currentRowPos == 0 && (currentColPos <= 20 || currentColPos >= 0))
	{
		map.MAP[currentRowPos][currentColPos] = 0;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentColPos > 0)
				currentColPos -= 5;
			else
				currentRowPos += 5;
		}
		map.MAP[currentRowPos][currentColPos] = 1;
		SetHorsePos(currentRowPos, currentColPos);
	}
	else if (currentColPos == 0 && (currentRowPos <= 20 || currentRowPos >= 0))
	{
		map.MAP[currentRowPos][currentColPos] = 0;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentRowPos < 20)
				currentRowPos += 5;
			else
				currentColPos += 5;
		}
		map.MAP[currentRowPos][currentColPos] = 1;
		SetHorsePos(currentRowPos, currentColPos);
	}
	else if (currentRowPos == 20 && (currentColPos <= 20 || currentColPos >= 0))
	{
		map.MAP[currentRowPos][currentColPos] = 0;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentColPos < 20)
				currentColPos += 5;
		}
		map.MAP[currentRowPos][currentColPos] = 1;
		SetHorsePos(currentRowPos, currentColPos);
	}
}

//������ �̵� 
void Horse::MoveCrossHorse(Map& map, int currentRowPos, int currentColPos, int loopTime)
{
	//(0,20)�϶�
	if (currentRowPos == 0 && currentColPos == 20)
	{
		map.MAP[currentRowPos][currentColPos] = 0;
		for (int i = 0; i < loopTime; i++)
		{
			currentRowPos += 5;
			currentColPos -= 5;
		}
	}
	//(0,0)�϶�
	else if (currentRowPos == 0 && currentColPos == 0)
	{
		for (int i = 0; i < loopTime; i++)
		{
			currentRowPos += 5;
			currentColPos += 5;
		}
	}
}
void Horse::MoveCenterHorse(Map& map, int currentRowPos, int currentColPos, int loopTime)
{
	if (currentRowPos == 10 && currentColPos == 10)
	{
		map.MAP[currentRowPos][currentColPos] = 0;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentColPos < 20 && currentRowPos < 20)
			{
				currentColPos += 5;
				currentRowPos += 5;
			}
		}
	}
}

//�������� �������� �ش縻�� �����ִ��Լ� - delete�ؾ��ҵ�??
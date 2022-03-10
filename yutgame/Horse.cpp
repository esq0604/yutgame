#include "Horse.h"

Horse::Horse():ON_HORSE(1),OFF_HORSE(0), MOVE_HORSE(5), MAX_POS(20), MIN_POS(0), CENTER_POS(10),OUT_ROW_POS(21), OUT_COL_POS(20), ON_TWO_HORSE(2)
{
	//�ʱⰪ�� 99�� �ְ�, �ǿ� �÷����� ����.
	//horseState�� �Ǻ��Ͽ� if������ �־ �ɵ�?
	currentRowPos = OUT_ROW_POS;
	currentColPos = OUT_COL_POS;
	firstShortRoad = false;
	secondShortRoad = false;
	centerShortRoad = false;
	nomalRoad = true;
}

//���� ó���� �ö󰡴� ���� current���� �̿��Ѱ��� �ƴ϶� 
//ó������ ���� ���� ǥ�⺯ȭ�� �Ͼ�� ����.����������� .
void Horse::MoveHorseSystem(int yutCount,Map& map,int currentRowPos,int currentColPos)
{
	//map.MAP[ROW][COL];
	//CheckHorseNumOnPos(map);
	switch (yutCount)
	{
	case 0:
		if (currentColPos == OUT_COL_POS && currentRowPos == OUT_COL_POS)
		{
			/*map.MAP[5][20] = ON_HORSE;
			SetHorsePos(5, 20);*/
			MoveHorse(map, currentRowPos, currentColPos, 4);
		}
		//MoveHorse(map, currentRowPos, currentColPos,4);
		break;
	case 1:
		if (currentColPos == OUT_COL_POS && currentRowPos == OUT_COL_POS)
		{
			/*map.MAP[20][20] = ON_HORSE;
			SetHorsePos(20, 20);*/
			MoveHorse(map, currentRowPos, currentColPos, 1);
		}
		//MoveHorse(map, currentRowPos, currentColPos, 1);
		break;
	case 2:
		if (currentColPos == OUT_COL_POS && currentRowPos == OUT_COL_POS)
		{
			/*map.MAP[15][20] = ON_HORSE;
			SetHorsePos(15, 20);*/
			MoveHorse(map, currentRowPos, currentColPos, 2);
		}
		//MoveHorse(map, currentRowPos, currentColPos, 2);
		break;
	case 3:

		if (currentColPos == OUT_COL_POS && currentRowPos == OUT_COL_POS)
		{
			/*map.MAP[10][20] = ON_HORSE;
			SetHorsePos(10, 20);*/
			MoveHorse(map, currentRowPos, currentColPos, 3);
		}
		//MoveHorse(map, currentRowPos, currentColPos, 3);
			break;
	case 4:
		if (currentColPos == OUT_COL_POS && currentRowPos == OUT_COL_POS)
		{
			/*map.MAP[5][20] = ON_HORSE;
			SetHorsePos(5, 20);*/
			MoveHorse(map, currentRowPos, currentColPos, 4);

		}
		//MoveHorse(map, currentRowPos, currentColPos, 4);
		break;
	}
	util.SetCursurPoint(0, 0);

}
void Horse::SetHorsePos(int row, int col)
{
	this->currentRowPos = row;
	this->currentColPos = col;
}

void Horse::MoveHorse(Map& map, int currentRowPos, int currentColPos,int loopTime)
{
	
	MoveShortHorse(map, currentRowPos, currentColPos, loopTime);
	if ((currentColPos == MAX_POS && (currentRowPos <= MAX_POS )
	{
		map.MAP[currentRowPos][currentColPos] = OFF_HORSE;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentRowPos > MIN_POS)
				currentRowPos -= MOVE_HORSE;
			else
				currentColPos -= MOVE_HORSE;
		}

		//���� �ű� �� ��ġüũ 
		if (currentRowPos == 0 && currentColPos == MAX_POS)
		{
			firstShortRoad = true;
			nomalRoad = false;
		}
		SetHorsePos(currentRowPos, currentColPos);
		if (map.MAP[currentRowPos][currentColPos] > 0)
			CheckHorseNumOnPos(map);
		else
			map.MAP[currentRowPos][currentColPos] = ON_HORSE;
	}

	else if (currentRowPos == MIN_POS && (currentColPos <= MAX_POS || currentColPos >= MIN_POS) && nomalRoad)
	{
		map.MAP[currentRowPos][currentColPos] = OFF_HORSE;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentColPos > MIN_POS)
				currentColPos -= MOVE_HORSE;
			else
				currentRowPos += MOVE_HORSE;
		}

		if (currentRowPos == MIN_POS && currentColPos == MIN_POS)
		{
			secondShortRoad = true;
			nomalRoad = false;
		}
		SetHorsePos(currentRowPos, currentColPos);
		if (map.MAP[currentRowPos][currentColPos] > 0)
			CheckHorseNumOnPos(map);
		else
			map.MAP[currentRowPos][currentColPos] = ON_HORSE;
	}

	else if (currentColPos == MIN_POS && (currentRowPos <= MAX_POS || currentRowPos >= MIN_POS)&& nomalRoad)
	{
		map.MAP[currentRowPos][currentColPos] = OFF_HORSE;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentRowPos < MAX_POS)
				currentRowPos += MOVE_HORSE;
			else
				currentColPos += MOVE_HORSE;
		}

		SetHorsePos(currentRowPos, currentColPos);
		if (map.MAP[currentRowPos][currentColPos] > 0)
			CheckHorseNumOnPos(map);
		else
			map.MAP[currentRowPos][currentColPos] = ON_HORSE;
	}

	else if (currentRowPos == MAX_POS && (currentColPos <= MAX_POS || currentColPos >= MIN_POS)&& nomalRoad)
	{
		map.MAP[currentRowPos][currentColPos] = OFF_HORSE;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentColPos < MAX_POS)
				currentColPos += MOVE_HORSE;
		}
		SetHorsePos(currentRowPos, currentColPos);
		if (map.MAP[currentRowPos][currentColPos] > 0)
			CheckHorseNumOnPos(map);
		else
			map.MAP[currentRowPos][currentColPos] = ON_HORSE;
	}
}

//void Horse::SetShortRoad(int currentRowPos, int currentColPos)
//{
//	//(0,20)�϶�
//	if (currentRowPos == 0 && currentColPos == 20) 
//	{
//		firstShortRoad = true;
//		
//	}
//	//(0,0)�϶�
//	else if (currentRowPos == 0 && currentColPos == 0)
//	{
//		secondShortRoad = true;
//	
//	}
//	else if (currentRowPos == 10 && currentColPos == 10)
//	{
//		centerShortRoad = true;
//	}
//}
void Horse::MoveShortHorse(Map& map, int currentRowPos, int currentColPos, int loopTime)
{
	if (firstShortRoad)
	{
		map.MAP[currentRowPos][currentColPos] = OFF_HORSE;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentRowPos < MAX_POS && currentColPos>MIN_POS)
			{
				currentRowPos += MOVE_HORSE;
				currentColPos -= MOVE_HORSE;
			
			}
			else if (currentRowPos == MAX_POS && currentColPos == MIN_POS)
			{
				//false�� �ٲ㼭 for����ŭ ���ư����� ����. 
				nomalRoad = true;
				firstShortRoad = false;
				currentColPos += MOVE_HORSE *(loopTime-i);
			}
			
		}
		

		if (currentRowPos == CENTER_POS && currentColPos == CENTER_POS)
		{
			firstShortRoad = false;
			centerShortRoad = true;
		}
		
		map.MAP[currentRowPos][currentColPos] = ON_HORSE;
		SetHorsePos(currentRowPos, currentColPos);
	}
	else if (secondShortRoad)
	{
		map.MAP[currentRowPos][currentColPos] = OFF_HORSE;
		for (int i = 0; i < loopTime; i++)
		{
		currentRowPos += MOVE_HORSE;
		currentColPos += MOVE_HORSE;
		}

		if (currentRowPos == CENTER_POS && currentColPos == CENTER_POS)
		{ 
			secondShortRoad = false;
			centerShortRoad = true;
		}
		map.MAP[currentRowPos][currentColPos] = ON_HORSE;
		SetHorsePos(currentRowPos, currentColPos);
	}
	else if (centerShortRoad)
	{
		map.MAP[currentRowPos][currentColPos] = OFF_HORSE;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentColPos < MAX_POS && currentRowPos < MAX_POS)
			{
				currentColPos += MOVE_HORSE;
				currentRowPos += MOVE_HORSE;
			}
		}
		map.MAP[currentRowPos][currentColPos] = ON_HORSE;
		SetHorsePos(currentRowPos, currentColPos);
	}
}
void Horse::CheckHorseNumOnPos(Map& map)
{
	/*if (map.MAP[currentRowPos][currentColPos] == OFF_HORSE)
	{
		map.MAP[currentRowPos][currentColPos] = ON_HORSE;
	}*/
	if (map.MAP[currentRowPos][currentColPos] == ON_HORSE)
	{
		map.MAP[currentRowPos][currentColPos]++;
	}
	else if (map.MAP[currentRowPos][currentColPos] == ON_TWO_HORSE)
	{
		map.MAP[currentRowPos][currentColPos]++;
	}

}


	//���� �ڱⰡ ������ ���ۿ� �𸥴� , ���� �����ǿ� ���� � �ִ����� �÷��̾ �����ؾ��ҰŰ���.

//�������� �������� �ش縻�� �����ִ��Լ� - delete�ؾ��ҵ�??
#include "Horse.h"
Horse::Horse()
{
	//�ʱⰪ�� 99�� �ְ�, �ǿ� �÷����� ����.
	//horseState�� �Ǻ��Ͽ� if������ �־ �ɵ�?
	currentRowPos = OUT_ROW_POS;
	currentColPos = OUT_COL_POS;
	firstShortRoad = false;
	secondShortRoad = false;
	centerShortRoad = false;
	nomalRoad = true;
	n_horse = 1;
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
		MoveHorsePos(map, currentRowPos, currentColPos, 4);
		break;
	case 1:
		MoveHorsePos(map, currentRowPos, currentColPos, 1);
		break;
	case 2:
		MoveHorsePos(map, currentRowPos, currentColPos, 2);
		break;
	case 3:
		MoveHorsePos(map, currentRowPos, currentColPos, 3);
		break;
	case 4:
		MoveHorsePos(map, currentRowPos, currentColPos, 4);
		break;
	}
	util.SetCursurPoint(0, 0);

}
void Horse::SetHorsePos(int row, int col)
{
	this->currentRowPos = row;
	this->currentColPos = col;
}

void Horse::MoveHorsePos(Map& map, int currentRowPos, int currentColPos,int loopTime)
{
	
	MoveShortHorse(map, currentRowPos, currentColPos, loopTime);
	if ((((currentColPos == MAX_POS) && (currentRowPos <= MAX_POS ))||((currentColPos==OUT_COL_POS)&&(currentRowPos==OUT_ROW_POS)))&&nomalRoad)
	{
		for (int i = 0; i < loopTime; i++)
		{
			if ((currentRowPos > MIN_POS)&&(currentColPos==OUT_COL_POS))
				currentRowPos -= MOVE_HORSE;
			else
				currentColPos -= MOVE_HORSE;
		}
		SetHorsePos(currentRowPos, currentColPos);

		if (currentRowPos == 0 && currentColPos == MAX_POS)
		{
			
			if (GetShortRoadSelect())
			{
				firstShortRoad = true;
				nomalRoad = false;
			}
			cout << " ";
		}
		
	}

	else if ((currentRowPos == MIN_POS && (currentColPos <= MAX_POS || currentColPos >= MIN_POS)) && nomalRoad)
	{
		for (int i = 0; i < loopTime; i++)
		{
			if (currentColPos > MIN_POS)
				currentColPos -= MOVE_HORSE;
			else
				currentRowPos += MOVE_HORSE;
		}
		SetHorsePos(currentRowPos, currentColPos);

		if (currentRowPos == MIN_POS && currentColPos == MIN_POS)
		{
			if (GetShortRoadSelect())
			{
				secondShortRoad = true;
				nomalRoad = false;
			}
		}
	}

	else if (currentColPos == MIN_POS && (currentRowPos <= MAX_POS || currentRowPos >= MIN_POS)&& nomalRoad)
	{
		for (int i = 0; i < loopTime; i++)
		{
			if (currentRowPos < MAX_POS)
				currentRowPos += MOVE_HORSE;
			else
				currentColPos += MOVE_HORSE;
		}
		SetHorsePos(currentRowPos, currentColPos);
		
	}

	else if (currentRowPos == MAX_POS && (currentColPos <= MAX_POS || currentColPos >= MIN_POS)&& nomalRoad)
	{
		for (int i = 0; i < loopTime; i++)
		{
			if (currentColPos < MAX_POS)
				currentColPos += MOVE_HORSE;
		}
		SetHorsePos(currentRowPos, currentColPos);
		
	}
}

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
		
		SetHorsePos(currentRowPos, currentColPos);
	}
	else if (secondShortRoad)
	{
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
		SetHorsePos(currentRowPos, currentColPos);
	}
	else if (centerShortRoad)
	{
		for (int i = 0; i < loopTime; i++)
		{
			if (currentColPos < MAX_POS && currentRowPos < MAX_POS)
			{
				currentColPos += MOVE_HORSE;
				currentRowPos += MOVE_HORSE;
			}
		}
		SetHorsePos(currentRowPos, currentColPos);
	}
}


bool Horse:: GetShortRoadSelect()
{
	menu.DrawShortRoadSelect();
	cin >> inputShortRoad;

	if (inputShortRoad == 'y'||inputShortRoad=='Y')
	{
		return true;
	}
	else if (inputShortRoad == 'n' || inputShortRoad == 'N')
		return false;
	else
		return false;
}

//void Horse::Set_n_horse(Map& map, Horse& horse)
//{
//
//}
//�������� �������� �ش縻�� �����ִ��Լ� - delete�ؾ��ҵ�??
#include"DrawMenu.h"
#include "Horse.h"
Horse::Horse():ON_HORSE(1),OFF_HORSE(0), MOVE_HORSE(5), MAX_POS(20), MIN_POS(0), CENTER_POS(10),OUT_ROW_POS(25), OUT_COL_POS(20), ON_TWO_HORSE(2)
{
	//초기값을 99로 넣고, 판에 올려두지 않음.
	//horseState로 판별하여 if문에서 넣어도 될듯?
	currentRowPos = OUT_ROW_POS;
	currentColPos = OUT_COL_POS;
	firstShortRoad = false;
	secondShortRoad = false;
	centerShortRoad = false;
	nomalRoad = true;
	
}

//현재 처음에 올라가는 값은 current값을 이용한것이 아니라서 
//처음값은 말의 개수 표기변화가 일어나지 않음.수정해줘야함 .
void Horse::MoveHorseSystem(int yutCount,Map& map,int currentRowPos,int currentColPos)
{
	//map.MAP[ROW][COL];
	//CheckHorseNumOnPos(map);
	switch (yutCount)
	{
	case 0:
		MoveHorse(map, currentRowPos, currentColPos, 4);
		break;
	case 1:
		MoveHorse(map, currentRowPos, currentColPos, 1);
		break;
	case 2:
		MoveHorse(map, currentRowPos, currentColPos, 2);
		break;
	case 3:
		MoveHorse(map, currentRowPos, currentColPos, 3);
		break;
	case 4:
		MoveHorse(map, currentRowPos, currentColPos, 4);
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
	if (((currentColPos == MAX_POS) && (currentRowPos <= MAX_POS ))||((currentColPos==OUT_COL_POS)&&(currentRowPos==OUT_ROW_POS)))
	{
		map.MAP[currentRowPos][currentColPos] = OFF_HORSE;
		for (int i = 0; i < loopTime; i++)
		{
			if ((currentRowPos > MIN_POS)&&(currentColPos==OUT_COL_POS))
				currentRowPos -= MOVE_HORSE;
			else
				currentColPos -= MOVE_HORSE;
		}
		map.MAP[currentRowPos][currentColPos] = ON_HORSE;
		SetHorsePos(currentRowPos, currentColPos);

		//말을 옮긴 뒤 위치체크 
		if (currentRowPos == 0 && currentColPos == MAX_POS)
		{
			
			if (GetShortRoadSelect())
			{
				firstShortRoad = true;
				nomalRoad = false;
			}
			cout << " ";
		}
		
		/*if (map.MAP[currentRowPos][currentColPos] > 0)
			CheckHorseNumOnPos(map);
		else*/
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
		map.MAP[currentRowPos][currentColPos] = ON_HORSE;
		SetHorsePos(currentRowPos, currentColPos);

		if (currentRowPos == MIN_POS && currentColPos == MIN_POS)
		{
			secondShortRoad = true;
			nomalRoad = false;
		}
		/*if (map.MAP[currentRowPos][currentColPos] > 0)
			CheckHorseNumOnPos(map);
		else*/
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
		map.MAP[currentRowPos][currentColPos] = ON_HORSE;
		SetHorsePos(currentRowPos, currentColPos);
		/*if (map.MAP[currentRowPos][currentColPos] > 0)
			CheckHorseNumOnPos(map);
		else*/
	}

	else if (currentRowPos == MAX_POS && (currentColPos <= MAX_POS || currentColPos >= MIN_POS)&& nomalRoad)
	{
		map.MAP[currentRowPos][currentColPos] = OFF_HORSE;
		for (int i = 0; i < loopTime; i++)
		{
			if (currentColPos < MAX_POS)
				currentColPos += MOVE_HORSE;
		}
		map.MAP[currentRowPos][currentColPos] = ON_HORSE;
		SetHorsePos(currentRowPos, currentColPos);
		/*if (map.MAP[currentRowPos][currentColPos] > 0)
			CheckHorseNumOnPos(map);
		else*/
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
				//false로 바꿔서 for문만큼 돌아가지가 않음. 
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
	
	if (map.MAP[currentRowPos][currentColPos] == ON_HORSE)
	{
		map.MAP[currentRowPos][currentColPos]++;
	}
	else if (map.MAP[currentRowPos][currentColPos] == ON_TWO_HORSE)
	{
		map.MAP[currentRowPos][currentColPos]++;
	}

}

bool Horse:: GetShortRoadSelect()
{
	menu->DrawShortRoadSelect();
	cin >> inputShortRoad;

	if (inputShortRoad == 'y')
	{
		return true;
	}
	else if (inputShortRoad == 'n')
		return false;
	else
		return false;
}
//종착지에 들어왔으면 해당말을 지워주는함수 - delete해야할듯??
#include "Horse.h"
#include "GameInit.h"
Horse::Horse()
{
	//초기값을 99로 넣고, 판에 올려두지 않음.
	//horseState로 판별하여 if문에서 넣어도 될듯?
	pos.x = OUT_ROW_POS;
	pos.y = OUT_COL_POS;
	firstShortRoad = false;
	secondShortRoad = false;
	centerShortRoad = false;
	nomalRoad = true;
	n_horse = 1;
}

//현재 처음에 올라가는 값은 current값을 이용한것이 아니라서 
//처음값은 말의 개수 표기변화가 일어나지 않음.수정해줘야함 .
void Horse::MoveHorseSystem(const int& yutCount,Map& map,Pos pos)
{
	//map.MAP[ROW][COL];
	//CheckHorseNumOnPos(map);
	switch (yutCount)
	{
	case 0:
		MoveHorsePos(map, pos, 4);
		break;
	case 1:
		MoveHorsePos(map, pos, 1);
		break;
	case 2:
		MoveHorsePos(map, pos, 2);
		break;
	case 3:
		MoveHorsePos(map, pos, 3);
		break;
	case 4:
		MoveHorsePos(map, pos, 4);
		break;
	}
	util.SetCursurPoint(0, 0);
}
void Horse::SetHorsePos(int row, int col)
{
	this->pos.x = row;
	this->pos.y = col;
}

void Horse::MoveHorsePos(Map& map, Pos pos,int loopTime)
{
	
	MoveShortHorse(map, pos, loopTime);
	//첫번째 라인 
	
	if ((((pos.y == MAX_POS) && (pos.x <= MAX_POS ))||((pos.y==OUT_COL_POS)&&(pos.x==OUT_ROW_POS)))&&nomalRoad)
	{
		cout << "first line" << endl;
		cout << pos.x << ' ' << pos.y << endl;
		for (int i = 0; i < loopTime; i++)
		{
			if ((pos.x > MIN_POS)&&(pos.y==OUT_COL_POS))
				pos.x -= MOVE_HORSE;
			else
				pos.y -= MOVE_HORSE;
		}
		SetHorsePos(pos.x, pos.y);
		GetSamePosHorse(map);
		if (pos.x == 0 && pos.y == MAX_POS)
		{
			
			if (GetShortRoadSelect())
			{
				firstShortRoad = true;
				nomalRoad = false;
			}
			cout << " ";
		}
		
	}

	//두번째라인
	else if ((pos.x == MIN_POS && (pos.y <= MAX_POS || pos.y >= MIN_POS)) && nomalRoad)
	{
		for (int i = 0; i < loopTime; i++)
		{
			if (pos.y > MIN_POS)
				pos.y -= MOVE_HORSE;
			else
				pos.x += MOVE_HORSE;
		}
		SetHorsePos(pos.x, pos.y);
		GetSamePosHorse(map);
		if (pos.x == MIN_POS && pos.y == MIN_POS)
		{
			if (GetShortRoadSelect())
			{
				secondShortRoad = true;
				nomalRoad = false;
			}
		}
	}

	//세번째라인
	else if (pos.y == MIN_POS && (pos.x <= MAX_POS || pos.x >= MIN_POS)&& nomalRoad)
	{
		for (int i = 0; i < loopTime; i++)
		{
			if (pos.x < MAX_POS)
				pos.x += MOVE_HORSE;
			else
				pos.y += MOVE_HORSE;
		}
		SetHorsePos(pos.x, pos.y);
		GetSamePosHorse(map);
	}

	//네번째라인
	else if (pos.x == MAX_POS && (pos.y <= MAX_POS || pos.y >= MIN_POS)&& nomalRoad)
	{
		for (int i = 0; i < loopTime; i++)
		{
			if (pos.y < MAX_POS)
				pos.y += MOVE_HORSE;
		}
		SetHorsePos(pos.x, pos.y);
		GetSamePosHorse(map);
	}
}

void Horse::MoveShortHorse(Map& map, Pos pos, int loopTime)
{
	if (firstShortRoad)
	{
		//map.MAP[pos.x][pos.y] = OFF_HORSE;
		for (int i = 0; i < loopTime; i++)
		{
			if (pos.x < MAX_POS && pos.y>MIN_POS)
			{
				pos.x += MOVE_HORSE;
				pos.y -= MOVE_HORSE;
			
			}
			else if (pos.x == MAX_POS && pos.y == MIN_POS)
			{
				//false로 바꿔서 for문만큼 돌아가지가 않음. 
				nomalRoad = true;
				firstShortRoad = false;
				pos.y += MOVE_HORSE *(loopTime-i);
			}
			
		}

		if (pos.x == CENTER_POS && pos.y == CENTER_POS)
		{
			firstShortRoad = false;
			centerShortRoad = true;
		}
		
		SetHorsePos(pos.x, pos.y);
		GetSamePosHorse(map);
	}
	else if (secondShortRoad)
	{
		for (int i = 0; i < loopTime; i++)
		{
		pos.x += MOVE_HORSE;
		pos.y += MOVE_HORSE;
		}

		if (pos.x == CENTER_POS && pos.y == CENTER_POS)
		{ 
			secondShortRoad = false;
			centerShortRoad = true;
		}
		SetHorsePos(pos.x, pos.y);
		GetSamePosHorse(map);
	}
	else if (centerShortRoad)
	{
		for (int i = 0; i < loopTime; i++)
		{
			if (pos.y < MAX_POS && pos.x < MAX_POS)
			{
				pos.y += MOVE_HORSE;
				pos.x += MOVE_HORSE;
			}
		}
		SetHorsePos(pos.x, pos.y);
		GetSamePosHorse(map);
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
//종착지에 들어왔으면 해당말을 지워주는함수 - delete해야할듯??
void Horse::GetSamePosHorse(Map& map)
{
	//다음이동시는 고려되지 않았음 ,플레이어가 움직일 말을 선택하려면 
	//같은위치인지 정보는 플레이어가 하는게 맞는거같기도 
	if (map.MAP[pos.x][pos.y] == 0)
		n_horse = 1;
	//else if (map.MAP[pos.x][pos.y] == )
	//	n_horse = 2;
	//else if (map.MAP[pos.x][pos.y] == ON_TWO_HORSE)
	//	n_horse = 3;
	
}
Horse::Pos Horse::GetHorsePos()
{
	return pos;
}
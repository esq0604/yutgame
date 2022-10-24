//클래스 구현부 
#include "Player.h"
#include "Horse.h"
Player::Player()
{
	//playerPosition[0][0] = 0;
	yutState = { 0};
	throwCount = 1;
	yutCount = 0;
	yutPrint = ' ';
	haveHolseCount = 3;
	currentHorseIdx = 3;
	samePosHorseNum = 1;
	
	//horse = new Horse;
	

}

void Player::ThrowYut(Map& map)
{
	 

		for (int i = 1; i < 5; i += 2)
		{
			yutState[i] = GetRandomNumber();
		}
		for (int j = 2; j < 5; j += 2)
		{
			yutState[j] = GetRandomNumber();
		}

		for (int i = 1; i < 5; i++)
		{
			yutCount += yutState[i];
			cout << yutState[i] << " ";
		}
		cout << "뒤집힌 윷의 수 " << yutCount << " " << GetYutCount(yutCount);
		//SelectHorse();
		
		MoveHorse(map, horse[currentHorseIdx], yutCount);
		yutCount = 0;
	
		
}

void Player::CreateHorse()
{
	//3, 2, 1, 0- 콘솔창에 표시
	haveHolseCount--;
	//2 ,1 ,0 ,-1 ??-배열인덱스 다루기 
	if(currentHorseIdx>0)
	currentHorseIdx--;

}
int Player::GetHorseCount()
{
	return haveHolseCount;
}


void Player::SetPlayerName(const int playerNum)
{
	menu.DrawSetPlayerName(playerNum);
	cin >> playerName;
}


//void Player::SelectHorse()
//{
//	char keySelect;
//	bool t=true;
//	selectHorseIdx = currentHorseIdx;
//	cout << "움직일 말을 선택하세요 (<-/->), Enter";
//	keySelect = _getch();
//	while (t)
//	{
//		switch (keySelect)
//		{
//		case KEY_LEFT:
//			selectHorseIdx--;
//			if (selectHorseIdx < MIN_HORSE_IDX)
//			{
//				selectHorseIdx = MAX_HORSE_IDX;
//				SelectHorseCurssor(horse + selectHorseIdx);
//			}
//			currentHorseIdx = selectHorseIdx;
//			break;
//		case KEY_RIGHT:
//			selectHorseIdx++;
//			if (selectHorseIdx > MAX_HORSE_IDX)
//			{
//				selectHorseIdx = MIN_HORSE_IDX;
//				SelectHorseCurssor(horse + selectHorseIdx);
//			}
//			break;
//		case KEY_ENTER:
//			t = false;
//		}
//	}
//}
//void Player::SelectHorseCurssor(Horse* horse)
//{
//	if (horse->currentColPos == MAX_HORSE_POS && horse->currentRowPos <= MAX_HORSE_POS)
//	{
//		util.SetCursurPoint(48, horse->currentColPos + CURSOR_POINT_COLNUM);
//	}
//	else if (horse->currentColPos <= MAX_HORSE_POS && horse->currentRowPos == MIN_HORSE_POS)
//	{
//		util.SetCursurPoint(horse->currentRowPos + CURSOR_POINT_ROWNUM, CURSOR_POINT_COLNUM);
//	}
//	else if ((horse->currentRowPos <= MAX_HORSE_POS || horse->currentRowPos >= MIN_HORSE_POS)&&(horse->currentColPos==MIN_HORSE_POS))
//	{
//		util.SetCursurPoint(1, 2);
//	}
//	else if ((horse->currentColPos <= MAX_HORSE_POS || horse->currentRowPos >= MIN_HORSE_POS) && (horse->currentRowPos == MAX_HORSE_POS))
//	{
//		util.SetCursurPoint(3, 4);
//	}
//}

int Player::GetRandomNumber()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 1);
	return dis(gen);
}

//2바이트 , char는 1바이트 
string Player::GetYutCount(const int yutCount)
{
	switch (yutCount)
	{
	case 0:
		yutPrint = "모 한번더 ! ";
		throwCount++;
		break;
	case 1:
		yutPrint = "도";
		break;
	case 2:
		yutPrint = "개";
		break;
	case 3:
		yutPrint = "걸";
		break;
	case 4:
		yutPrint = " 윷";
		break;
	}
	return yutPrint;

}
//체크하는 함수를 만들고, 맵에서 이 함수를 쓰면 각 객체가 
void Player::GetHorseInSamePos(Map &map,Horse horse)
{
	//맵에 말이 몇개 올라가있는지 체크를 하려면..
	cout << "GetHorseInSamePos" << endl;
	if (map.MAP[horse.pos.x][horse.pos.y]== OFF_HORSE)
	{
		map.MAP[horse.pos.x][horse.pos.y] = horse_Shape[0];
		wcout << "cur state " << horse_Shape[0] << endl;
		//samePosHorseNum = ON_ONE_HORSE;
	}
	else if (map.MAP[horse.pos.x][horse.pos.y] == horse_Shape[0])
	{
		map.MAP[horse.pos.x][horse.pos.y] = horse_Shape[1];

		//samePosHorseNum = ON_TWO_HORSE;
	}
	else if (map.MAP[horse.pos.x][horse.pos.y] == horse_Shape[1])
	{
		map.MAP[horse.pos.x][horse.pos.y] = horse_Shape[2];
		//samePosHorseNum = ON_THREE_HORSE;
	}

}
void Player::OnHorseSelect()
{
	char horseOnState;
	if (haveHolseCount > 0 )
	{
		if (haveHolseCount == 3)
		{
			CreateHorse();
		}
		else
		{
			menu.DrawOnHorseQuestion();
			cin >> horseOnState;

			if (horseOnState == 'y' || horseOnState == 'Y')
			{
				CreateHorse();
			}
			else if (horseOnState == 'n' || horseOnState == 'N')
			{

			}
		}
	}

	
	/*else if (haveHolseCount == 0)
	{
		
	}*/
}
void Player::GetPlayerHaveHorse(int playerNum)
{
	//std::cout << playerNum << endl;
	menu.DrawPlayerHaveHorse(playerNum);
	std::cout << haveHolseCount;
	
}

void Player::MoveHorse(Map& map, Horse& horse, const int& yutCount)
{
	//horse에서 pos를 결정
	map.MAP[horse.pos.x][horse.pos.y] = OFF_HORSE;
	cout << horse.pos.x << ' ' << horse.pos.y << endl;
	horse.MoveHorseSystem(yutCount,map,horse.pos);

	map.MAP[horse.pos.x][horse.pos.y] = horse_Shape[0];
	
	//debug - cout << horse.pos.x << " " << horse.pos.y;
}
//
//void GetHorseCnt(Map& map, Horse& horse)
//{
//	if (map.MAP[horse.pos.x][horse.pos.y] == 0)
//		horse.n_horse = 1;
//	else if (map.MAP[horse.pos.x][horse.pos.y] == 1)
//		horse.n_horse = 2;
//	else if (map.MAP[horse.pos.x][horse.pos.y] == 2)
//		horse.n_horse = 3;
//}

//TODO::수정해야함..
//void GetHorsePos(Map& map, Horse& horse)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		horsePos.x = horse.GetHorsePos().x;
//	}
//}
	
void Player::SetHorseShape(const wchar_t(&shape)[3])
{
	for (int i = 0; i < 3; i++)
	{
		horse_Shape[i] = shape[i];
	}

}



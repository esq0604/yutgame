//Ŭ���� ������ 
#include "Player.h"
Player::Player():MIN_HORSE_IDX(0), MAX_HORSE_IDX(2), CURSOR_POINT_COLNUM(1), CURSOR_POINT_ROWNUM(5), MAX_HORSE_POS(20), MIN_HORSE_POS(0), ON_ONE_HORSE(1), ON_TWO_HORSE(2), ON_THREE_HORSE(3)
{
	//playerPosition[0][0] = 0;
	yutState = { 0};
	throwCount = 1;
	yutCount = 0;
	yutPrint = ' ';
	haveHolseCount = 3;
	currentHorseIdx = 3;
	samePosHorseNum = 1;
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
		cout << "������ ���� �� " << yutCount << " " << GetYutCount(yutCount);
		//SelectHorse();
		horse[currentHorseIdx].MoveHorseSystem(yutCount,map,horse[currentHorseIdx].currentRowPos,horse[currentHorseIdx].currentColPos);
		yutCount = 0;
	
		
}

void Player::CreateHorse()
{
	haveHolseCount--;
	currentHorseIdx--;

}
int Player::GetHorseCount()
{
	return haveHolseCount;
}


void Player::SetPlayerName()
{
	string name;
	cin >> name;
	playerName = name;
}


void Player::SelectHorse()
{
	char keySelect;
	bool t=true;
	selectHorseIdx = currentHorseIdx;
	cout << "������ ���� �����ϼ��� (<-/->), Enter";
	keySelect = _getch();
	while (t)
	{
		switch (keySelect)
		{
		case KEY_LEFT:
			selectHorseIdx--;
			if (selectHorseIdx < MIN_HORSE_IDX)
			{
				selectHorseIdx = MAX_HORSE_IDX;
				SelectHorseCurssor(horse + selectHorseIdx);
			}
			currentHorseIdx = selectHorseIdx;
			break;
		case KEY_RIGHT:
			selectHorseIdx++;
			if (selectHorseIdx > MAX_HORSE_IDX)
			{
				selectHorseIdx = MIN_HORSE_IDX;
				SelectHorseCurssor(horse + selectHorseIdx);
			}
			break;
		case KEY_ENTER:
			t = false;
		}
	}
}
void Player::SelectHorseCurssor(Horse* horse)
{
	if (horse->currentColPos == MAX_HORSE_POS && horse->currentRowPos <= MAX_HORSE_POS)
	{
		util.SetCursurPoint(48, horse->currentColPos + CURSOR_POINT_COLNUM);
	}
	else if (horse->currentColPos <= MAX_HORSE_POS && horse->currentRowPos == MIN_HORSE_POS)
	{
		util.SetCursurPoint(horse->currentRowPos + CURSOR_POINT_ROWNUM, CURSOR_POINT_COLNUM);
	}
	else if ((horse->currentRowPos <= MAX_HORSE_POS || horse->currentRowPos >= MIN_HORSE_POS)&&(horse->currentColPos==MIN_HORSE_POS))
	{
		util.SetCursurPoint(1, 2);
	}
	else if ((horse->currentColPos <= MAX_HORSE_POS || horse->currentRowPos >= MIN_HORSE_POS) && (horse->currentRowPos == MAX_HORSE_POS))
	{
		util.SetCursurPoint(3, 4);
	}
}

int Player::GetRandomNumber()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 1);
	return dis(gen);
}

//2����Ʈ , char�� 1����Ʈ 
string Player::GetYutCount(int yutCount)
{
	switch (yutCount)
	{
	case 0:
		yutPrint = "�� �ѹ��� ! ";
		throwCount++;
		break;
	case 1:
		yutPrint = "��";
		break;
	case 2:
		yutPrint = "��";
		break;
	case 3:
		yutPrint = "��";
		break;
	case 4:
		yutPrint = "��";
		break;
	}
	return yutPrint;

}
//üũ�ϴ� �Լ��� �����, �ʿ��� �� �Լ��� ���� �� ��ü�� 
int Player::GetHorseInSamePos(Map &map,Horse horse)
{
	//�ʿ� ���� � �ö��ִ��� üũ�� �Ϸ���..
	if (map.MAP[horse.currentRowPos][horse.currentColPos] == ON_ONE_HORSE)
	{
		samePosHorseNum = ON_ONE_HORSE;
	}
	else if (map.MAP[horse.currentRowPos][horse.currentColPos] == ON_TWO_HORSE)
	{
		samePosHorseNum = ON_TWO_HORSE;
	}
	else if (map.MAP[horse.currentRowPos][horse.currentColPos] == ON_THREE_HORSE)
	{
		samePosHorseNum = ON_THREE_HORSE;
	}

	return samePosHorseNum;
}


	
	




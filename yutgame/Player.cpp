//Ŭ���� ������ 
#include "Player.h"
Player::Player()
{
	 playerPosition[0][0] = 0;
	 yutState={ 0 };
	 throwCount = 1;
	 yutCount=0;
	 yutPrint = ' ';
}

void Player::ThrowYut()
{
	/*if (throwCount > 0)
	{*/
		//Ȧ��, ¦�� 
		for (int i = 1; i < 5; i += 2)
		{
			yutState[i] = GetRandomNumber();
		}
		for (int j = 2; j < 5; j += 2)
		{
			yutState[j] = GetRandomNumber();
		}
		/*for (int i = 2; i < 6; i += 2)
		{
			yutState[i] = GetRandomNumber();
		}*/
		for (int i = 1; i < 5; i++)
		{
			yutCount += yutState[i];
			cout << yutState[i] << " ";
		}
		cout << "������ ���� �� " << yutCount << " " << GetYutCount(yutCount);
		yutCount = 0;
		/*throwCount--;
	}*/
		
}
void Player::MoveHorse()
{

}


void Player::SetPlayerName()
{
	string name;
	cin >> name;
	playerName = name;
}

int Player::GetRandomNumber()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 1);
	return dis(gen);
}

//��,��,��,��� 2����Ʈ, char�� 1����Ʈ
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
	
	




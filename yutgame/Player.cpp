//클래스 구현부 
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
		//홀수, 짝수 
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
		cout << "뒤집힌 윷의 수 " << yutCount << " " << GetYutCount(yutCount);
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

//도,래,미,등등 2바이트, char는 1바이트
string Player::GetYutCount(int yutCount)
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
		yutPrint = "윷";
		break;
	}
	return yutPrint;

}
	
	




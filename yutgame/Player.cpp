//Å¬·¡½º ±¸ÇöºÎ 
#include "Player.h"
Player::Player()
{
	 playerPosition[0][0] = 0;
	 yutState={ 0 };
	 yutCount = 0;
}

void Player::ThrowYut()
{
	//È¦¼ö, Â¦¼ö 
	for (int i = 1,j=2; i < 6; i+=2,j+2)
	{
		yutState[i] = GetRandomNumber();
		yutState[j] = GetRandomNumber();
	}
	/*for (int i = 2; i < 6; i += 2)
	{
		yutState[i] = GetRandomNumber();
	}*/
	for (int i = 1; i < 6; i++)
	{
		cout << yutState[i] << " ";
	}
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

char Player::GetYutCount()
{
	switch()
}



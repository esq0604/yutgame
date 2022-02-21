//클래스 구현부 
#include "Player.h"
Player::Player()
{
	 playerPosition[0][0] = 0;
	 yutState={ 0 };
}

void Player::ThrowYut()
{
	for (int i = RandomNumber(); i < RandomNumber(); i++)
	{
		cout << i << " ";
		yutState[i] = 1;
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

int Player::RandomNumber()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 4);
	return dis(gen);
}


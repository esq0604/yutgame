#pragma once
#include<iostream>
#include"Player.h"
#include "Util.h"
class Horse;
using namespace std;
class DrawMenu 
{
private:
	Player player;
	Horse* horse;
	Util util;
	char helpMessageOut;
	char inputCommand;
	string inputShortRoad;
	void DrawHelpMessage();
	void DrawInputCommand();
	void EnterInputHelpMessage();
	void EnterInputCommand();
	


public:
	void DrawMainScreen();
	void DrawNamingScreen();
	void DrawStartScreen();
	void DrawInputPlayerName(Player* player);
	void DrawPlayerHaveHorse(Player* player);
	void OnHorseQuestion(Player& player);
	void DrawHelpMessageInGame();
	bool GetShortRoadSelect();
};

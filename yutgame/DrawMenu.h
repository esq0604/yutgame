#pragma once
#include<iostream>
#include"Player.h"
#include "Util.h"
#include "Horse.h"
using namespace std;
class DrawMenu 
{
public:
	Player player;
	Horse horse;
	Util util;
	char helpMessageOut;
	char inputCommand;
	char inputShortRoad;
public:
	void DrawMainScreen();
	void DrawNamingScreen();
	void DrawStartScreen();
	void DrawHelpMessage();
	void DrawInputCommand();
	void DrawHelpMessageInGame();
	void EnterInputHelpMessage();
	void EnterInputCommand();
	void OnHorseQuestion(Player& player);
	void DrawShortRoadSelect(Horse& horse);
	void DrawPlayerHaveHorse(Player* player);
	void DrawInputPlayerName(Player* player);

};

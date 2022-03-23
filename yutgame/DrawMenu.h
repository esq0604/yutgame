#pragma once
#include<iostream>
#include "Util.h"
using namespace std;
class DrawMenu 
{
private:
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
	void DrawSetPlayerName(int playerNum);
	void DrawPlayerHaveHorse(int i);
	void DrawOnHorseQuestion();
	void DrawHelpMessageInGame();
	void DrawShortRoadSelect();
	//bool GetShortRoadSelect();
};

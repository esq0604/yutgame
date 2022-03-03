#pragma once
#include<iostream>
#include"Player.h"
#include "Util.h"
using namespace std;
class DrawMenu : Util
{
public:
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
	bool DrawShortRoadSelect();
};

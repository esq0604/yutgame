#pragma once
#include<iostream>
#include"Player.h"
#include"Util.h"
using namespace std;
class DrawMenu :public Util
{
public:
	char helpMessageOut;
	char inputCommand;
public:
	void DrawMainScreen();
	void DrawNamingScreen();
	void DrawStartScreen();
	void DrawHelpMessage();
	void DrawInputCommand();
	void EnterInputHelpMessage();
	void EnterInputCommand();
	void DrawHelpMessageInGame();
};

#pragma once
#include<iostream>
#include"Player.h"
using namespace std;
class DrawMenu
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
};

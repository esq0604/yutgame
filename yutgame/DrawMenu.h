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
	void Draw_MainScreen();
	void Draw_NamingScreen();
	void Draw_StartScreen();
	void Draw_HelpMessage();
	void Draw_InputCommand();
	void Enter_InputHelpMessage();
	void Enter_InputCommand();
};

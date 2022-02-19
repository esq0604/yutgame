#pragma once
#include<iostream>
#include"Player.h"
using namespace std;
class MainMenu
{
public:
	char helpmessageOut;
	char inputCommand;
public:
	void Draw_MainScreen();
	void Draw_NamingScreen();
	void Draw_StartScreen();
	void Draw_HelpMessage();
	void Draw_InputCommand();
};

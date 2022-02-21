#pragma once
#include<Windows.h>
enum eColor
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};
class Util
{
	int x, y;
public:
	void TextColor(int foreground, int background);
	void SetCursurPoint(int x, int y);
private:

};
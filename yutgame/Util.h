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
	unsigned short color;

	void TextColor(int foreground, int background);
	void SetCursurPoint(int x, int y);
	void SetTextColor(unsigned short text);
private:

};
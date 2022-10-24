#pragma once
#include<iostream>
#include<windows.h>
#include<vector>
#define COL 5
#define ROW 5
using namespace std;
class Map
{
public:

    void DrawMap();
public:
    int colIdx = 20;
    int rowIdx = 20;
    wchar_t MAP[5][5] =
    {
        '0','0','0','0' ,'0',
        '0','0','1','0','0',
        '0','1','0','1' ,'0',
        '0','0','1','0' ,'0',
        '0','0','0','0' ,'0'
    };
    
};
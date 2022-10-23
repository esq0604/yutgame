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
    string MAP[6] =
    {   "00000",
        "00100",
        "01010",
        "00100",
        "00000"
    };
};
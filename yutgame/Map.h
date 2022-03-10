#pragma once
#include<iostream>
#include<windows.h>
#define COL 21
#define ROW 22
using namespace std;
class Map
{
public:
    void DrawMap();
    void CreateMap();
public:
    int colIdx = 20;
    int rowIdx = 20;
    int  MAP[ROW][COL] = { 0 };
};
#pragma once
#include<iostream>
#include<windows.h>
#define MAP_SIZE 21
using namespace std;
class Map
{
public:
    void CreateMap();

private:
    int MAP[MAP_SIZE][MAP_SIZE] = { 0 };
};
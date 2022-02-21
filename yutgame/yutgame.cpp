#include<windows.h>
#include<array>
#include "Map.h"
#include "DrawMenu.h"
#include "Util.h"
using namespace std;



int main()
{
    system("color 8f");
    system("mode con cols=100 lines=40");
    Util util;
    DrawMenu drawMenu;
    Player player[2];
    Map map;
    //util.TextColor(BLUE,LIGHTGRAY);
    drawMenu.DrawMainScreen();

    drawMenu.DrawNamingScreen();
    
    for (int i = 0; i < 2; i++)
    {   
        cout << "\t\t\t플레이어 " << i+1 << "이름을 입력하세요: ";
        player[i].SetPlayerName();
    }
    
    drawMenu.DrawStartScreen();


    //순서정하기
    //명령어는 상시로 돌아가야함.
    
    while (true)
    {
        map.DrawMap();  
        //윷던지기 플레이어 1,2 
        player[0].ThrowYut();
    }
}
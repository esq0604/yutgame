#include<windows.h>
#include<array>
#include "Map.h"
#include "MainMenu.h"
#include "Util.h"
using namespace std;



int main()
{
    system("color 8f");
    system("mode con cols=100 lines=40");
    Util util;
    MainMenu mainMenu;
    Player player[2];
    Map map;
    //util.TextColor(BLUE,LIGHTGRAY);
    mainMenu.Draw_MainScreen();

    mainMenu.Draw_NamingScreen();
    for (int i = 0; i < 2; i++)
    {   
        cout << "\t\t\t플레이어 " << i+1 << "이름을 입력하세요: ";
        player[i].Set_PlayerName();
    }

    mainMenu.Draw_StartScreen();
    while (true)
    {
        map.DrawMap();

    }
}
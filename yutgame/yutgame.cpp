#include<windows.h>
#include "Map.h"
#include "MainMenu.h"
#include "Util.h"
using namespace std;



int main()
{
    system("color 8f");
    system("mode con cols=100 lines=40");
    Util util;
    //이건 리스트로 관리할듯. 
    Player player1, player2;
    MainMenu mainMenu;
    Map map;
    //util.TextColor(BLUE,LIGHTGRAY);
    mainMenu.DrawMainScreen();
    
    map.DrawMap();
}
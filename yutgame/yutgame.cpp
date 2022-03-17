#include<windows.h>
#include<array>
#include<conio.h>
#include "Map.h"
#include "DrawMenu.h"
#include "Util.h"
using namespace std;




int main()
{
    system("color 8f");
    system("mode con cols=110 lines=40");
    Util util;
    DrawMenu drawMenu;
    Player player[3];
    Map map;

    //util.TextColor(BLUE,LIGHTGRAY);
    drawMenu.DrawMainScreen();
    drawMenu.DrawNamingScreen();
    drawMenu.DrawInputPlayerName(player);
    drawMenu.DrawStartScreen();
    system("cls");

    while (true)
    {
        system("cls");

        char yutThw;
        map.DrawMap();
        drawMenu.DrawHelpMessageInGame();
        drawMenu.DrawPlayerHaveHorse(player);
        cin >> yutThw;
        if(yutThw == 'T')
        {
            if(player[1].haveHolseCount>0)
            //drawMenu.OnHorseQuestion(player[1]);
            util.SetCursurPoint(60 ,12);
            cout << "플레이어 " << "의 결과  ";
            player[1].ThrowYut(map);
            //util.SetCursurPoint(60,14);
            //cout << "플레이어 " << "의 결과  ";
            //player[2].ThrowYut();

        }     
        
 
        cout << endl;
        util.SetCursurPoint(48, 21);
        Sleep(2000);
       
    }
        
 }

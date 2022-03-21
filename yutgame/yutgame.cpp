#include<windows.h>
#include<array>
#include<conio.h>
#include"Player.h"
#include "Map.h"
#include "DrawMenu.h"
#include "Util.h"
using namespace std;




int main()
{
    system("color 8f");
    system("mode con cols=110 lines=40");
    Util util;
    Player player[2];
    DrawMenu drawMenu;
    Map map;

    
    //util.TextColor(BLUE,LIGHTGRAY);
    
    drawMenu.DrawMainScreen();
    drawMenu.DrawNamingScreen();
    drawMenu.DrawSetPlayerName();
    drawMenu.DrawStartScreen();
    system("cls");

    while (true)
    {
        system("cls");

        char yutThw;
        map.DrawMap();
        drawMenu.DrawHelpMessageInGame();
        drawMenu.DrawPlayerHaveHorse(1);
        cin >> yutThw;
        if(yutThw == 'T')
        {
            if(player[1].haveHolseCount>0)
            drawMenu.DrawOnHorseQuestion();
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

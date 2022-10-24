#include<windows.h>
#include<array>
#include<conio.h>
#include"Player.h"
#include "Map.h"
#include "DrawMenu.h"
#include "Util.h"
#include "GameInit.h"
using namespace std;




int main()
{
    int order = 0;
    const int PLAYER_ONE = 1;
    const int PLAYER_TWO = 2;
    //system("color 8f");
    system("mode con cols=150 lines=40");
    Util util;
    Player player[2];
    DrawMenu drawMenu;
    Map map;
    GameInit gameInit(player);
    //util.TextColor(BLUE,LIGHTGRAY);
    
    drawMenu.DrawMainScreen();
    drawMenu.DrawNamingScreen();
    util.SetCursurPoint(5, 1);
    player[0].SetPlayerName(PLAYER_ONE);
    util.SetCursurPoint(5, 2);
    player[1].SetPlayerName(PLAYER_TWO);
    drawMenu.DrawStartScreen();
    system("cls");

    while (true)
    {
        system("cls");
        util.SetTextColor(WHITE);
       util.SetCursurPoint(0, 29);
        cout << "플레이어 " << (order + 1) << "의 차례입니다.";
        util.SetCursurPoint(0, 0);
        char yutThw;
        map.DrawMap();
        drawMenu.DrawHelpMessageInGame();
        util.SetCursurPoint(0, 25);

        player[0].GetPlayerHaveHorse(PLAYER_ONE);
        cout << player[0].haveHolseCount;
        cout << player[1].haveHolseCount;
        util.SetCursurPoint(0, 27);

        player[1].GetPlayerHaveHorse(PLAYER_TWO);
        util.SetCursurPoint(60, 10);

        cin >> yutThw;
        if(yutThw == 'T')
        {
            
            util.SetCursurPoint(0, 31);
            if(player[order].haveHolseCount>0)
            player[order].OnHorseSelect();
            util.SetCursurPoint(60 ,12);
            cout << "플레이어 " <<(order+1)<<"의 결과  ";
            player[order].ThrowYut(map);

        }     
        
        
        if (util.color == 4)
            util.color = 3;
        else
            util.color = 4;
        
        order = !order;

        cout << endl;
        util.SetCursurPoint(48, 21);
        Sleep(2000);
       
    }
        
 }

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
    
    for (int i = 1; i < 3; i++)
    {   
        cout << "\t\t\t�÷��̾� " << i << "�̸��� �Է��ϼ���: ";
        player[i].SetPlayerName();
    }
    
    drawMenu.DrawStartScreen();
    system("cls");


    while (true)
    {
        system("cls");

        char yutThw;
        map.DrawMap();
        drawMenu.DrawHelpMessageInGame();
        util.SetCursurPoint(0, 25);
        cout << "�÷��̾� 1 ���� ���� �� ";
         player[1].GetHorseCount();
        util.SetCursurPoint(0, 27);
        cout << "�÷��̾� 2 ���� ���� �� ";
         player[2].GetHorseCount();
        util.SetCursurPoint(60,10);
        cin >> yutThw;
        if(yutThw == 'T')
        {
            if(player[1].haveHolseCount-1>0)
            drawMenu.OnHorseQuestion(player[1]);
            util.SetCursurPoint(60 ,12);
            cout << "�÷��̾� " << "�� ���  ";
            player[1].ThrowYut(map);
            //util.SetCursurPoint(60,14);
            //cout << "�÷��̾� " << "�� ���  ";
            //player[2].ThrowYut();

        }     
        
 
        cout << endl;
        Sleep(2000);
       
    }
        
 }

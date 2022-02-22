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


    int logCount = 2;
    while (true)
    {
        map.DrawMap(); 
        char c;
        //util.SetCursurPoint(70, 20);
        util.SetCursurPoint(55, logCount-4);
        cout << "SPACE�� ���� ���� �������� ";
        cin >> c;
        if(c == 'T')
        {
            util.SetCursurPoint(55, (25 + logCount));
            cout << "�÷��̾� " << "�� ���  ";
            player[1].ThrowYut();
            util.SetCursurPoint(55, (25 + logCount+2));
            cout << "�÷��̾� " << "�� ���  ";

            player[2].ThrowYut();
            logCount += 2;
        }     
        
        if (logCount == 10)
        {
            logCount = 0;
        }
        cout << endl;
        Sleep(2000);
        system("cls");
    }
        
 }

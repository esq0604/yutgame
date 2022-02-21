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
    system("mode con cols=100 lines=40");
    Util util;
    DrawMenu drawMenu;
    Player player[3];
    Map map;
    //util.TextColor(BLUE,LIGHTGRAY);
    drawMenu.DrawMainScreen();

    drawMenu.DrawNamingScreen();
    
    for (int i = 1; i < 3; i++)
    {   
        cout << "\t\t\t플레이어 " << i << "이름을 입력하세요: ";
        player[i].SetPlayerName();
    }
    
    drawMenu.DrawStartScreen();


    while (true)
    {
        char c;
        map.DrawMap(); 
        util.SetCursurPoint(70, 20);
       
        //윷던지기 플레이어 1,2 
        //map.DrawMap();
        for (int i = 1; i < 3; i++)
        {
            c = getchar();
                if(c == 32)
                {
                    util.SetCursurPoint(55, 20+(i+3));
                    cout << "플레이어 " << i << "의 결과  ";
                    player[i].ThrowYut();

                }


            
        }

        cout << endl;
    }
        
 }

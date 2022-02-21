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


    while (true)
    {
        char c;
        map.DrawMap(); 
        util.SetCursurPoint(70, 20);
       
        //윷던지기 플레이어 1,2 
        //map.DrawMap();
        for (int i = 0; i < 2; i++)
        {
            c = getchar();
                if(c == 32)
                {
                    util.SetCursurPoint(70, 20+(i+3));
                    cout << "플레이어 " << i << " ";
                    player[i].ThrowYut();

                }
\

            
        }

        cout << endl;
    }
        
 }

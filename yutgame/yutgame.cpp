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
        cout << "\t\t\t�÷��̾� " << i+1 << "�̸��� �Է��ϼ���: ";
        player[i].SetPlayerName();
    }
    
    drawMenu.DrawStartScreen();


    //�������ϱ�
    //��ɾ�� ��÷� ���ư�����.
    
    while (true)
    {
        map.DrawMap();  
        //�������� �÷��̾� 1,2 
        player[0].ThrowYut();
    }
}
#include "MainMenu.h"
void MainMenu::Draw_MainScreen()
{

    cout << "\n\n\n\n";
    cout << "\t\t\t\t"; cout << "                                      @\n";
    cout << "\t\t\t\t"; cout << "     @@@@       @            @@@@     @     \n";
    cout << "\t\t\t\t"; cout << "   @      @     @           @    @    @           \n";
    cout << "\t\t\t\t"; cout << "  @        @    @          @      @   @           \n";
    cout << "\t\t\t\t"; cout << " @          @   @         @        @  @  \n";
    cout << "\t\t\t\t"; cout << "  @        @    @          @      @   @                 \n";
    cout << "\t\t\t\t"; cout << "   @     @      @           @    @    @ \n";
    cout << "\t\t\t\t"; cout << "     @@@@       @@@@@@@@@    @@@@     @ \n";
    cout << "\t\t\t\t"; cout << "                    @@                @  \n";
    cout << "\t\t\t\t"; cout << "@@@@@@@@@@@@@@ @@@@@@@@@@@            @ \n";
    cout << "\t\t\t\t"; cout << "     @   @                \n";
    cout << "\t\t\t\t"; cout << "     @ @ @        @@@@@@    \n";
    cout << "\t\t\t\t"; cout << "   @@@@@@@@            @                            \n";
    cout << "\t\t\t\t"; cout << "       @               @             \n";
    cout << "\t\t\t\t"; cout << "      @ @         @@@@@@                                \n";
    cout << "\t\t\t\t"; cout << "     @   @        @                \n";
    cout << "\t\t\t\t"; cout << "    @     @       @@@@@@      \n\n\n\n\n";
    cout << "\t\t\t\t"; cout << "     게임전 화면 이동을 하려면 아무키나 누르세요.\n\n\n\n\n\n\n";
    cout << "\t\t\t\t"; cout << "                \n\n\n\n\n\n\n";
    cout << "\t\t\t\t"; cout << "                   \n\t\t\t\t";
    getchar();
    system("cls");
}
void MainMenu::Draw_NamingScreen()
{
    cout << "\t\t\t******************* 유닛 생성합니다 *******************\n";
}
void MainMenu::Draw_HelpMessage()
{
    cout << "\t\t\t*******************도움말*******************\n\n";
    cout << "\t\t\t<H>elp : 도움말\n";
    cout << "\t\t\t<M>ap : 맵을 화면에 출력함\n";
    cout << "\t\t\t<T>hrow : 게임 시작\n";
    cout << "\t\t\t<Q>uit 게임 종료\n";

}
void MainMenu::Draw_InputCommand()
{
    cout << "\t\t\t********************************************\n\n";
    cout << "\t\t\t명령어를 입력하세요 >";
}
void MainMenu::Draw_StartScreen()
{
    cout << "\t\t\t******************* 게임을 시작합니다 *******************\n\n";
    cout << "\t\t\t게임 시작\n ";
    cout << "\t\t\t게임 도움말 출력하시겠습니까?(y/n) ";

HELP_MESSAGE:
    cin >> helpmessageOut;
    if (helpmessageOut == 'y')
    {
        Draw_HelpMessage();
        Draw_InputCommand();
        cin >> inputCommand;
    }
    else if (helpmessageOut == 'n')
    {
        Draw_InputCommand();
        cin >> inputCommand;
    }
    else
    {
        cout << "\t\t\t잘못된 입력입니다. 게임 도움말 출력하시겠습니까?(y/n)";
        goto HELP_MESSAGE;
    }
    
//스위치문 다른곳으로 옮겨야할듯?? 
    switch (inputCommand)
    {
    case 'H':
    {
        Draw_HelpMessage();
        break;
    }
    case 'M':
    {
        break;
    }
    case 'T':
    {
        break;
    }
    case 'Q':
    {
        break;
    }
    default:
    {
        cout << "\t\t\t잘못된 입력입니다. 게임 도움말 출력하시겠습니까?(y/n)";
        break;
    }
    }
}




#include "DrawMenu.h"
void DrawMenu::Draw_MainScreen()
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
void DrawMenu::Draw_NamingScreen()
{
    cout << "\t\t\t******************* 유닛 생성합니다 *******************\n";
}
void DrawMenu::Draw_HelpMessage()
{
    cout << "\t\t\t*******************도움말*******************\n\n";
    cout << "\t\t\t<H>elp : 도움말\n";
    cout << "\t\t\t<M>ap : 맵을 화면에 출력함\n";
    cout << "\t\t\t<T>hrow : 게임 시작\n";
    cout << "\t\t\t<Q>uit 게임 종료\n";

}
void DrawMenu::Draw_InputCommand()
{
    cout << "\t\t\t********************************************\n\n";
    cout << "\t\t\t명령어를 입력하세요 >";
    Enter_InputCommand();
}
void DrawMenu::Draw_StartScreen()
{
    cout << "\t\t\t******************* 게임을 시작합니다 *******************\n\n";
    cout << "\t\t\t게임 시작\n ";
    cout << "\t\t\t게임 도움말 출력하시겠습니까?(y/n) ";
    Enter_InputHelpMessage();
}
void DrawMenu::Enter_InputHelpMessage()
{
    while (true)
    {
        cin >> helpMessageOut;
        if (helpMessageOut == 'y')
        {
            Draw_HelpMessage();
            Draw_InputCommand();
            break;
        }
        else if (helpMessageOut == 'n')
        {
            Draw_InputCommand();
            break;
        }
        else
        {
            cout << "\t\t\t잘못된 입력입니다. 게임 도움말 출력하시겠습니까?(y/n)";
        }
    }
}
void DrawMenu::Enter_InputCommand()
{
    bool bOnLoop = true;
    while (bOnLoop)
    {
        cin >> inputCommand;
        switch (inputCommand)
        {
        case 'H':
        {
            system("cls");
            bOnLoop = false;
            Draw_HelpMessage();
            Draw_InputCommand();
            break;
        }
        case 'M':
        {
            break;
        }
        case 'T':
        {
            //일단은 넘어가기위해 FALSE로,.,
            bOnLoop = false;
            break;
        }
        case 'Q':
        {
            exit(0);
        }
        default:
        {
            system("cls");
            bOnLoop = false;
            Draw_HelpMessage();
            Draw_InputCommand();
            break;
        }
        }
    }
}




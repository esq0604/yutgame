#include "DrawMenu.h"

void DrawMenu::DrawMainScreen()
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
void DrawMenu::DrawNamingScreen()
{
    cout << "\t\t\t******************* 유닛 생성합니다 *******************\n";
}
void DrawMenu::DrawHelpMessage()
{
    cout << "\t\t\t*******************도움말*******************\n\n";
    cout << "\t\t\t<H>elp : 도움말\n";
    cout << "\t\t\t<M>ap : 맵을 화면에 출력함\n";
    cout << "\t\t\t<T>hrow : 게임 시작\n";
    cout << "\t\t\t<Q>uit 게임 종료\n";

}
void DrawMenu::DrawHelpMessageInGame()
{
    util.SetCursurPoint(55, 0);
    cout << "*******************도움말*******************";
    util.SetCursurPoint(60, 2);
    cout << "<H>elp : 도움말";

    util.SetCursurPoint(60, 4);
    cout << "<M>ap : 맵을 화면에 출력함";

    util.SetCursurPoint(60, 6);
    cout << "<T>hrow : 윷 던지기";

    util.SetCursurPoint(60, 8);
    cout << "<Q>uit 게임 종료";
}

void DrawMenu::DrawInputCommand()
{
    cout << "\t\t\t********************************************\n\n";
    cout << "\t\t\t명령어를 입력하세요 >";
    EnterInputCommand();
}
void DrawMenu::DrawStartScreen()
{
    cout << "\t\t\t******************* 게임을 시작합니다 *******************\n\n";
    cout << "\t\t\t게임 시작\n ";
    cout << "\t\t\t게임 도움말 출력하시겠습니까?(y/n) ";
    EnterInputHelpMessage();
}
void DrawMenu::EnterInputHelpMessage()
{
    while (true)
    {
        cin >> helpMessageOut;
        if (helpMessageOut == 'y')
        {
            DrawHelpMessage();
            DrawInputCommand();
            break;
        }
        else if (helpMessageOut == 'n')
        {
            DrawInputCommand();
            break;
        }
        else
        {
            cout << "\t\t\t잘못된 입력입니다. 게임 도움말 출력하시겠습니까?(y/n)";
        }
    }
}

void DrawMenu::EnterInputCommand()
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
            DrawHelpMessage();
            DrawInputCommand();
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
            DrawHelpMessage();
            DrawInputCommand();
            break;
        }
        }
    }
}

void DrawMenu::DrawOnHorseQuestion()
{
    cout << "말을 올리겠습니까? (y/n)";
}


void DrawMenu::DrawPlayerHaveHorse(int i)
{
  
    
    cout << "플레이어 " << i << "보유 말의 수 ";
    //cout << "플레이어 " << 2 << "보유 말의 수 ";
    //입력칸을 위해 커서위치를 바꿔놈 
    
}

void DrawMenu::DrawSetPlayerName(int playerNum)
{
        cout << "\t\t\t플레이어 " << playerNum << "이름을 입력하세요: ";
}

void DrawMenu::DrawShortRoadSelect()
{
    cout << "다음 턴에 지름길을 이용하시겠습니까? (y/n)";
}



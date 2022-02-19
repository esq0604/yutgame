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
    cout << "\t\t\t\t"; cout << "     ������ ȭ�� �̵��� �Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n\n\n";
    cout << "\t\t\t\t"; cout << "                \n\n\n\n\n\n\n";
    cout << "\t\t\t\t"; cout << "                   \n\t\t\t\t";
    getchar();
    system("cls");
}
void DrawMenu::Draw_NamingScreen()
{
    cout << "\t\t\t******************* ���� �����մϴ� *******************\n";
}
void DrawMenu::Draw_HelpMessage()
{
    cout << "\t\t\t*******************����*******************\n\n";
    cout << "\t\t\t<H>elp : ����\n";
    cout << "\t\t\t<M>ap : ���� ȭ�鿡 �����\n";
    cout << "\t\t\t<T>hrow : ���� ����\n";
    cout << "\t\t\t<Q>uit ���� ����\n";

}
void DrawMenu::Draw_InputCommand()
{
    cout << "\t\t\t********************************************\n\n";
    cout << "\t\t\t��ɾ �Է��ϼ��� >";
    Enter_InputCommand();
}
void DrawMenu::Draw_StartScreen()
{
    cout << "\t\t\t******************* ������ �����մϴ� *******************\n\n";
    cout << "\t\t\t���� ����\n ";
    cout << "\t\t\t���� ���� ����Ͻðڽ��ϱ�?(y/n) ";
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
            cout << "\t\t\t�߸��� �Է��Դϴ�. ���� ���� ����Ͻðڽ��ϱ�?(y/n)";
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
            //�ϴ��� �Ѿ������ FALSE��,.,
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




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
    cout << "\t\t\t\t"; cout << "     ������ ȭ�� �̵��� �Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n\n\n";
    cout << "\t\t\t\t"; cout << "                \n\n\n\n\n\n\n";
    cout << "\t\t\t\t"; cout << "                   \n\t\t\t\t";
    getchar();
    system("cls");
}
void MainMenu::Draw_NamingScreen()
{
    cout << "\t\t\t******************* ���� �����մϴ� *******************\n";
}
void MainMenu::Draw_HelpMessage()
{
    cout << "\t\t\t*******************����*******************\n\n";
    cout << "\t\t\t<H>elp : ����\n";
    cout << "\t\t\t<M>ap : ���� ȭ�鿡 �����\n";
    cout << "\t\t\t<T>hrow : ���� ����\n";
    cout << "\t\t\t<Q>uit ���� ����\n";

}
void MainMenu::Draw_InputCommand()
{
    cout << "\t\t\t********************************************\n\n";
    cout << "\t\t\t��ɾ �Է��ϼ��� >";
}
void MainMenu::Draw_StartScreen()
{
    cout << "\t\t\t******************* ������ �����մϴ� *******************\n\n";
    cout << "\t\t\t���� ����\n ";
    cout << "\t\t\t���� ���� ����Ͻðڽ��ϱ�?(y/n) ";

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
        cout << "\t\t\t�߸��� �Է��Դϴ�. ���� ���� ����Ͻðڽ��ϱ�?(y/n)";
        goto HELP_MESSAGE;
    }
    
//����ġ�� �ٸ������� �Űܾ��ҵ�?? 
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
        cout << "\t\t\t�߸��� �Է��Դϴ�. ���� ���� ����Ͻðڽ��ϱ�?(y/n)";
        break;
    }
    }
}




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
    cout << "\t\t\t\t"; cout << "     ������ ȭ�� �̵��� �Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n\n\n";
    cout << "\t\t\t\t"; cout << "                \n\n\n\n\n\n\n";
    cout << "\t\t\t\t"; cout << "                   \n\t\t\t\t";
    getchar();
    system("cls");
}
void DrawMenu::DrawNamingScreen()
{
    cout << "\t\t\t******************* ���� �����մϴ� *******************\n";
}
void DrawMenu::DrawHelpMessage()
{
    cout << "\t\t\t*******************����*******************\n\n";
    cout << "\t\t\t<H>elp : ����\n";
    cout << "\t\t\t<M>ap : ���� ȭ�鿡 �����\n";
    cout << "\t\t\t<T>hrow : ���� ����\n";
    cout << "\t\t\t<Q>uit ���� ����\n";

}
void DrawMenu::DrawHelpMessageInGame()
{
    SetCursurPoint(55, 0);
     cout << "*******************����*******************";
     SetCursurPoint(60, 2);
     cout << "<H>elp : ����";

     SetCursurPoint(60, 4);
     cout << "<M>ap : ���� ȭ�鿡 �����";

     SetCursurPoint(60, 6);
     cout << "<T>hrow : �� ������";

     SetCursurPoint(60, 8);
     cout << "<Q>uit ���� ����";



}
void DrawMenu::DrawInputCommand()
{
    cout << "\t\t\t********************************************\n\n";
    cout << "\t\t\t��ɾ �Է��ϼ��� >";
    EnterInputCommand();
}
void DrawMenu::DrawStartScreen()
{
    cout << "\t\t\t******************* ������ �����մϴ� *******************\n\n";
    cout << "\t\t\t���� ����\n ";
    cout << "\t\t\t���� ���� ����Ͻðڽ��ϱ�?(y/n) ";
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
            cout << "\t\t\t�߸��� �Է��Դϴ�. ���� ���� ����Ͻðڽ��ϱ�?(y/n)";
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
            DrawHelpMessage();
            DrawInputCommand();
            break;
        }
        }
    }
}

bool DrawMenu::DrawShortRoadSelect()
{

    while (true)
    {
        cout << "���� �Ͽ� �������� �̿��Ͻðڽ��ϱ�? (y/n)";
        cin >> inputShortRoad;
        if (inputShortRoad == 'y')
            return true;
        else if (inputShortRoad == 'n')
            return false;
    }

}





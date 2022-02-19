#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;
#define MAP_SIZE 21

int MAP[MAP_SIZE][MAP_SIZE];
class MainMenu {
public:
    MainMenu()
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
        cout << "\t\t\t\t"; cout << "     게임을 시작하려면 아무키나 누르세요.\n\n\n\n\n\n\n";
        cout << "\t\t\t\t"; cout << "                \n\n\n\n\n\n\n";
        cout << "\t\t\t\t"; cout << "                   \n\t\t\t\t";
        getchar();
        system("cls");
    }
};
class Map
{
public:
    void DrawMap()
    {

        for (int row = 0; row< MAP_SIZE; row++)
        {
            cout << "\t\t\t\t";
            for (int col = 0; col < MAP_SIZE; col++)
            {
                if ((row == 0 || col == 0 || row == 20 || col == 20) && (row % 5 == 0) && (col % 5 == 0))
                    cout << MAP[row][col] << " ";
                else if ((row % 5 == 0 || col % 5 == 0) && (row == col) ||(col*row==75))
                    cout << MAP[row][col] << " ";

                else
                    cout << " " <<" ";
            }
            cout << endl;
        }
        getchar();
        system("cls");
    }
};

int main()
{
    system("mode con cols=100 lines=40");
    Map map;
    MainMenu MainMenu;
    map.DrawMap();
}
#include "Map.h"

void Map::DrawMap()
{
    
    for (int row = 0; row < ROW; row++)
    {
        wcout << "\t";
        for (int col = 0; col < COL; col++)
        {
            if (MAP[row][col] == '1')
            {
                wcout << ' ' << ' ' << "\t";
                continue;
            }
            wcout << MAP[row][col] << "\t";

        }
        wcout << endl << endl << endl << endl;
    }
        /*for (int i = 0; i < ROW; i++)
        {
            cout << " ";
            for (int j = 0; j < COL; j++)
            {
                cout << MAP[i][j] << " ";
            }
            cout << endl;
        }*/
        //getchar();
        //system("cls");
}

//void Map::CreateMap(Map& map)
//{
//
//}
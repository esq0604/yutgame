#include "Map.h"
void Map::DrawMap()
{
    
        for (int row = 0; row < ROW; row++)
        {
            cout << "\t";
            for (int col = 0; col < COL; col++)
            {
                if ((row == 0 || col == 0 || row == 20 || col == 20) && (row % 5 == 0&&row<25) && (col % 5 == 0))
                    cout << MAP[row][col] << " ";
                else if ((row % 5 == 0 || col % 5 == 0) && (row == col) || (col * row == 75))
                    cout << MAP[row][col] << " ";

                else
                    cout << " " << " ";
            }
            cout << endl;
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
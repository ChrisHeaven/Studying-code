#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here


        for (int i = 0; i < 6; i++)
        {
            /* code */
            for (int j = 0; j < 6; j++)
            {
                if (i == 0 && j == 0)
                    board[i][j] = board[i][j];
                if (i == 0 && j != 0)
                    board[i][j] = board[i][j] + board[i][j - 1];
                if (i != 0 && j == 0)
                    board[i][j] = board[i][j] + board[i - 1][j];
                if (i != 0 && j != 0)
                {
                    if (board[i - 1][j] >= board[i][j - 1])
                        board[i][j] = board[i][j] + board[i - 1][j];
                    else
                        board[i][j] = board[i][j] + board[i][j - 1];
                }
            }
        }

        return board[5][5];
    }
};

int main()
{
    vector<vector<int> > board = {
        { 564, 448, 654, 186, 490, 699 },
        { 487, 444, 563, 228, 365, 261 },
        { 429, 505, 612, 564, 715, 726 },
        { 464, 617, 234, 647, 702, 263 },
        { 245, 249, 231, 462, 453, 646 },
        { 669, 510, 492, 512, 622, 135 }
    };
    Bonus s;

    cout << s.getMost(board) << endl;

    system("PAUSE");

    return 0;
}
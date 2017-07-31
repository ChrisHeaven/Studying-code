#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int get_marsh(int map[20][20], int n, int m) {
    int count = 0, max_count = 0, max_row = 0, max_col = 0, total_count = 0;

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < m - 2; j++)
            {
                for (int a = 0; a < 3; a++)
                {
                    for (int b = 0; b < 3; b++)
                    {
                        if (map[i + a][j + b] > 0)
                            count++;
                    }
                }

                if (max_count < count)
                {
                    max_row = i;
                    max_col = j;
                    max_count = count;
                }
                count = 0;
            }
        }

        for (int a = 0; a < 3; a++)
        {
            for (int b = 0; b < 3; b++)
            {
                if (map[max_row + a][max_col + b] > 0)
                    map[max_row + a][max_col + b]--;
            }
        }

        total_count = total_count + max_count;
        max_count = 0;
    }

    return total_count;
}

int main()
{
    int n, m, k, x, y;
    int map[20][20] = { 0 };

    while (cin >> n)
    {
        cin >> m;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> x;
            cin >> y;
            map[x][y]++;
        }

        cout << get_marsh(map, n, m) << endl;
    }

    return 0;
}
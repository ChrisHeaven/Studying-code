#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

float get_possi(int n, int m, int k, int map[20][20])
{
    float route_num[20][20] = { 0.0 };
    float possi = 0.0;

    route_num[0][0] = 1;
    if (map[0][1] > 0)
        route_num[0][1] = 0;
    else
        route_num[0][1] = 0.5;
    if (map[1][0] > 0)
        route_num[1][0] = 0;
    else
        route_num[1][0] = 0.5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0 && i > 1)
            {
                if (map[i][j] == 0)
                    route_num[i][j] = route_num[i - 1][j] / 2.0;
            }
            if (i == 0 && j > 1)
            {
                if (map[i][j] == 0)
                    route_num[i][j] = route_num[i][j - 1] / 2.0;
            }
            if (j != 0 && i != 0 && j != m - 1 && i != n - 1)
            {
                if (map[i][j] == 0)
                    route_num[i][j] = route_num[i][j - 1] / 2.0 + route_num[i - 1][j] / 2.0;
            }

            if (j == m - 1 && i > 0 && i != n - 1)
            {
                if (map[i][j] == 0)
                    route_num[i][j] = route_num[i][j - 1] / 2.0 + route_num[i - 1][j];
            }

            if (i == n - 1 && j > 0 && j != m - 1)
            {
                if (map[i][j] == 0)
                    route_num[i][j] = route_num[i][j - 1] + route_num[i - 1][j] / 2.0;
            }

            if (i == n - 1 && j == m - 1)
            {
                if (map[i][j] == 0)
                    route_num[i][j] = route_num[i][j - 1] + route_num[i - 1][j];
            }
        }
    }

    possi = route_num[n - 1][m - 1];

    if (map[0][0] > 0)
        possi = 0.0;

    return possi;
}

int main()
{
    int n = 0, m = 0, k = 0;
    while (cin >> n)
    {
        cin >> m >> k;
        int map[20][20] = { 0 };
        int row = 0;
        int col = 0;

        for (int i = 0; i < k; i++)
        {
            cin >> row >> col;
            map[row - 1][col - 1]++;
        }

        cout << fixed << setprecision(2) << get_possi(n, m, k, map) << endl;
    }

    return 0;
}
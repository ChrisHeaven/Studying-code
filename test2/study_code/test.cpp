#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int get_result(int n, string score)
{
    int up = 0, down = 0;
    int total_up[100] = { 0 }, total_down[100] = { 0 };
    int count_up = 0;
    int count_down = 0;

    for (int i = 1; i < n; i++)
    {
        if (score[i] > score[i - 1])
        {
            up++;
            if (i == n - 1)
            {
                if (up > 0)
                {
                    total_up[count_up] = up;
                    count_up++;
                }
                up = 0;
            }
        }
        else
        {
            if (up > 0)
            {
                total_up[count_up] = up;
                count_up++;
            }
            up = 0;
        }

        if (score[i] < score[i - 1])
        {
            down++;
            if (i == n - 1)
            {
                if (down > 0)
                {
                    total_down[count_down] = down;
                    count_down++;
                }
                down = 0;
            }
        }
        else
        {
            if (down > 0)
            {
                total_down[count_down] = down;
                count_down++;
            }
            down = 0;
        }
    }

    int iter = 0, sum = 0;
    if (count_up > count_down)
    {
        iter = count_down;
        sum = (total_up[count_up - 1] + 1) * total_up[count_up - 1] / 2;
    }
    else if (count_up < count_down)
    {
        iter = count_up;
        sum = (total_down[count_down - 1] + 1) * total_down[count_down - 1] / 2;
    }
    else if (count_up == count_down)
        iter = count_up;

    for (int i = 0; i < iter; i++)
        sum = sum + ((total_up[i] + 1) + 2) * total_up[i] / 2 + (total_down[i] + 1) * total_down[i] / 2;

    return sum;
}

int main()
{
    int n = 0, buff = 0;
    string score;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> buff;
            score.push_back(buff);
        }
        cout << get_result(n, score) << endl;
    }

    return 0;
}
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int move(int r, double point_1[], double point_2[]) {
    double dis = sqrt((point_1[0] - point_2[0]) * (point_1[0] - point_2[0]) + (point_1[1] - point_2[1]) * (point_1[1] - point_2[1]));
    int pre_step = dis / (2 * r);
    int step = 0;
    if (dis > pre_step * (2 * r))
        step = pre_step + 2;
    else
        step = pre_step;
    return step;
}

int main()
{
    int r;
    double point_1[2], point_2[2];
    while (cin >> r) {
        for (int i = 0; i < 2; i++)
        {
            cin >> point_1[i];
        }
        for (int i = 0; i < 2; i++)
        {
            cin >> point_2[i];
        }
        cout << move(r, point_1, point_2) << endl;
    }

    return 0;
}
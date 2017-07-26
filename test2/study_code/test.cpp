#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int ko(int a[])
{
    float dis_1, dis_2, dis_3;
    dis_1 = sqrt((a[1] - a[7]) * (a[1] - a[7]) + (a[2] - a[8]) * (a[2] - a[8]));
    dis_2 = sqrt((a[3] - a[7]) * (a[3] - a[7]) + (a[4] - a[8]) * (a[4] - a[8]));
    dis_3 = sqrt((a[5] - a[7]) * (a[5] - a[7]) + (a[6] - a[8]) * (a[6] - a[8]));

    int damage = 0;
    if (dis_1 <= a[0])
        damage++;
    if (dis_2 <= a[0])
        damage++;
    if (dis_3 <= a[0])
        damage++;

    return damage;
}

int main()
{
    int a[9];
    while (cin >> a[0]) {
        for (int i = 1; i < 9; i++)
            cin >> a[i];

        cout << ko(a) << "x" << endl;
    }
    //system("PAUSE");

    return 0;
}
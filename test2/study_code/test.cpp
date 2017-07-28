#include <iostream>
#include <stdlib.h>

using namespace std;

int b[200000];

int get_num(int a[], int b[])
{
    int type_count = 0;
    int num_count = 0;
    int sum = 0;
    int last = 0;

    for (int j = 0; j < a[2]; j++) {
        sum = sum + b[j];
    }
    if (sum <= a[1]) {
        type_count++;
        // num_count = 0;
        // t = 0;
    }

    for (int i = 0; i < a[0] - a[2]; i++)
    {
        // for (int j = i; j < i + a[2]; j++) {
        //     t = t + b[j];
        //     last = b[j + 1];
        // }
        sum = sum - b[i] + b[i + a[2]];
        if (sum <= a[1]) {
            type_count++;
            // num_count = 0;
            // t = 0;
        }
    }

    return type_count;
}

int main()
{
    int a[3];
    while (cin >> a[0]) {
        cin >> a[1];
        cin >> a[2];

        for (int i = 0; i < a[0]; i++) {
            cin >> b[i];
        }

        cout << get_num(a, b) << endl;

        // cout << a[0] << a[1] << a[2] << endl;
        // cout << b[1] << endl;
    }

    return 0;
}
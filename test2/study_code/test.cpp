#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

// char a[100];

int upgrade(int a[], int b[])
{
    for (int i = 0; i < a[0]; i++) {
        if (a[1] >= b[i])
            a[1] = a[1] + b[i];
        else {
            int result = sqrt(a[1] * b[i]);
            for (int j = result; j >= 0; j--) {
                if ((a[1] % j == 0) && (b[i] % j == 0))
                {
                    a[1] = a[1] + j;
                    break;
                }
            }
        }
    }

    return a[1];
}

int main()
{
    int a[2];
    while (cin >> a[0]) {
        cin >> a[1];
        // cout << a[0] << " " << a[1] << endl;

        int b[100000];
        for (int i = 0; i < a[0]; i++) {
            cin >> b[i];
        }
        // cout << b[2] << endl;
        cout << upgrade(a, b) << endl;
    }

    // system("PAUSE");

    return 0;
}
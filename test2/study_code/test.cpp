#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int find_max(int n, int[] a) {
    int max = -1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
}

int find_min(int n, int[] a) {
    int min = 1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
}

int count_area(int n, int[][] a)
{
    int max_x = find_max(a[][0]);
    int min_x = find_min(a[][0]);

    int max_y = find_max(a[][1]);
    int min_y = find_min(a[][1]);

    return 0;
}

int main()
{
    int n;
    cin >> n;
    int a[1000][2];
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        cin >> a[i][1];
    }

    // cout << n << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << a[i][0] << " " << a[i][1] << endl;
    // }

    count_area(n, a);

    system("PAUSE");

    return 0;
}
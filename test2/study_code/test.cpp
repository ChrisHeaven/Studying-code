#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

char no_repeat(int n[100])
{
    int k = 0;
    char a[100];
    for (int i = 0; i < 100; i++) {
        int flag = 0;
        for (int j = 0; i < 100; j++) {
            if (n[i] == n[j] && i != j) {
                break;
                flag = 1;
            }
        }
        if (flag == 0) {
            a[k] = n[i];
            k++;
        }
    }

    return a;
}

int main()
{
    char n[100] = {0};
    while (cin >> n) {
        cout << no_repeat(n);
    }
    return 0;
}
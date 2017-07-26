#include <iostream>
#include <stdlib.h>

using namespace std;

int a[1000][1000];

int last_num(int num)
{
    if (num > 1000)
        num = 1000;

    int del_point = 2;
    int arr_index = 0;
    int count = 0;

    for (int i = 0; i < num; i++) {
        a[arr_index][i] = i;
    }

    int sub_count = 0;
    while (1) {
        if (num - count == 1)
            break;

        if (del_point <= (num - 1 - count)) {
            a[arr_index][del_point] = -1;
            sub_count++;
            del_point = del_point + 3;
        }
        else {
            del_point = del_point - (num - count);

            int j = 0;
            for (int i = 0; i < num; i++) {
                if (a[arr_index][i] != -1) {
                    a[arr_index + 1][j] = a[arr_index][i];
                    j++;
                }
            }
            arr_index++;
            count = count + sub_count;
            sub_count = 0;
        }
        if (num - count == 1)
            break;
    }

    int value_ = a[arr_index][0];
    return value_;
}

int main()
{
    int n;
    while (cin >> n) {
        cout << last_num(n) << endl;
    }

    return 0;
}
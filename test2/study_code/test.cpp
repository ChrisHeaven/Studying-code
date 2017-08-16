#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int q_sort(int n, int a[10], int low, int high)
{
    if (low >= high)
        return 0;

    int begin = low;
    int end = high;
    int key = a[low];

    while (begin < end)
    {
        for (; end > begin; end--)
        {
            if (a[end] <= key)
            {
                a[low] = a[end];
                break;
            }
        }
        //high = end;

        for (; begin < end; begin++)
        {
            if (a[begin] >= key)
            {
                a[end] = a[begin];
                break;
            }
        }
        //low = begin;
    }

    a[begin] = key;

    q_sort(n, a, 0, begin - 1);
    q_sort(n, a, begin + 1, high);
}

int main()
{
    int n, a[10] = {0};
    string str;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << q_sort(n, a, 0, n - 1) << endl;
    }

    return 0;
}
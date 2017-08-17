#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int q_sort(int a[], int low, int high)
{
	int head = low;
	int tail = high;
	int key_value = a[low];

	if (head >= tail)
		return 0;

	while (head < tail)
	{
		for (; head < tail; tail--)
		{
			if (a[tail] < key_value)
			{
				a[head] = a[tail];
				break;
			}
		}

		for (; head < tail; head++)
		{
			if (a[head] > key_value)
			{
				a[tail] = a[head];
				break;
			}
		}
	}

	a[head] = key_value;

	q_sort(a, 0, head - 1);
	q_sort(a, head + 1, high);
}

int main()
{
	int n;
	string str;
	int a[] = { 339, 833, 73, 236, 653, 34, 23, 2422, 11314, 1110 };
	n = sizeof(a) / sizeof(int);

	q_sort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
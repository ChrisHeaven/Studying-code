#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int q_sort(int a[10], int low, int high)
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
			if (a[end] < key)
			{
				a[begin] = a[end];
				break;
			}
		}

		for (; begin < end; begin++)
		{
			if (a[begin] > key)
			{
				a[end] = a[begin];
				break;
			}
		}
	}

	a[begin] = key;

	q_sort(a, 0, begin - 1);
	q_sort(a, begin + 1, high);
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
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int bubble_sort(int a[], int n)
{
	for (int i = n; i >= 0; i--)
	{
		int temp = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j + 1] < a[j])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	return 0;
}

int main()
{
	int n;
	string str;
	int a[] = { 339, 833, 73, 236, 653, 34, 23, 2422, 11314, 1110 };
	n = sizeof(a) / sizeof(int);

	bubble_sort(a, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
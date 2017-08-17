#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

void heap_adjust(int a[], int father_node, int n)
{
	int child_node;
	int temp = 0;
	while (father_node * 2 + 1 <= n)
	{
		child_node = father_node * 2 + 1;

		if (a[child_node + 1] > a[child_node] && child_node + 1 <= n)
			child_node++;

		if (a[child_node] > a[father_node])
		{
			temp = a[child_node];
			a[child_node] = a[father_node];
			a[father_node] = temp;
			father_node = child_node;
		}
		else
			break;
	}
}

void heap_sort(int a[], int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
		heap_adjust(a, i, n);

	int temp = 0;
	for (int i = n; i > 0; i--)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;

		heap_adjust(a, 0, i - 1);
	}

}

int main()
{
	int n;
	string str;
	int a[] = { 339, 833, 73, 236, 653, 34, 23, 2422, 11314, 1110 };
	n = sizeof(a) / sizeof(int);

	heap_sort(a, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
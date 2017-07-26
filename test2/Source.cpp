#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int find_max(int n, int a[1000]) {
	int max = -1e9;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

int find_min(int n, int a[1000]) {
	int min = 1e9;
	for (int i = 0; i < n; i++) {
		if (a[i] < min)
			min = a[i];
	}
	return min;
}

int count_area(int n, int a[1000][2])
{
	int b[1000], c[1000];
	for (int i = 0; i < n; ++i)
	{
		b[i] = a[i][0];
		c[i] = a[i][1];
	}

	int max_x = find_max(n, b);
	int min_x = find_min(n, b);

	int max_y = find_max(n, c);
	int min_y = find_min(n, c);

	int area;
	if (max_x - min_x > max_y - min_y)
		area = (max_x - min_x) * (max_x - min_x);
	else
		area = (max_y - min_y) * (max_y - min_y);

	return area;
}

int main()
{
	int n;
	while (cin >> n) {
		int a[1000][2];
		for (int i = 0; i < n; i++) {
			cin >> a[i][0];
			cin >> a[i][1];
		}
		cout << count_area(n, a) << endl;
	}

	// cout << n << endl;
	// for (int i = 0; i < n; i++) {
	//     cout << a[i][0] << " " << a[i][1] << endl;
	// }

	//count_area(n, a);

	//system("PAUSE");

	return 0;
}
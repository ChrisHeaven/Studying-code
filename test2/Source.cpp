#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int get_max_dis(int n, int str[]) {
	int max_dis = 0, dis = 0, deleted_dis = 0;
	for (int i = 0; i < n - 1; i++)
	{
		dis = str[i + 1] - str[i];
			if (dis > max_dis)
				max_dis = dis;
	}

	int min_max = 1001;
	for (int i = 0; i < n - 2; i++)
	{
		deleted_dis = str[i + 2] - str[i];
		if (deleted_dis < min_max)
			min_max = deleted_dis;
	}

	if (max_dis < min_max)
		max_dis = min_max;

	return max_dis;
}

int main()
{
	int n;
	int str[100];
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		cout << get_max_dis(n, str) << endl;
	}

	return 0;
}
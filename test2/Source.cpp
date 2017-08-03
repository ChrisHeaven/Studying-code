#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int get_secret(int p, int n, vector<int> x)
{
	int full[300] = { 0 };
	int index = -1;

	for (int i = 0; i < n; i++)
	{
		if (full[x[i] % p] == 1)
		{
			index = i + 1;
			break;
		}
		full[x[i] % p] = 1;
	}

	return index;
}

int main()
{
	int p = 0, n = 0, buff = 0;
	while (cin >> p)
	{
		vector<int> x;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> buff;
			x.push_back(buff);
		}

		cout << get_secret(p, n, x) << endl;
	}

	return 0;
}
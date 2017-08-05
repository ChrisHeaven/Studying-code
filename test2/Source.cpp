#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int knew[100000] = { 0 }, be_knew[100000] = { 0 };
int index[20][100000] = { 0 };
int num[20] = { 0 };

int get_canddi(int n, int m, vector<int> s_1, vector<int> s_2, int t)
{

	for (int i = 0; i < m; i++)
	{
		if (s_1[i] != s_2[i])
		{
			knew[s_1[i]]++;
			be_knew[s_2[i]]++;
		}
	}

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (knew[i] == 0 && be_knew[i] == n - 1)
		{
			index[t][count] = i;
			count++;
		}
	}
	num[t] = count;

	return 0;
}

int main()
{
	int t, n, m, buff;

	while (cin >> t)
	{
		for (int i = 0; i < t; i++)
		{
			vector<int> s_1, s_2;

			cin >> n >> m;
			for (int j = 0; j < m; j++)
			{
				cin >> buff;
				s_1.push_back(buff);
				cin >> buff;
				s_2.push_back(buff);
			}

			get_canddi(n, m, s_1, s_2, i);
		}

		for (int i = 0; i < t; i++)
		{
			if (num[i] != 0)
			{
				cout << num[i] << endl;;
				for (int j = 0; j < num[i]; j++)
				{
					cout << index[i][j] << " ";
				}
				cout << " " << endl;
			}
			else
			{
				cout << num[i] << endl;
				cout << " " << endl;
			}
		}
	}

	return 0;
}
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<vector<int>> relation(6, vector<int>(6, 0));

void add_edge(int a, int b)
{
	relation[a][b + 1]++;
	relation[b][0]++;
}

void top_sort()
{
	int n = relation[0].size();
	int count = n;

	while (count > 0)
	{
		int zero = 0;
		for (int i = 0; i < n; i++)
		{
			if (relation[i][0] == 0)
			{
				cout << i << " ";
				relation[i][0] = -1;
				for (int j = 1; j < n; j++)
				{
					if (relation[i][j] > 0)
						relation[j - 1][0]--;
				}
				count--;
				zero++;
			}
		}
		if (zero == 0)
			break;
	}
	cout << endl;

	if (count > 0)
		cout << "ERROR" << endl;
}

void main()
{
	add_edge(5, 2);
	add_edge(5, 0);
	add_edge(4, 0);
	add_edge(4, 1);
	add_edge(2, 3);
	add_edge(3, 1);
	add_edge(1, 0);

	top_sort();

	system("pause");
}
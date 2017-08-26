#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

// long long dp[1000][1000];

int main(void)
{
	string buff;
	vector<int> a;
	string num;
	int index;

	getline(cin, buff);
	buff.push_back(' ');
	cin >> index;

	for (int i = 0; i < buff.size(); i++)
	{
		if (buff[i] != ' ')
			num.push_back(buff[i]);
		else
		{
			int temp = atoi(num.c_str());
			a.push_back(temp);
			num.clear();
		}
	}

	int max_num = -1e5;
	int max_index = 0;
	for (int j = 0; j < index; j++)
	{
		max_num = -1e5;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] > max_num)
			{
				max_num = a[i];
				max_index = i;
			}
		}
		a[max_index] = -1e5;
	}

	cout << max_num << endl;

	system("pause");
	return 0;
}
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int sunday(string a, string b, int hash_table[])
{
	int index = 0;

	for (int i = 0, j = 0; i < a.size(), j < b.size();)
	{
		if (a[i] == b[j])
		{
			i++;
			j++;
			if (j == b.size())
			{
				index = i - j;
				break;
			}
		}
		else
		{
			if (i + b.size() < a.size())
				i = i + b.size();
			else
			{
				index = -1;
				break;
			}

			while (i < a.size())
			{
				if (hash_table[(int)a[i]] > 0)
				{
					j = 0;
					i = i - hash_table[a[i]] + 1;
					break;
				}
				i++;
			}
		}
	}
	return index;
}

int main()
{
	string a = "LESSONS SOFTWARE% TEARNED IN SOFTWARE% TE";
	string b = "SOFTWARE%";
	int hash_table[128] = {0};

	for (int i = 0; i < b.size(); i++)
		hash_table[(int)b[i]] = i + 1;

	cout << sunday(a, b, hash_table) << endl;
	cout << a.find(b) << endl;

	system("pause");
	return 0;
}
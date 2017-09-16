#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int temp[1000] = {0};

int main()
{
	string arr;
	string div;
	while (cin >> arr >> div)
	{
		for (int i = 0; i < arr.size();)
		{
			int flag = 1;
			if (arr[i] == div[0])
			{
				for (int j = i; j < i + div.size(); j++)
				{
					if (arr[j] != div[j - i])
					{
						flag = 1;
						break;
					}
					else
						flag = 0;
				}
			}

			if (flag == 0)
			{
				for (int j = i; j < i + div.size(); j++)
				{
					arr[j] = ' ';
					if (j == i + div.size() - 1)
						arr[j] = '\n';
				}
				i = i + div.size();
			}
			else
				i++;
		}

		for (int i = 0; i < arr.size(); i++)
			cout << arr[i];

		cout << endl;
	}

	return 0;
}
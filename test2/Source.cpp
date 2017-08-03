#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

char string_[20][1000000] = { "" };

int get_secret(int t)
{
	char secret[20] = { "" };
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 1000000; j++)
		{
			int flag = 0;
			for (int k = 0; k < 1000000; k++)
			{
				if (string_[i][j] == string_[i][k] && j != k)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				secret[i] = string_[i][j];
				break;
			}
		}
		printf("%c\n", secret[i]);
	}

	return 0;
}

int main()
{
	int t;
	while (cin >> t)
	{
		for (int i = 0; i < t; i++)
		{
			scanf("%s", string_[i]);
		}

		get_secret(t);
	}

	return 0;
}
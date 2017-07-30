#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	float str[4];
	while (cin >> str[0])
	{
		for (int i = 1; i < 4; i++)
		{
			cin >> str[i];
		}

		for (int i = 0; i < str[3]; i++)
		{
			str[1] = (str[1] + 1) * (1 - str[2]) + 21 * str[2];
		}

		cout << ceil(str[1]) << endl;
	}

	return 0;
}
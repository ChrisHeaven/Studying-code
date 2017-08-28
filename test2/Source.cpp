#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(void)
{
	string num;

	while (cin >> num)
	{
		int index = -1;
		if (num.size() == 1)
		{
			index = index + (num[0] - 'a') * (((25 + 1) * 25 + 1) * 25 + 1) + 1;
		}
		if (num.size() == 2)
		{
			index = index + (num[0] - 'a') * (((25 + 1) * 25 + 1) * 25 + 1) + 1;
			index = index + (num[1] - 'a') * ((25 + 1) * 25 + 1) + 1;
		}
		if (num.size() == 3)
		{
			index = index + (num[0] - 'a') * (((25 + 1) * 25 + 1) * 25 + 1) + 1;
			index = index + (num[1] - 'a') * ((25 + 1) * 25 + 1) + 1;
			index = index + (num[2] - 'a') * (25 + 1) + 1;
		}
		if (num.size() == 4)
		{
			index = index + (num[0] - 'a') * (((25 + 1) * 25 + 1) * 25 + 1) + 1;
			index = index + (num[1] - 'a') * ((25 + 1) * 25 + 1) + 1;
			index = index + (num[2] - 'a') * (25 + 1) + 1;
			index = index + (num[3] - 'a') + 1;
		}

		cout << index << endl;
	}

	// system("pause");
	return 0;
}
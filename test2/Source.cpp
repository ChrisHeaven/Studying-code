#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int index = 0;
		for (int i = 0; i <= 10; i++)
		{
			if (pow(2, i) > n + 1)
			{
				index = i;
				break;
			}
		}

		cout << pow(2, index - 1) - 1 << endl;
	}

	return 0;
}
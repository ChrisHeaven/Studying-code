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
	int n;
	while (cin >> n)
	{
		// long long sum = 1;
		// for (long long i = 1; i <= n; i++)
		// 	sum = sum * i;

		// long long count = 0;
		// while (sum % 10 == 0)
		// {
		// 	count++;
		// 	sum = sum / 10;
		// }

		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			int current_i = i;
			while (current_i % 5 == 0)
			{
				count++;
				current_i = current_i / 5;
			}
		}

		cout << count << endl;
	}

	// system("pause");
	return 0;
}
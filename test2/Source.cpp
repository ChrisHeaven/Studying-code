#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
	int n;
	while (cin >> n)
	{
		int buff;
		vector<int> arr_for_max;
		vector<int> arr_for_min;

		for (int i = 0; i < n; i++)
		{
			cin >> buff;
			arr_for_max.push_back(buff);
			arr_for_min.push_back(buff);
		}

		long long sum = 1;
		int max_three[3];
		int min_three[3];
		int max_index = 0, min_index = 0;

		for (int i = 0; i < 3; i++)
		{
			int max_value = -1e6;
			int min_value = 1e6;
			for (int j = 0; j < n; j++)
			{
				if (arr_for_max[j] > max_value)
				{
					max_value = arr_for_max[j];
					max_index = j;
				}

				if (arr_for_min[j] < min_value)
				{
					min_value = arr_for_min[j];
					min_index = j;
				}
			}
			max_three[i] = max_value;
			arr_for_max[max_index] = -1e6;

			min_three[i] = min_value;
			arr_for_min[min_index] = 1e6;
		}

		long long sum_1, sum_2;

		sum_1 = max_three[0];
		sum_1 = sum_1 * max_three[1];
		sum_1 = sum_1 * max_three[2];

		sum_2 = max_three[0];
		sum_2 = sum_2 * min_three[0];
		sum_2 = sum_2 * min_three[1];

		if (sum_1 >= sum_2)
			sum = sum_1;
		else
			sum = sum_2;

		cout << sum << endl;
	}
	// system("pause");
	return 0;
}
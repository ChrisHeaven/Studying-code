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
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		int sum = 0;
		for (int len = len1; len <= len2; len++)
		{
			int sum_1 = 0, sum_2 = 0;
			for (int i = 0; i < len; i++)
				sum_1 = sum_1 + pow(26, len - i - 1) * (s1[i] - 'a');

			for (int i = 0; i < len; i++)
				sum_2 = sum_2 + pow(26, len - i - 1) * (s2[i] - 'a');
			sum = (sum + (sum_2 - sum_1)) % 1000007;
		}

		cout << sum - 1 << endl;
	}

	return 0;
}
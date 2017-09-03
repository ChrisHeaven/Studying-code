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
	string str_1, str_2;
	while (cin >> str_1 >> str_2)
	{
		vector<int> num_1;
		vector<int> num_2;

		for (int i = str_1.size() - 1; i >= 0; i--)
			num_1.push_back((int)(str_1[i] - '0'));

		for (int i = str_2.size() - 1; i >= 0; i--)
			num_2.push_back((int)(str_2[i] - '0'));

		int length = num_1.size() + num_2.size();
		vector<int> result(length, 0);

		for (int i = 0; i < num_1.size(); i++)
		{
			for (int j = 0; j < num_2.size(); j++)
			{
				int temp = 0;
				temp = num_1[i] * num_2[j];
				if (temp >= 10)
				{
					result[i + j] += temp % 10;
					if (result[i + j] >= 10)
					{
						result[i + j + 1] += result[i + j] / 10;
						result[i + j] = result[i + j] % 10;
					}
					result[i + j + 1] += temp / 10;
				}
				else
				{
					result[i + j] += temp;
					if (result[i + j] >= 10)
					{
						result[i + j + 1] += result[i + j] / 10;
						result[i + j] = result[i + j] % 10;
					}
				}
			}
		}

		for (int i = result.size() - 1; i >= 0; i--)
		{
			if (result.back() == 0)
				result.pop_back();
			else 
			{
				if (result[i] >= 10)
				{
					result[i + 1] = result[i] / 10;
					result[i] = result[i] % 10;
				}
			}
		}
		for (int i = result.size() - 1; i >= 0; i--)
			cout << result[i];

		cout << endl;
	}
	// system("pause");
	return 0;
}
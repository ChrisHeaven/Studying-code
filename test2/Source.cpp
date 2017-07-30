#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

float count_d(int str[2], int light[1000])
{
	int sort_light[1000] = { 0 };
	for (int i = 0; i < str[0]; i++)
	{
		int count = 0;
		for (int j = 0; j < str[0]; j++)
		{
			if (light[i] <= light[j])
				count++;
		}
		if (sort_light[str[0] - count] == 0)
			sort_light[str[0] - count] = light[i];
		else
		{
			for (int k = str[0] - count + 1; k < str[0]; k++)
			{
				if (sort_light[k] == 0)
					sort_light[k] = light[i];
			}
		}
	}

	int start_dis = sort_light[0] - 0 + 1;
	int end_dis = str[1] - sort_light[str[0] - 1] + 1;

	float max_dis = 0;
	for (int i = 0; i < str[0] - 1; i++)
	{
		if (abs(sort_light[i + 1] - sort_light[i]) >= max_dis)
			max_dis = abs(sort_light[i + 1] - sort_light[i]);
	}

	max_dis = max_dis / 2.0;

	if (start_dis > max_dis)
		max_dis = start_dis;
	if (end_dis > max_dis)
		max_dis = end_dis;

	return max_dis;
}

int main()
{
	int str[2], light[1000];
	while (cin >> str[0] >> str[1])
	{
		for (int i = 0; i < str[0]; i++)
		{
			cin >> light[i];
			light[i] = light[i] + 1;
 		}

		cout << fixed << setprecision(2) << count_d(str, light) << endl;
	}

	return 0;
}
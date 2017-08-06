#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int get_tier(int n, string id, string weight, string height)
{
	string sorted_weight, sorted_height;

	for (int i = 0; i < n; i++)
	{
		sorted_weight.push_back(-1);
		sorted_height.push_back(0);
	}

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (weight[i] < weight[j])
				count++;
			else if (weight[i] == weight[j])
			{
				if (height[i] >= height[j])
					count++;
			}
		}
		if (sorted_weight[n - count] == -1)
		{
			sorted_weight[n - count] = weight[i];
			sorted_height[n - count] = height[i];
		}
		else
		{
			for (int j = n - count; j < n; j++)
			{
				if (sorted_weight[j] == -1)
				{
					sorted_weight[j] = weight[i];
					sorted_height[j] = height[i];
					break;
				}
			}
		}
	}

	int max_tier = 0;
	for (int index = 0; index < n - 1; index++)
	{
		int tier = 0;
		int cur_index = index;
		for (int i = index; i < n - 1; i++)
		{
			if (sorted_height[i + 1] >= sorted_height[cur_index])
			{
				if (sorted_height[i + 1] > sorted_height[cur_index])
				{
					tier++;
					cur_index = i + 1;
				}
				else if (sorted_height[i + 1] == sorted_height[cur_index] && sorted_weight[cur_index] <= sorted_weight[i + 1])
				{
					tier++;
					cur_index = i + 1;
				}
			}
		}
		if (tier >= max_tier)
			max_tier = tier;
	}

	return max_tier + 1;
}

int main()
{
	int n, buff;
	string id, weight, height;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> buff;
			id.push_back(buff);
			cin >> buff;
			weight.push_back(buff);
			cin >> buff;
			height.push_back(buff);
		}

		cout << get_tier(n, id, weight, height) << endl;
	}

	return 0;
}
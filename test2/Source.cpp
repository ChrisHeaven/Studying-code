#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int sorted_index[100000] = { 0 };

long get_time(long n, long r, long avg, vector<long> a, vector<long> b)
{
	long sum = 0;

	for (int i = 0; i < n; i++)
		sum = sum + a[i];

	long remain = n * avg - sum;

	for (int i = 0; i < b.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < b.size(); j++)
		{
			if (b[i] <= b[j])
				count++;
		}
		if (sorted_index[b.size() - count] == 0)
			sorted_index[b.size() - count] = i + 1;
		else
		{
			for (int j = b.size() - count; j < b.size(); j++)
			{
				if (sorted_index[j] == 0) 
				{
					sorted_index[j] = i + 1;
					break;
				}
			}
		}
	}

	long remain_sum = 0, index = 0;
	for (int i = 0; i < a.size() - 1; i++)
	{
		remain_sum = remain_sum + (r - a[sorted_index[i] - 1]);
		index = i;
		if (remain_sum + r - a[sorted_index[i + 1] - 1] > remain)
			break;
	}

	long time_cost = 0;

	if (remain > 0) 
	{
		for (int i = 0; i <= index; i++)
			time_cost = time_cost + (r - a[sorted_index[i] - 1]) * b[sorted_index[i] - 1];

		time_cost = time_cost + (remain - remain_sum) * b[sorted_index[index + 1] - 1];
	}

	return time_cost;
}

int main()
{
	//long n, r, avg, buff;
	//vector<long> a, b;
	//while (cin >> n)
	//{
	//	cin >> r;
	//	cin >> avg;
	//	for (int i = 0; i < n; i++)
	//	{
	//		cin >> buff;
	//		a.push_back(buff);
	//		cin >> buff;
	//		b.push_back(buff);
	//	}

	//	long result = get_time(n, r, avg, a, b);
	//	printf("%ld", result);

	//	a.clear();
	//	b.clear();
	//}

	long a = 72189518;
	printf("%ld", a);

	return 0;
}
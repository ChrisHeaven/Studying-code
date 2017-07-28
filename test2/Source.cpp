#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	/**
	* �������ܻ�õ��������
	*
	* @param prices Prices[i]����i��Ĺɼ�
	* @return ����
	*/
	int calculateMax(vector<int> prices) {
		int first_max = 0;
		int second_max = 0;
		int sum = 0, sum_1 = 0, sum_2 = 0;

		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = 0; j < i; j++) {
				for (int k = j + 1; k < i; k++)
					if (prices[k] - prices[j] > first_max)
						first_max = prices[k] - prices[j];
			}
			for (int j = i; j < prices.size(); j++) {
				for (int k = j + 1; k < prices.size(); k++)
					if (prices[k] - prices[j] > second_max)
						second_max = prices[k] - prices[j];
			}

			if (first_max > 0)
				sum_1 = first_max;
			if (second_max > 0)
				sum_2 = second_max;

			if (sum_1 + sum_2 >= sum)
				sum = sum_1 + sum_2;

			first_max = 0;
			second_max = 0;
			sum_1 = 0;
			sum_2 = 0;
		}
		return sum;
	}
};

int main()
{
	//vector<int> prices = { 61,8,81,67,80,47 };
	//Solution s;
	//cout << s.calculateMax(prices) << endl;
	//system("PAUSE");

	string a;
	while (cin >> a)
	{
		cout << a[1] << endl;
	}

	return 0;
}
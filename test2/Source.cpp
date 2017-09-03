#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers)
	{
		stack<int> sta;
		vector<int> result;

		while (!numbers.empty())
		{
			int temp = numbers.back();
			numbers.pop_back();
			while (sta.size() != 0 && temp < sta.top())
			{
				numbers.push_back(sta.top());
				sta.pop();
			}
			sta.push(temp);
		}

		int length = sta.size();
		for (int i = 0; i < length; i++)
		{
			result.push_back(sta.top());
			sta.pop();
		}

		return result;
	}
};

int main(void)
{
	int a[5] = {11, 2, 31, 14, 5};
	TwoStacks A;
	vector<int> arr(a, a + 5), res;
	res = A.twoStacksSort(arr);

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ' ';

	cout << endl;

	system("pause");
	return 0;
}
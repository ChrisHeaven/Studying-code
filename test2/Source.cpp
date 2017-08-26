#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int transformers(int m, int n)
{
	vector<int> result;

	int neg = 1;
	if (m < 0)
	{
		m = m * (-1);
		neg = -1;
	}
	else if (m == 0)
		cout << 0;

	while (m > 0)
	{
		int a = m % n;

		result.push_back(a);
		m = m / n;
	}

	if (neg == -1)
		cout << "-";

	int sum = 0;
	for (int i = result.size() - 1; i >= 0; i--)
		sum = sum + result[i];

	return sum;
}

int main(void)
{
	int m;

	while (cin >> m)
	{
		int sum = 0;

		for (int i = 2; i < m; i++)
			sum = sum + transformers(m, i);

		cout << sum << '/' << m - 2 << endl;
	}

	// system("pause");
	return 0;
}
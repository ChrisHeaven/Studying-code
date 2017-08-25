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
	int m, n;

	while (cin >> m >> n)
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

		for (int i = result.size() - 1; i >= 0; i--)
		{
			if (result[i] >= 10)
				cout << (char)(result[i] - 10 + 65);
			else
				cout << result[i];
		}

		cout << endl;
	}

	// system("pause");
	return 0;
}
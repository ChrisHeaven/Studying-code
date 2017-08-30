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
	string str;

	while (cin >> str)
	{
		long long sum = 0;
		for (int i = 0; i < str.size(); i++)
			sum = sum + ((int)(str[i] - 'a') + 1) * pow(26, str.size() - i - 1);

		cout << sum << endl;
	}

	// system("pause");
	return 0;
}
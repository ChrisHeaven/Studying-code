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
	int k, node[3];

	while (cin >> k)
	{
		for (int i = 0; i < 3; i++)
			cin >> node[i];

		int flag = 0, root = pow(2, k - 1);
		while (flag == 0)
		{
			if (node[0] < root && node[1] < root && node[2] < root)
			{
				root = root - pow(2, k - 2);
				k--;
			}
			else if (node[0] > root && node[1] > root && node[2] > root)
			{
				root = root + pow(2, k - 2);
				k--;
			}
			else
				flag = 1;
		}

		cout << root << endl;
	}

	// system("pause");
	return 0;
}
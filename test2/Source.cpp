#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int set_check(int arr[32], int id, int op)
{
	int index_1 = id / 32;
	int index_2 = id % 32;
	unsigned int temp = 0x80000000;

	if (op == 0)
	{
		temp = temp >> index_2;
		arr[index_1] = arr[index_1] | temp;
		return -1;
	}
	else
	{
		temp = temp >> index_2;
		if ((arr[index_1] & temp) == 0)
			return 0;
		else
			return 1;
	}
}

int main(void)
{
	int id_1, id_2;
	int arr[32] = { 0 };

	while (cin >> id_1 >> id_2)
	{
		if (id_1 < 1 || id_1 > 1024 || id_2 < 1 || id_2 > 1024)
			cout << -1 << endl;
		else
		{
			set_check(arr, id_1 - 1, 0);
			cout << set_check(arr, id_2 - 1, 1) << endl;
		}
	}

	// system("pause");
	return 0;
}
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int b[200000];

int get_num(int a[], int b[])
{
	int type_count = 0;
	int num_count = 0;
	int sum = 0;
	int last = 0;

	for (int j = 0; j < a[2]; j++) {
		sum = sum + b[j];
	}
	if (sum <= a[1])
		type_count++;

	for (int i = 0; i < a[0] - a[2]; i++)
	{
		sum = sum - b[i] + b[i + a[2]];
		if (sum <= a[1])
			type_count++;
	}

	return type_count;
}

int main()
{
	int a[3];
	//while (cin >> a[0]) {
	//	cin >> a[1];
	//	cin >> a[2];

	//	for (int i = 0; i < a[0]; i++) {
	//		cin >> b[i];
	//	}

	//	cout << get_num(a, b) << endl;
	//}

	vector<vector<int> > f = { {2, 2},{3, 3},{4, 4} };
	cout << f[0][1] << f[1][0] << endl;
	system("PAUSE");
	return 0;
}
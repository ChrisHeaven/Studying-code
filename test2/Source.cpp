#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int last_num(int num)
{
	if (num > 1000)
		num = 1000;

	int a[1000][1000];
	int del_point = 2;
	int arr_index = 0;
	int count = 0;


	for (int i = 0; i < num; i++) {
		a[arr_index][i] = i;
	}

	while (1) {
		if (num - count == 1)
			break;

		if (del_point <= (num - 1 - count)) {
			a[arr_index][del_point] = -1;
			del_point = del_point + 3;
		}
		else {
			del_point = del_point - (num - count);

			int j = 0;
			int sub_count = 0;
			for (int i = 0; i < (num - count); i++) {
				if (a[arr_index][i] == -1)
					sub_count++;
				else {
					a[arr_index + 1][j] = a[arr_index][i];
					j++;
				}
			}
			arr_index++;
			count = count + sub_count;
		}
		if (num - count == 1)
			break;
	}

	int value_ = a[arr_index][0];
	cout << value_ << endl;
	return 0;
}

int main()
{
	/* code */
	/*int n = 249;
	while(cin >> n)
		last_num(n);*/

	int n;
	cin >> n;
	int a[1000][2];
	for (int i = 0; i < n; i++) {
		cin >> a[i][0];
		cin >> a[i][1];
	}

	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i][0] << " " << a[i][1] << endl;
	}

	system("PAUSE");

	return 0;
}
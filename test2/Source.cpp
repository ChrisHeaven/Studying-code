#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

char a[100];

int no_repeat(char n[100])
{
	int k = 0;
	for (int i = 0; i < 100; i++) {
		int flag = 0;
		for (int j = 0; j < 100; j++) {
			if (n[i] == n[j] && i > j) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			a[k] = n[i];
			k++;
		}
	}

	return 0;
}

int main()
{
	char n[100] = { 0 };
	while (cin >> n) {
		no_repeat(n);
		cout << a << endl;
	}
	return 0;
}
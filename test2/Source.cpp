#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

void point_test(int &a)
{
	a = a + 10;
}

void main(void)
{
	int a = 0;
	point_test(a);
	cout << a << endl;

	system("pause");
}
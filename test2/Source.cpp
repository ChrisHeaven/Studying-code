#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

//array是待调整的堆数组，i是待调整的数组元素的位置，nlength是数组的长度
//本函数功能是：根据数组array构建大根堆
void HeapAdjust(int array[], int father_node, int a_length)
{
	int child_node;
	int temp = 0;

	while (2 * father_node + 1 < a_length)
	{
		child_node = 2 * father_node + 1;

		if (array[child_node] < array[child_node + 1] && child_node + 1 < a_length)
			child_node++;

		if (array[child_node] > array[father_node])
		{
			temp = array[child_node];
			array[child_node] = array[father_node];
			array[father_node] = temp;
			father_node = child_node;
		}
		else
			break;
	}
}
//堆排序算法
void HeapSort(int array[], int length)
{
	for (int i = length / 2 - 1; i >= 0; i--)
		HeapAdjust(array, i, length);

	int temp = 0;
	for (int i = length - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		HeapAdjust(array, 0, i);
	}
}
int main()
{
	int i;
	int num[] = { 92, 8, 17, 6, 5, 41, 53, 2, 1, 110 };
	int a_length = sizeof(num) / sizeof(int);

	HeapSort(num, a_length);
	for (i = 0; i < a_length; i++)
		cout << num[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
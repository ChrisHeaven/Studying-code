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
void HeapAdjust(int array[], int child_node, int nLength)
{
	int father_node = (child_node - 1) / 2;

	int temp = 0;
	if (array[child_node] > array[father_node])
	{
		temp = array[father_node];
		array[father_node] = array[child_node];
		array[child_node] = temp;
	}
}
//堆排序算法
void HeapSort(int array[], int length)
{
	int i;

	for (i = length; i > 0; i--)
		HeapAdjust(array, i, length);
	//从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
	cout << array[0] << endl;
	int temp = 0;
	for (i = length - 1; i > 0; --i)
	{
		//把第一个元素和当前的最后一个元素交换，
		//保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		//不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
		if (array[2] > array[1])
			HeapAdjust(array, 2, length);
		else
			HeapAdjust(array, 1, length);

		cout << array[0] << endl;
	}
}
int main()
{
	int i;
	int num[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	HeapSort(num, sizeof(num) / sizeof(int));
	for (i = 0; i < sizeof(num) / sizeof(int); i++)
		printf("%d ", num[i]);
	//for (int i = sizeof(num) / sizeof(int) - 1; i >= 0; i--)
	//{
	//	for (int j = sizeof(num) / sizeof(int) - 1; j > 0; j--)
	//	{
	//		int father_node = (j - 1) / 2;

	//		int temp = 0;
	//		if (num[j] > num[father_node])
	//		{
	//			temp = num[father_node];
	//			num[father_node] = num[j];
	//			num[j] = temp;
	//		}
	//	}
	//	cout << num[0] << endl;
	//	num[0] = -1;
	//}

	system("pause");
	return 0;
}
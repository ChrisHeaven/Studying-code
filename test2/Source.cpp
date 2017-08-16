#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

//array�Ǵ������Ķ����飬i�Ǵ�����������Ԫ�ص�λ�ã�nlength������ĳ���
//�����������ǣ���������array���������
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
//�������㷨
void HeapSort(int array[], int length)
{
	int i;

	for (i = length; i > 0; i--)
		HeapAdjust(array, i, length);
	//�����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
	cout << array[0] << endl;
	int temp = 0;
	for (i = length - 1; i > 0; --i)
	{
		//�ѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ�����
		//��֤��ǰ�����һ��λ�õ�Ԫ�ض��������ڵ��������֮������
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		//������С����heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
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
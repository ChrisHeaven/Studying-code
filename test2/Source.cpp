#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

/* PΪģʽ�����±��0��ʼ */
void GetNext(string P, int next[])
{
	int p_len = P.size();
	int i = 0;   //P���±�
	int j = -1;
	next[0] = -1;

	while (i < p_len)
	{
		if (j == -1 || P[i] == P[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

/* ��S���ҵ�P��һ�γ��ֵ�λ�� */
int KMP(string S, string P, int next[])
{
	GetNext(P, next);

	int i = 0;  //S���±�
	int j = 0;  //P���±�
	int s_len = S.size();
	int p_len = P.size();

	while (i < s_len && j < p_len)
	{
		if (j == -1 || S[i] == P[j])  //P�ĵ�һ���ַ���ƥ���S[i] == P[j]
		{
			i++;
			j++;
		}
		else
			j = next[j];  //��ǰ�ַ�ƥ��ʧ�ܣ�������ת
	}

	if (j == p_len)  //ƥ��ɹ�
		return i - j;

	return -1;
}

int main()
{
	int next[100] = { 0 };

	cout << KMP("bbc abcdab abcdabcdabde", "abcdabd", next) << endl; //15

	system("pause");

	return 0;
}
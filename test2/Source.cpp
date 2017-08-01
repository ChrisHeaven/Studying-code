#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

int fibo[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
char storage[5000][100] = { "" };
int sorted_storage[5000] = { 0 };

int get_lucky(char str[100], int length) {
	// write code here

	int store_count = 0;
	for (int a = 1; a < length; a++)
	{
		for (int i = 0; i < length - (a - 1); i++)
		{
			int lex[26] = { 0 };
			char buff[100] = { "" };
			for (int j = i; j < i + a; j++)
			{
				int index = int(str[j]) - 97;
				if (lex[index] == 0)
					lex[index] = 1;
				buff[j - i] = str[j];
			}

			int count = 0;
			for (int k = 0; k < 26; k++)
			{
				if (lex[k] == 1)
					count++;
			}

			for (int k = 0; k < 12; k++)
			{
				int flag = 0;
				if (count == fibo[k])
				{
					for (int j = 0; j < store_count; j++)
					{
						if (strcmp(storage[j], buff) == 0)
						{
							flag = 1;
							break;
						}
					}
					if (flag)
						break;
					else
					{
						for (int j = 0; j < a; j++)
							storage[store_count][j] = buff[j];
						store_count++;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < store_count; i++)
	{
		int min_count = 0;
		for (int j = 0; j < store_count; j++)
		{
			if (strcmp(storage[i],storage[j]) <= 0)
				min_count++;
		}

		if (sorted_storage[store_count - min_count] == 0)
			sorted_storage[store_count - min_count] = i + 1;
		else
		{
			for (int k = store_count - min_count; k < store_count; k++)
			{
				if (sorted_storage[k] == 0)
				{
					sorted_storage[k] = i + 1;
					break;
				}
			}
		}
	}

	for (int i = 0; i < store_count; i++)
	{
		cout << storage[sorted_storage[i] - 1] << endl;
	}

	//cout << store_count << endl;
	return 0;
}

int main()
{
	char str[100] = { "" };
	string s;
	while (cin >> s)
	{
		//cout << str.size() << endl;
		for (int i = 0; i < s.size(); i++)
		{
			str[i] = s.at(i);
		}
		int length = s.size();
		get_lucky(str, length);
	}

	return 0;
}
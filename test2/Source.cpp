#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

//int count_ = 0;
char result[9] = { 0 };

int get_result(string password, int char_size)
{
	int remain = 0;
	for (int i = 0; i < password.size(); i++)
	{
		result[char_size - password.size()] = password[i];
		//count_++;
		string buff;
		for (int j = 0; j < password.size(); j++)
		{
			if (j != i)
			{
				buff.push_back(password[j]);
			}
		}
		remain = buff.size();
		if (remain == 0)
			break;
		get_result(buff, char_size);
	}
	if (remain == 0)
	{
		for (int i = 0; i < char_size; i++)
		{
			cout << result[i];
		}
		cout << endl;
		//count_-= 2;
	}

	return 0;

}

int main()
{
	string password;

	while (getline(cin, password))
	{
		get_result(password, password.size());
	}

	return 0;
}
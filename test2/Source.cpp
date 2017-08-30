#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> result;

void en_ch(vector<string> word_set)
{
	for (int i = 0; i < word_set.size(); i++)
	{
		if (word_set[i].compare("One") == 0)
			result.push_back("Yi");
		else if (word_set[i].compare("Two") == 0)
			result.push_back("Er");
		else if (word_set[i].compare("Three") == 0)
			result.push_back("San");
		else if (word_set[i].compare("Four") == 0)
			result.push_back("Si");
		else if (word_set[i].compare("Five") == 0)
			result.push_back("Wu");
		else if (word_set[i].compare("Six") == 0)
			result.push_back("Liu");
		else if (word_set[i].compare("Seven") == 0)
			result.push_back("Qi");
		else if (word_set[i].compare("Eight") == 0)
			result.push_back("Ba");
		else if (word_set[i].compare("Nine") == 0)
			result.push_back("Jiu");
		else if (word_set[i].compare("Zero") == 0)
			result.push_back("Ling");
		else if (word_set[i].compare("Double") == 0)
		{
			if (word_set[i + 1].compare("One") == 0)
				result.push_back("Yi");
			else if (word_set[i + 1].compare("Two") == 0)
				result.push_back("Er");
			else if (word_set[i + 1].compare("Three") == 0)
				result.push_back("San");
			else if (word_set[i + 1].compare("Four") == 0)
				result.push_back("Si");
			else if (word_set[i + 1].compare("Five") == 0)
				result.push_back("Wu");
			else if (word_set[i + 1].compare("Six") == 0)
				result.push_back("Liu");
			else if (word_set[i + 1].compare("Seven") == 0)
				result.push_back("Qi");
			else if (word_set[i + 1].compare("Eight") == 0)
				result.push_back("Ba");
			else if (word_set[i + 1].compare("Nine") == 0)
				result.push_back("Jiu");
			else if (word_set[i + 1].compare("Zero") == 0)
				result.push_back("Ling");
		}
		else
		{
			result.clear();
			result.push_back("ERROR");
			break;
		}
	}
}

void ch_en(vector<string> word_set)
{
	for (int i = 0; i < word_set.size(); i++)
	{
		if (word_set[i].compare("Yi") == 0)
			result.push_back("One");
		else if (word_set[i].compare("Er") == 0)
			result.push_back("Two");
		else if (word_set[i].compare("San") == 0)
			result.push_back("Three");
		else if (word_set[i].compare("Si") == 0)
			result.push_back("Four");
		else if (word_set[i].compare("Wu") == 0)
			result.push_back("Five");
		else if (word_set[i].compare("Liu") == 0)
			result.push_back("Six");
		else if (word_set[i].compare("Qi") == 0)
			result.push_back("Seven");
		else if (word_set[i].compare("Ba") == 0)
			result.push_back("Eight");
		else if (word_set[i].compare("Jiu") == 0)
			result.push_back("Nine");
		else if (word_set[i].compare("Ling") == 0)
			result.push_back("Zero");
		else
		{
			result.clear();
			result.push_back("ERROR");
			break;
		}
	}
}

int main(void)
{
	string str;
	while (getline(cin, str))
	{
		vector<string> word_set;
		string temp;
		temp.push_back(str[0]);
		for (int i = 1; i < str.size(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				word_set.push_back(temp);
				temp.clear();
				temp.push_back(str[i]);
			}
			else
			{
				temp.push_back(str[i]);
				if (i == str.size() - 1)
					word_set.push_back(temp);
			}
		}

		if (word_set[0][0] == 'Y' || word_set[0][0] == 'W' || word_set[0][0] == 'L' || word_set[0][0] == 'Q' || word_set[0][0] == 'B' || word_set[0][0] == 'J')
			ch_en(word_set);
		else if (word_set[0][0] == 'O' || word_set[0][0] == 'T' || word_set[0][0] == 'F' || word_set[0][0] == 'N' || word_set[0][0] == 'Z' || word_set[0][0] == 'D')
			en_ch(word_set);
		else if (word_set[0][0] == 'E')
		{
			if (word_set[0].compare("Er") == 0)
				ch_en(word_set);
			else if (word_set[0].compare("Eight") == 0)
				en_ch(word_set);
			else
				cout << "ERROR";
		}
		else if (word_set[0][0] == 'S')
		{
			if (word_set[0].compare("Si") == 0 || word_set[0].compare("San") == 0)
				ch_en(word_set);
			else if (word_set[0].compare("Six") == 0 || word_set[0].compare("Seven") == 0)
				en_ch(word_set);
			else
				cout << "ERROR";
		}
		for (int i = 0; i < result.size(); i++)
			cout << result[i];

		cout << endl;
		result.clear();
	}

	system("pause");
	return 0;
}
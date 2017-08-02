#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int output_log(vector<string> path_name, vector<string> line_num)
{
	char file_name[100][16] = { "" }, buff[16] = { "" };
	int num_[100] = { 0 };
	vector<string> line;
	int count = 0;

	for (int j = 0; j < path_name.size(); j++)
	{
		int index = 0;
		for (int i = path_name[j].size() - 1; i > path_name[j].size() - 17; i--)
		{
			if (path_name[j][i] == '\\')
				break;
			buff[index] = path_name[j][i];
			index++;
		}

		strrev(buff);

		int flag = 0;
		for (int i = 0; i < count; i++)
		{
			if (strcmp(file_name[i], buff) == 0 && line[i] == line_num[j])
			{
				flag = 1;
				num_[i]++;
				break;
			}
		}

		if (flag == 0)
		{
			strcpy(file_name[count], buff);
			line.push_back(line_num[j]);
			num_[count] = 1;
			count++;
		}
	}

	if (count > 8)
	{
		for (int i = 0; i < 8; i++)
		{
			int max_index = 0;
			for (int j = 0; j < count - 1; j++)
			{
				if (num_[j + 1] > num_[j])
					max_index = j + 1;
				else
					max_index = j;
			}

			cout << file_name[max_index] << line[max_index] << " " << num_[max_index] << endl;
			num_[max_index] = 0;
		}
	}
	else 
	{
		for (int i = 0; i < count; i++)
		{
			int max_index = 0;
			for (int j = 0; j < count - 1; j++)
			{
				if (num_[j + 1] > num_[j])
					max_index = j + 1;
				else
					max_index = j;
			}

			cout << file_name[max_index] << " " << line[max_index] << " " << num_[max_index] << endl;
			num_[max_index] = 0;
		}
	}
	return 0;
}

int main()
{
	vector<string> line_num;
	string buff, buff_;
	string buf;
	vector<string>  path_name;
	while (getline(cin, buff))
	{
		if (buff.size() == 0)
			break;
		int index = buff.find(' ');

		for (int i = 0; i < index; i++)
			buff_.push_back(buff[i]);
		for (int i = index + 1; i < buff.size(); i++)
			buf.push_back(buff[i]);

		path_name.push_back(buff_);
		//cin >> buf;
		line_num.push_back(buf);
		buf.clear();
		buff_.clear();
	}

	output_log(path_name, line_num);
	system("pause");

	return 0;
}
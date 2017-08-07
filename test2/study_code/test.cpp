#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

char result[9] = { 0 };
vector<string> result_set;

int get_result(string password, int char_size)
{
    int remain = 0;
    for (int i = 0; i < password.size(); i++)
    {
        result[char_size - password.size()] = password[i];
        string buff;
        for (int j = 0; j < password.size(); j++)
        {
            if (j != i)
                buff.push_back(password[j]);
        }
        remain = buff.size();
        if (remain == 0)
            break;
        get_result(buff, char_size);
    }
    if (remain == 0)
    {
        string buf;
        for (int i = 0; i < char_size; i++)
            buf.push_back(result[i]);
        result_set.push_back(buf);
    }

    return 0;

}

int main()
{
    string password;

    while (getline(cin, password))
    {
        get_result(password, password.size());

        vector<string> final_set;
        for (int i = 0; i < result_set.size(); i++)
            final_set.push_back(" ");

        for (int i = 0; i < result_set.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < result_set.size(); j++)
            {
                if (strcmp(result_set[i].c_str(), result_set[j].c_str()) <= 0)
                    count++;
            }
            final_set[result_set.size() - count] = result_set[i];
        }

        for (int i = 0; i < result_set.size(); i++)
            cout << final_set[i] << endl;
    }

    return 0;
}
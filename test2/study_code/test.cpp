#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int fibo[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

int get_lucky(string str) {
    // write code here

    char storage[500][100];
    int store_count = 0;
    for (int a = 0; a < 100; a++)
    {
        for (int i = 0; i < str.size() - (a - 1); i++)
        {
            int lex[26] = {0};
            string buff;
            for (int j = i; j < (a - 1); j++)
            {
                int index = int (str[j]) - 97;
                if (lex[index] == 0)
                    lex[index] = 1;
                buff.push_back(str[j]);
            }

            int count = 0;
            for (int k = 0; k < 26; k++)
            {
                if (lex[index] == 0)
                    count++;
            }

            for (int k = 0; k < 12; k++)
            {
                if (count == fibo[k])
                {
                    for (int j = 0; j < buff.size(); j++)
                        storage[store_count][j] = buff[j];
                }
            }
            store_count++;
        }
    }

    for (int i = 0; i < store_count; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            cout << storage[i][j] << endl;
        }
    }
    return 0;
}

int main()
{
    string str;
    while (cin >> str)
    {
        get_lucky(str);
    }

    // char a, b;
    // cin >> a;
    // cin >> b;

    // cout << (int)a - (int)b << endl;

    // system("PAUSE");

    return 0;
}
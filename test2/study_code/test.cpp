#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int get_answer(string str) {
    int yes_ = 0;

    for (int i = 0; i < str.size(); i++)
    {
        int k = 0;
        char backup[10];

        for (int j = 0; j < str.size(); j++) {
            if (j != i) {
                backup[k] = str[j];
                k++;
            }
        }

        int num;
        if ((str.size() - 1) % 2 == 0)
            num = (str.size() - 1) / 2;
        else
            num = (str.size() - 1) / 2 + 1;

        int count = 0;

        for (int j = 0; j < num; j++) {
            if (backup[j] == backup[(str.size() - 1) - 1 - j])
                count++;
            else
                break;
        }
        if (count == num) {
            yes_ = 1;
            break;
        }
    }
    if (yes_)
        return 1;
    else
        return 0;
}

int main()
{
    string a;
    while (cin >> a)
        if (get_answer(a))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    return 0;
}
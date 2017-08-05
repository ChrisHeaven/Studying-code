#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

string abc = "345678910JQKA2jokerJOKER";

int get_result(string poker)
{
    int index = poker.find('-');
    string poker_1, poker_2;

    poker_1 = poker.substr(0, index);
    poker_2 = poker.substr(index + 1);

    if (poker_1.size() == 11 || poker_2.size() == 11)
        cout << "joker JOKER" << endl;
    else if (poker_1.size() == 7 || poker_2.size() == 7)
    {
        if (poker_2.size() != 7)
            cout << poker_1 << endl;
        else if (poker_1.size() != 7)
            cout << poker_2 << endl;
        else if (poker_1.size() == 7 && poker_2.size() == 7)
        {
            if (abc.find(poker_1[0]) > abc.find(poker_2[0]))
                cout << poker_1 << endl;
            else
                cout << poker_2 << endl;
        }
    }
    else if (count(poker_1.begin(), poker_1.end(), ' ') == count(poker_2.begin(), poker_2.end(), ' '))
    {
        if (abc.find(poker_1[0]) > abc.find(poker_2[0]))
            cout << poker_1 << endl;
        else
            cout << poker_2 << endl;
    }
    else
        cout << "ERROR" << endl;

    return 0;
}

int main()
{
    string poker;

    while (getline(cin, poker))
    {
        get_result(poker);
    }

    return 0;
}
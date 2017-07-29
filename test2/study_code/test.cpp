#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include<iomanip>

using namespace std;

float poss[1000][1000];
float max_poss = 0;

int main()
{
    int str[5];
    while (cin >> str[0]) {
        for (int i = 1; i < 5; i++)
        {
            cin >> str[i];
        }

        for (int i = 0; i < str[0]; i++) {
            for (int j = 0; j < str[1]; j++) {
                cin >> poss[i][j];
            }
        }

        float cc_poss = 0, ss_poss = 0;
        cc_poss = poss[str[2] - 1][str[3] - 1];
        float sum = 0;

        for (int i = 0; i < str[0]; i++) {
            for (int j = 0; j < str[1]; j++) {
                sum = sum + poss[i][j];
            }
        }

        ss_poss = sum / (str[0] * str[1]);

        cc_poss = 1 - pow(1 - cc_poss, str[4]);
        ss_poss = 1 - pow(1 - ss_poss, str[4]);

        if (ss_poss > cc_poss) {
            max_poss = ss_poss;
            cout << "ss" << endl;
        }
        else if (cc_poss > ss_poss) {
            max_poss = cc_poss;
            cout << "cc" << endl;
        }
        else if (cc_poss == ss_poss) {
            max_poss = cc_poss;
            cout << "equal" << endl;
        }

        cout << fixed << setprecision(2) << max_poss << endl;
    }

    return 0;
}
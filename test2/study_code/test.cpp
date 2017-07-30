#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

class StringFormat {
public:
    string formatString(string A, int n, vector<char> arg, int m) {
        // write code here
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == '%' && A[i + 1] == 's')
            {
                A[i] = arg[count];
                A[i + 1] = -1;
                count++;
            }
        }

        int last = 0;
        if (m > count)
        {
            last = m - count;
            for (int j = n; j < n + last; j++)
            {
                A.push_back(arg[count]);
                count++;
            }
        }

        string B;
        for (int i = 0; i < n + last; i++)
        {
            if (A[i] != -1)
            {
                B.push_back(A[i]);
            }
        }
        return B;
    }
};

int main()
{
    string A = "ELK";
    int n = 3, m = 1;
    vector<char> arg = {'H'};
    StringFormat s;

    cout << s.formatString(A, n, arg, m) << endl;

    system("PAUSE");

    return 0;
}
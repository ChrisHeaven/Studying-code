#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

class Coder {
public:
    vector<string> findCoder(vector<string> A, int n) {
        // write code here
        int num[300] = { 0 }, index[300] = { 0 };
        vector<string> A_buff;

        for (int i = 0; i < n; i++)
        {
            A_buff.push_back(A[i]);
            for (int j = 0; j < A[i].size(); j++)
            {
                if (A[i][j] >= 'a' && A[i][j] <= 'z')
                    A[i][j] += ('A' - 'a');
            }

            int count = 0, pos = 0;
            for (int j = 0; j < A[i].size(); j++)
            {
                if (A[i].find("CODER", pos) == -1)
                    break;
                pos = A[i].find("CODER", pos) + 1;
                count++;
            }
            num[i] = count;
        }

        for (int i = 0; i < 300; i++)
        {
            int num_count = 0;
            for (int j = 0; j < 300; j++)
            {
                if (num[i] >= num[j])
                    num_count++;
            }
            if (index[300 - num_count] == 0)
                index[300 - num_count] = i + 1;
            else
            {
                for (int k = 300 - num_count; k < 300; k++)
                {
                    if (index[k] == 0)
                    {
                        index[k] = i + 1;
                        break;
                    }
                }
            }
        }

        int zero_count = 0;
        for (int i = 0; i < 300; i++)
        {
            if (num[i] > 0)
                zero_count++;
        }

        vector<string> B;
        for (int i = 0; i < zero_count; i++)
            B.push_back(A_buff[index[i] - 1]);

        return B;
    }
};

int main()
{
    vector<string> A = { "i am a coder", "Coder Coder", "Code" };
    int n = 3;
    Coder code;
    vector<string> B = code.findCoder(A, n);

    for (int i = 0; i < B.size(); i++)
        cout << B[i] << endl;

    system("pause");

    return 0;
}
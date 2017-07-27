#include <iostream>
#include <stdlib.h>

using namespace std;

int a[1000][1000];

class LongestDistance {
public:
    int getDis(vector<int> A, int n) {
        // write code here
        int max_dis = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (A[j] - A[i] >= max_dis)
                    max_dis = A[j] - A[i];
            }
        }
        return max_dis;
    }
};

int main()
{
    int n;
    while (cin >> n) {

        cout << getDis(n) << endl;
    }

    return 0;
}
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

// long long dp[1000][1000];

int main(void)
{
    int buff;
    vector<int> a;

    while (cin >> buff)
    {
        a.push_back(buff);
    }

    vector<int> dp(n);
    dp[0] = a[0];
    int maxVal = a[0];
    for (int i = 1; i < n; i++)
    {
                dp[i] = max(a[i], dp[i - 1] + a[i]);
                if (dp[i] > maxVal)
                        maxVal = dp[i];   
    }
        cout << maxVal << endl;

    // system("pause");
    return 0;
}
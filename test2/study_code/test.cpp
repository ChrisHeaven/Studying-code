作者：RejudgeX
链接：https://www.nowcoder.com/discuss/30697
来源：牛客网

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
long long a[N];
int k;

int partition(int l, int r) {
    while (l != r)
    {
        while (a[r] >= a[l] && r > l)
            r--;
        if (l == r)
            break;
        swap(a[r], a[l]);
        while (a[l] < a[r] && r > l)
            l++;
        if (l < r)
            swap(a[r], a[l]);

    }
    return l;
}

long long solve(int l, int r) {
    int now = partition(l, r);
    if (k < now)
        return solve(l, now - 1);
    else if (k > now)
        return solve(now + 1, r);
    else
        return a[now];
}


int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }

        k = n - 1;
        long long x1 = solve(0, n - 1);
        k = n - 2;
        long long x2 = solve(0, n - 2);
        k = n - 3;
        long long x3 = solve(0, n - 3);
        long long Ans = x1 * x2 * x3;
        if (n > 3) {
            k = 0;
            long long y1 = solve(0, n - 1);
            k = 1;
            long long y2 = solve(0, n - 2);
            Ans = max(Ans, y1 * y2 * x1);
        }
        printf("%lld\n", Ans);
    }
    return 0;
}
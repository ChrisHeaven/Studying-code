#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Apples {
public:
    int getInitial(int n) {
        // write code here
        int min_ = 0;
        for (int i = n + 1;; i++) {
            int flag = 0;
            int apple_num = i;
            for (int j = 0; j < n; j++) {
                //if (j == n - 1 && apple_num == 1) {
                //  flag = 1;
                //  break;
                //}

                if (apple_num % n != 1)
                {
                    flag = 1;
                    break;
                }

                int result = apple_num / n;
                apple_num = apple_num - 1 - result;
            }

            if (flag == 0) {
                min_ = i;
                break;
            }
        }
        return min_;
    }
};

int main()
{
    int n = 3;
    Apples s;
    cout << s.getInitial(n) << endl;

    system("PAUSE");

    return 0;
}
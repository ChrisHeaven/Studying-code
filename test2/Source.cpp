
#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	while (cin >> str) {
		int i, l = str.length(), x = 2, j = l - 1;
		for (i = 0; i < j; i++, j--) {
			if (str[i] != str[j]) {
				x--;
				if (str[i + 1] == str[j])
					i++;
				else if (str[i] == str[j - 1])
					j--;
				else
					x--;

			}

		}
		if (x > 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
}
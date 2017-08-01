#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

int original_score[30000];
int student_id[30000];
char c_[5000] = { "" };
int a_[5000] = { 0 };
int b_[5000] = { 0 };
int max_score_all[5000] = { 0 };

int get_max_score(int n, int m)
{
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		if (c_[i] == 'Q')
		{
			if (a_[i] > b_[i])
			{
				int max_score = 0;
				for (int j = b_[i]; j <= a_[i]; j++)
				{
					if (original_score[j - 1] > max_score)
						max_score = original_score[j - 1];
				}
				max_score_all[count] = max_score;
				count++;
			}
			else 
			{
				int max_score = 0;
				for (int j = a_[i]; j <= b_[i]; j++)
				{
					if (original_score[j - 1] > max_score)
						max_score = original_score[j - 1];
				}
				max_score_all[count] = max_score;
				count++;
			}
		}

		if (c_[i] == 'U')
		{
			original_score[a_[i] - 1] = b_[i];
		}
	}

	for (int i = 0; i < count; i++)
		cout << max_score_all[i] << endl;

	return 0;
}

int main()
{
	int n, m;
	while (cin >> n)
	{
		cin >> m;
		for (int i = 0; i < n; i++)
			cin >> original_score[i];

		for (int i = 0; i < m; i++)
		{
			cin >> c_[i];
			cin >> a_[i];
			cin >> b_[i];
		}

		for (int i = 0; i < n; i++)
			student_id[i] = i + 1;

		get_max_score(n, m);
	}

	return 0;
}
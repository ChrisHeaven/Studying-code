#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

long long int Triangle[1000][1000];

class Visit {
public:

	int triangle(long long int Triangle[1000][1000], int block_point[100][2])
	{
		Triangle[1][1] = 1;
		Triangle[2][1] = 1; Triangle[2][2] = 1;

		for (int i = 3; i <= 10; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				int flag = 0;
				for (int k = 0; k < 100; k++)
				{
					if (block_point[k][0] == i && block_point[k][1] == j) 
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					Triangle[i][j] = 0;
				else
					Triangle[i][j] = Triangle[i - 1][j - 1] + Triangle[i - 1][j];
			}
		}
		return 0;
	}

	int countPath(vector<vector<int> > map, int n, int m) {
		// write code here
		int man_pos[2], buss_pos[2];
		int block_point[100][2];
		int k = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1)
				{
					man_pos[0] = i;
					man_pos[1] = j;
				}
				if (map[i][j] == 2)
				{
					buss_pos[0] = i;
					buss_pos[1] = j;
				}
				if (map[i][j] == -1)
				{
					block_point[k][0] = i;
					block_point[k][1] = j;
					k++;
				}
			}
		}

		int row_diff = abs(man_pos[0] - buss_pos[0]);
		int col_diff = abs(man_pos[1] - buss_pos[1]);

		int step = row_diff + col_diff;
		int num = (step + 1 - (abs(buss_pos[0] - man_pos[0]) + 1)) + 1;

		triangle(Triangle, block_point);

		int path_num = Triangle[step + 1][num];
		//cout << path_num << endl;
		return path_num;
	}
};

int main()
{
	vector<vector<int> > map = { {0},{0},{2},{1}};
	int n = 4, m = 1;
	Visit s;
	cout << s.countPath(map, n, m) << endl;
	system("PAUSE");

	return 0;
}
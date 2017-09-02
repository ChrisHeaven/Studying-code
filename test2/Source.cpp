#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

void DFS(vector<vector<pair<string, int>>> &dir, int root, string mask) {
	string next_mask;
	for (int i = 0; i < dir[root].size(); ++i) {
		pair<string, int> node = dir[root][i];
		cout << mask;
		if (i != dir[root].size() - 1) {
			cout << "|-- ";
		}
		else {
			cout << "`-- ";
		}
		cout << node.first << endl;

		if (i == dir[root].size() - 1)
		{
			next_mask = "    " + mask;
		}
		else {
			next_mask = mask + "|   ";
		}
		DFS(dir, node.second, next_mask);
	}
}

int main(void)
{
	int n;
	while (cin >> n)
	{
		vector<vector<pair<string, int>>> dir(n + 1);
		for (int i = 0; i < n; ++i) {
			string node_s;
			int father_idx;
			pair<string, int> node;
			cin >> node_s >> father_idx;
			node.first = node_s;
			node.second = i + 1;
			dir[father_idx + 1].push_back(node);
		}

		for (int i = 0; i < dir.size(); ++i) {
			sort(dir[i].begin(), dir[i].end());
		}

		cout << dir[0][0].first << endl;
		DFS(dir, 1, "");

		// int father = -1, count = n, node_count = 0;
		// while (count > 0)
		// {
		// 	int index_[1000], flag = 0;
		// 	for (int j = 0; j < n; j++)
		// 	{
		// 		if (father_node[j] == father)
		// 		{
		// 			// cout << filename[j] << endl;
		// 			if (father == -1) {
		// 				// output.push_back(filename[j]);
		// 				count--;
		// 				index_[node_count] = j;
		// 				node_count++;
		// 				flag = 1;
		// 			}
		// 			else
		// 			{
		// 				filename[j] = "-- " + filename[j];
		// 				// output.push_back("-- " + filename[j]);
		// 				count--;
		// 				index_[node_count] = j;
		// 				node_count++;
		// 				flag = 1;
		// 			}
		// 		}
		// 	}
		// 	if (flag == 0)
		// 	{
		// 		node_count--;
		// 		father = file_index[index_[node_count - 1]];
		// 	}
		// 	else
		// 		father = file_index[index_[node_count - 1]];
		// }

		// vector<vector<string>> final(father);
		// int iter = 0;
		// string add_ = "";
		// for (int j = 0; j < father; j++)
		// {
		// 	for (int i = 0; i < filename.size(); i++)
		// 	{
		// 		if (father_node[i] == -1 && j == 0)
		// 			cout << filename[i] << endl;
		// 		else if (father_node[i] == j)
		// 		{
		// 			filename[i] = add_ + filename[i];
		// 			final[j].push_back(filename[i]);
		// 		}
		// 	}
		// 	add_ = add_ + " |";
		// 	sort(final[j].begin(), final[j].end());
		// }

		// for (int j = 0; j < father; j++)
		// {
		// 	for (int i = 0; i < final[j].size(); i++)
		// 	{
		// 		if (i == final[j].size() - 1)
		// 			cout << '`' << final[j][i] << endl;
		// 		else
		// 			cout << '|' << final[j][i] << endl;
		// 	}
		// }
	}

	// system("pause");
	return 0;
}
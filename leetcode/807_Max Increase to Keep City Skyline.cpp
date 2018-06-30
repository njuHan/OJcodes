#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
#include<functional>
using namespace std;

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		int m = grid.size(), n = grid[0].size();
		vector<int> maxRow(m, 0);
		vector<int> maxCol(n, 0);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] > maxRow[i]) maxRow[i] = grid[i][j];
				if (grid[i][j] > maxCol[j]) maxCol[j] = grid[i][j];
			}
		int ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				ans += min(maxRow[i], maxCol[j]) - grid[i][j];
		return ans;
	}
};
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
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty()) return 0;
		m = matrix.size(), n = matrix[0].size();
		maxpath = 0;
		cache = vector<vector<int>>(m, vector<int>(n, 0));
		for (int i=0; i<m; i++)
			for (int j = 0; j < n; j++)
			{
				if (cache[i][j] == 0)
					maxpath = max(maxpath, dfs(i, j, matrix));
			}
		return maxpath;
	}
private:
	vector<vector<int>> cache;
	int maxpath;
	int m, n;
	int dfs(int i, int j,  vector<vector<int>>& matrix)
	{
		if (cache[i][j] > 0) return cache[i][j];
		int& maxlen = cache[i][j] = 1;
		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k], y = j + dy[k];
			if (x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] <= matrix[i][j]) continue;
			int len = 1 + dfs(x, y, matrix);
			maxlen = max(len, maxlen);
		}
		return maxlen;
	}
};


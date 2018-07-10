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
#include<ctime>
#include<numeric>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.empty()) return{};
		m = matrix.size(), n = matrix[0].size();
		vis[0] = vector<vector<bool>>(m, vector<bool>(n, 0));
		vis[1] = vector<vector<bool>>(m, vector<bool>(n, 0));
		for (int i = 0; i < m; i++)
		{
			dfs(i, 0, INT_MIN, 0, matrix);
			dfs(i, n - 1, INT_MIN, 1, matrix);
		}
		for (int j = 0; j < n; j++)
		{
			dfs(0, j, INT_MIN, 0, matrix);
			dfs(m - 1, j, INT_MIN, 1, matrix);
		}
		return ans;
	}
private:
	int m, n;
	vector<vector<bool>> vis[2];
	vector<pair<int, int>> ans;
	// ocean:
	// pacific : 0
	// atlantic : 1
	void dfs(int x, int y, int preHt, int ocean, vector<vector<int>>& matrix)
	{
		if (x<0 || x>=m || y<0 || y>=n || matrix[x][y]<preHt || vis[ocean][x][y]) return;
		vis[ocean][x][y] = 1;
		if (vis[!ocean][x][y]) ans.emplace_back(x,y);
		for (int i = 0; i < 4; i++)
			dfs(x + dx[i], y + dy[i], matrix[x][y], ocean, matrix);
	}
};
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

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		m = grid.size();
		n = grid[0].size();
		ans = 0;
		vis = vector<vector<bool>>(m, vector<bool>(n, 0));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == 1)
				{
					dfs(i, j, grid); //there is exactly one island (i.e., one or more connected land cells)
					return ans;
				}
		return ans;
		
	}
private:
	int m, n, ans;
	vector<vector<bool>> vis;
	void dfs(int x, int y, vector<vector<int>>& grid)
	{
		if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
		{
			ans++;
			return;
		}
		if (vis[x][y]) return;
		vis[x][y] = 1;
		for (int i = 0; i < 4; i++)
			dfs(x + dx[i], y + dy[i], grid);
		
	}
};
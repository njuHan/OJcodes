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
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		m = grid.size();
		n = grid[0].size();
		int ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == 1) ans = max(ans, dfs(i, j, grid));
		return ans;
	}
private:
	int m, n;
	int dfs(int x, int y, vector<vector<int>>& grid)
	{
		if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return 0;
		grid[x][y] = 0;
		int area = 1;
		for (int i = 0; i < 4; i++)
			area += dfs(x + dx[i], y + dy[i], grid);
		return area;
	}
};
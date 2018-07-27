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
	int largestIsland(vector<vector<int>>& grid) {
		m = grid.size(); n = grid[0].size();
		color = vector<vector<int>>(m, vector<int>(n, 0));
		int c = 1, ans = 0;
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				if (grid[i][j] == 1 && color[i][j] == 0)
				{
					int cnt = 0;
					dfs(i, j, c, cnt, grid);
					color2size[c] = cnt;
					ans = max(ans, cnt);
					//cout<<c<<","<<cnt<<endl;
					c++;
				}
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				if (grid[i][j] == 0)
				{
					set<int> st;
					for (int k = 0; k < 4; k++)
						st.insert(getColor(i + dx[k], j + dy[k], grid));
					int temp = 1;
					for (int c : st)
					{
						//cout<<c<<", "<<color2size[c]<<endl;
						temp += color2size[c];
					}
					ans = max(ans, temp);
				}
		return ans;

	}
private:
	unordered_map<int, int> color2size;
	vector<vector<int>> color;
	int m, n;
	void dfs(int x, int y, int c, int& cnt, vector<vector<int>>& grid)
	{
		if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || color[x][y] == c) return;
		cnt++;
		color[x][y] = c;
		for (int i = 0; i < 4; i++)
			dfs(x + dx[i], y + dy[i], c, cnt, grid);
	}
	int getColor(int x, int y, vector<vector<int>>& grid)
	{
		if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return 0;
		return color[x][y];
	}
};
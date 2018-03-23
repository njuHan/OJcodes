#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int color = 0;
		if (grid.size() == 0 || grid[0].size() == 0) return 0;
		m = grid.size();
		n = grid[0].size();
		vis = vector<vector<bool>>(m, vector<bool>(n, false));
		g = grid;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (search(i, j))
				{
					color++;
				}
			}
		return color;
	}
	bool search(int i, int j)
	{
		if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == true || g[i][j]=='0') return false;
		vis[i][j] = true;
		search(i - 1, j);
		search(i + 1, j);
		search(i, j - 1);
		search(i, j + 1);
		return true;
	}
private:
	int m;
	int n;
	vector<vector<bool>> vis;
	vector<vector<char>> g;
};

int main()
{


	system("pause");
	return 0;
}
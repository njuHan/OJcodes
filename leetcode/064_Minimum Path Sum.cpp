#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		if (n == 0) return 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (i == 0 && j == 0) continue;
				int up = i > 0 ? dp[i - 1][j] : INT_MAX;
				int left = j > 0? dp[i][j - 1] : INT_MAX;
				dp[i][j] = min(up, left) + grid[i][j];
			}
		return dp[m - 1][n - 1];
	}
};

int main()
{
	Solution solu;
	vector<vector<int>> vec = {
		{1,3,1},
		{1,5,1},
		{4,2,1}
	};
	int ans = solu.minPathSum(vec);
	printf("%d\n", ans);
	system("pause");
	return 0;
}
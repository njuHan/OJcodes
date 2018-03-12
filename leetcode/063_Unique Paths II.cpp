#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = 1;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				int& ans = dp[i][j];
				if (i > 0)
					ans += dp[i - 1][j];
				if (j > 0)
					ans += dp[i][j - 1];
			}
		return dp[m - 1][n - 1];
	}
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0) return 0;
		int n = obstacleGrid[0].size();
		if (n <1) return 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0; //注意起始点的障碍物
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (obstacleGrid[i][j] == 1)
					continue;
				int& ans = dp[i][j];
				if (i > 0)
					ans += dp[i - 1][j];
				if (j > 0)
					ans += dp[i][j - 1];
			}
		return dp[m - 1][n - 1];
	}
};

int main()
{
	Solution solu;
	vector<vector<int>> vec = {
		{0,0,0 },
		{0,1,0},
			{0,0,0 }
	};
	int ans = solu.uniquePathsWithObstacles(vec);
	printf("%d\n", ans);
	system("pause");
	return 0;
}
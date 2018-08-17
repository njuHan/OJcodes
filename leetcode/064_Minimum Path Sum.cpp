#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

//O(n) space,  bottom to top 
class Solution3 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		int m = grid.size(), n = grid[0].size();
		vector<int> dp(n+1, INT_MAX); //多出最后一列，int_max
		dp[n - 1] = 0;
		for (int i=m-1; i>=0; i--)
			for (int j = n - 1; j >= 0; j--)
				dp[j] = min(dp[j + 1], dp[j]) + grid[i][j];
		return dp[0];
	}
};

//O(n) space, top to bottom
class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
		int m = grid.size(), n = grid[0].size();
		vector<int> dp(n, grid[0][0]);
		for (int j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j];
		for (int i = 1; i < m; i++)
		{
			dp[0] += grid[i][0]; //dp[i][0] = dp[i-1][0] + grid[i][0]
			for (int j = 1; j < n; j++)
				dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
		}
		return dp[n - 1];
    }
};

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
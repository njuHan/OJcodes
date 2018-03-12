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
};

int main()
{
	Solution solu;
	int ans = solu.uniquePaths(2,2);
	printf("%d\n", ans);
	system("pause");
	return 0;
}
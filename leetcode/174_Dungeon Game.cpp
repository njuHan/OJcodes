
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;


class Solution 
{
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		if (m < 1) return 1;
		int n = dungeon[0].size();
		if (n < 1) return 1;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		//dp[i][j] 从(i,j)出发达到终点的最少初始血量
		//逆推
		dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
		for (int i = m - 2; i >= 0; i--)
		{
			dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
		}
		for (int j = n - 2; j >= 0; j--)
		{
			dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
		}
		for (int i=m-2; i>=0; i--)
			for (int j = n - 2; j >= 0; j--)
			{
				dp[i][j] = min(max(dp[i + 1][j] - dungeon[i][j], 1), max(dp[i][j + 1] - dungeon[i][j], 1));
			}
		return dp[0][0];
	}
};

int main()
{
	Solution solu;
	// [[-2,-3,3],[-5,-10,1],[10,30,-5]]
	return 0;
}
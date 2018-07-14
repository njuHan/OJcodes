#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
#include<functional>
#include<algorithm>
using namespace std;


unsigned int dp[2][50][50]; //注意int溢出
const int mod = 1e9 + 7;
class Solution {
public:
	//dp[k][x][y]: 从(x,y)出发，最多移动n步，到达边界外的路径数
	// dp[k][x][y] = dp[k-1][x-1][y] + dp[k-1][x+1][y] + dp[k-1][x][y-1] + dp[k-1][x][y+1]
	// if (x,y)在边界外， dp[k][x][y] = 1;
	int findPaths(int m, int n, int N, int i, int j) {
		memset(dp, 0, sizeof(dp));
		for (int k = 1; k <= N; k++)
		{
			int pre = (k - 1) % 2, cur = k % 2;
			for (int x = 0; x < m; x++)
				for (int y = 0; y < n; y++)
				{
					dp[cur][x][y] = (x>0 ? dp[pre][x - 1][y] : 1)
						+ (y>0 ? dp[pre][x][y - 1] : 1)
						+ (x < m - 1 ? dp[pre][x + 1][y] : 1)
						+ (y < n - 1 ? dp[pre][x][y + 1] : 1);
					dp[cur][x][y] %= mod;
				}
		}
		return dp[N % 2][i][j];
	}
};
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
#include<sstream>
#include<functional>
using namespace std;


class Solution {
public:
	int cherryPickup(vector<vector<int>>& grid) {
		int n = grid.size();
		if (n == 0) return 0;
		int maxStep = n - 1 + n - 1; // x + y
		//3维dp，2维存储，从后往前
		vector<vector<int>> dp(n, vector<int>(n, -1));
		dp[0][0] = grid[0][0];
		for (int step = 1; step <= maxStep; step++) 
		{
			for (int i = min(step, n-1); i >= 0 ; i--)
			{
				if (step - i >= n) continue;
				for (int j = min(step, n-1); j >= i; j--) // assume j>=i
				{
					if (step - j >= n) continue;
					if (grid[i][step - i] == -1 || grid[j][step - j] == -1)
					{
						dp[i][j] = -1; //由于复用了上一轮的dp, 需要把本轮不可到达的dp赋值-1
						continue;
					}
					//上一轮的step-1的dp
					int cherry = dp[i][j]; 
					if (i > 0) cherry = max(cherry, dp[i - 1][j]);
					if (j > 0) cherry = max(cherry, dp[i][j - 1]);
					if (i > 0 && j > 0) cherry = max(cherry, dp[i - 1][j - 1]);
					if (cherry < 0) continue; //无法到达
					dp[i][j] = cherry +  grid[i][step - i] + (i == j ? 0 : grid[j][step - j]);
				}
			}
		}
		return max(dp[n - 1][n - 1], 0);
	}
};
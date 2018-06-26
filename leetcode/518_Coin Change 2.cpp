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
using namespace std;


class Solution {
public:
	int change(int amount, vector<int>& coins) {
		if (amount == 0) return 1;
		if (coins.empty()) return 0;
		sort(coins.begin(), coins.end());
		int num = coins.size();
		vector<vector<int>> dp(amount + 1, vector<int>(num, 0));
		for (int i = 0; i < num; i++) if (coins[i]<=amount) dp[coins[i]][i] = 1;
		for (int i = 1; i <= amount; i++)
		{
			for (int j = 0; j<num; j++)
			{
				
				if (i - coins[j] >= 0)
					for (int k = 0; k <= j; k++)
						if (dp[i - coins[j]][k]) dp[i][j] += dp[i - coins[j]][k];
			}
		}
		int ans = 0;
		for (int i = 0; i < num; i++) ans += dp[amount][i];
		return ans;
	}
	
	int change1(int amount, vector<int>& coins)
	{
		if (amount == 0) return 1;
		if (coins.empty()) return 0;
		int len = coins.size();
		//dp[i][j], ÷ª”√ idx<=iµƒ”≤±“
		vector<vector<int>> dp(len, vector<int>(amount + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j <= amount; j++)
			{
				dp[i][j] += (i > 0 ? dp[i - 1][j] : 0) + (j >= coins[i] ? dp[i][j - coins[i]] : 0);
			}
		}
		return dp[len - 1][amount];
	}
	int change2(int amount, vector<int>& coins)
	{
		if (amount == 0) return 1;
		if (coins.empty()) return 0;
		int len = coins.size();
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < len; i++)
		{
			for (int j = coins[i]; j <= amount; j++)
			{
				dp[j] += dp[j - coins[i]];
			}
		}
		return dp[amount];
	}
};
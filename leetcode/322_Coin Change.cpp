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

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX);
		// dp[i] 兑换i元需要的最少硬币
		dp[0] = 0;
		for (int i = 1; i <= amount; i++)
		{
			for (auto e : coins)
			{
				if (i - e >= 0 && dp[i-e]!=INT_MAX)
					dp[i] = min(dp[i], dp[i - e] + 1);
			}
		}
		if (dp[amount] == INT_MAX) return -1;
		else return dp[amount];
	}
};

int main()
{


	system("pause");
	return 0;
}
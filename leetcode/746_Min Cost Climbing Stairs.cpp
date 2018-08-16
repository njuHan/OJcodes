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

class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), f1 = cost[0], f2 = cost[1], ans;
        for (int i=2; i<n; i++)
        {
            ans = min(f1, f2) + cost[i];
            f1 = f2;
            f2 = ans;
        }
        return min(f1, f2);
    }
};

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int len = cost.size();
		if (len < 1) return 0;
		if (len == 1) return cost[0];
		if (len == 2) return min(cost[0], cost[1]);
		vector<int> dp(len + 1, 0);
		dp[0] = cost[0]; dp[1] = cost[1];
		for (int i = 2; i <= len; i++)
			dp[i] = min(dp[i - 1], dp[i - 2]) + (i < len ? cost[i] : 0);
		return dp[len];
		
	}
};
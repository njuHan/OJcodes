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
	bool canCross(vector<int>& stones) {
		return dfs(stones, 0, 0);
	}
private:
	unordered_map<long long, bool> dp;
	bool dfs(vector<int>& stones, int idx, int step)
	{
		long long key = idx;
		key = key << 32;
		key |= step;
		if (dp.count(key)) return dp[key];
		for (int i = idx + 1; i < stones.size(); i++)
		{
			int gap = stones[i] - stones[idx];
			if (gap < step - 1) continue;
			if (gap > step + 1) return dp[key] = false;
			if (dfs(stones, i, gap)) return dp[key] = true;
		}
		return dp[key] = (idx == stones.size() - 1);
	}
};
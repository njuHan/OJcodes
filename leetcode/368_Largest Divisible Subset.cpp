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
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.empty()) return{};
		sort(nums.begin(), nums.end());
		vector<set<int>> dp;
		for (int num : nums)
		{
			int len = 0, idx = -1;
			for (int i = 0; i<dp.size(); i++)
			{
				if (!dp[i].empty() && num% *dp[i].rbegin() == 0 && len < dp[i].size())
				{
					len = dp[i].size();
					idx = i;
				}
			}
			if (idx!=-1)
			{
				set<int> newst(dp[idx]);
				newst.insert(num);
				dp.push_back(newst);
			}
			else
				dp.push_back({ num });
		}
		int maxlen = dp[0].size(), idx = 0;
		for (int i=1; i<dp.size(); i++)
			if (dp[i].size() > maxlen)
			{
				maxlen = dp[i].size();
				idx = i;
			}
		return vector<int>(dp[idx].begin(), dp[idx].end());
	}
	// dp
	vector<int> largestDivisibleSubset2(vector<int>& nums) 
	{
		if (nums.empty()) return{};
		sort(nums.begin(), nums.end());
		vector<int> dp(nums.size(), 0);
		vector<int> next(nums.size(), 0);
		dp[0] = 1;
		int maxLen = 1, idx = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			int maxpre = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				if (nums[i] % nums[j] == 0 && dp[j] > maxpre)
				{
					maxpre = dp[j];
					next[i] = j;
				}
			}
			dp[i] = maxpre + 1;
			if (dp[i] > maxLen)
			{
				maxLen = dp[i];
				idx = i;
			}
		}
		vector<int> ans;
		for (int i = 0; i < maxLen; i++)
		{
			ans.emplace_back(nums[idx]);
			idx = next[idx];
		}
		return vector<int>(ans.rbegin(), ans.rend());
	}
};

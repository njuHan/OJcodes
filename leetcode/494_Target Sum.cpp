#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<bitset>
using namespace std;

class Solution {
public:
	int findTargetSumWays2(vector<int>& nums, int S) {
		cnt = 0;
		target = S;
		this->nums = nums;
		search(0, 0);
		return cnt;
	}
	// https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C++-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
	// subset sum
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for (int e : nums) sum += e;
		if (sum < S || (sum + S) & 1) return 0;
		int target = (sum + S) >> 1; //sum subset 
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++)
			for (int j = target; j >= 0; j--) //Ë³Ðò²»ÄÜ¸Ä
			{
				if (j - nums[i] >= 0)
					dp[j] += dp[j - nums[i]];
			}
		return dp[target];
	}
private:
	int cnt;
	int target;
	vector<int> nums;
	void search(int cur, int sum)
	{
		if (cur == nums.size())
		{
			cnt += (sum == target);
			return;
		}
		search(cur + 1, sum - nums[cur]);
		search(cur + 1, sum + nums[cur]);
		return;
	}
};
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
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0); dp[0] = 1;
        for (int i=1; i<=target; i++)
            for (int num : nums)
                dp[i] += (i>=num)*dp[i-num];
        return dp[target];
    }
};

// https://leetcode.com/problems/combination-sum-iv/discuss/85097/What-if-negative-numbers-are-allowed-in-the-given-array
// https://leetcode.com/problems/combination-sum-iv/discuss/85120/C++-template-for-ALL-Combination-Problem-Set
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; i++)
		{
			for (int num : nums)
				if (i >= num) dp[i] += dp[i - num];
		}
		return dp[target];
	}
};
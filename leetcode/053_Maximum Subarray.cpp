#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		size_t len = nums.size();
		if (len < 1) return 0;
		vector<int> dp(len, INT_MIN);
		dp[0] = nums[0];
		int maxsum = dp[0];
		for (size_t i = 1; i < len; i++)
		{
			dp[i] = nums[i] + max(0, dp[i - 1]);
			maxsum = max(maxsum, dp[i]);
		}
		return maxsum;
	}
};
int main()
{
	Solution solu;
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	int ans = solu.maxSubArray(nums);
	cout << ans;
	system("pause");
	return 0;
}
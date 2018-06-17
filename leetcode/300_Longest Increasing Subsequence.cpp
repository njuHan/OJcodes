
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
	//O(n*n)
	int lengthOfLIS2(vector<int>& nums) {
		int len = nums.size();
		if (len < 1) return 0;
		vector<int> dp(len, 0);
		dp[0] = 1;
		int ans = 1;
		for (int i = 1; i < len; i++)
		{
			dp[i] = 1; 
			for (int j = i - 1; j >= 0; j--)
			{
				if (nums[j] < nums[i]) dp[i] = max(dp[j]+1, dp[i]);
			}
			ans = max(dp[i], ans);
		}
		return ans;
	}
	
	// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
	//O(nlog(n))
	int lengthOfLIS(vector<int>& nums)
	{
		int len = nums.size();
		if (len < 1) return 0;
		vector<int> arr;
		arr.emplace_back(nums[0]);
		for (int i = 1; i < len; i++)
		{
			if (nums[i] > *(arr.end()-1)) 
				arr.emplace_back(nums[i]);
			else
			{
				vector<int>::iterator it = lower_bound(arr.begin(), arr.end(), nums[i]); // *it >= nums[i]
				*it = nums[i];
			}
		}
		return arr.size();
	}
};

int main()
{
	Solution solu;
	vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
	int ans = solu.lengthOfLIS(nums);
	system("pause");
	return 0;
}
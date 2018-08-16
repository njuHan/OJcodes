#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    int rob(vector<int>& nums) {
        int take = 0, nontake = 0;
        for (int num : nums)
        {
            int temp = take;
            take = nontake + num;
            nontake = max(temp, nontake);
        }
        return max(take, nontake);
    }
};

class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len < 1) return 0;
		if (len == 1) return nums[0];
		vector<int> dp(len, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < len; i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return dp[len - 1];
	}
};

int main()
{


	system("pause");
	return 0;
}
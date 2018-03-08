#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums)
	{
		vector<int> index;
		int len = nums.size();
		for (int i = 0; i < len; i++)
			index.push_back(i + nums[i]);
		int jump = 0;
		int max_index = index[0];
		while (jump <= max_index && jump < len)
		{
			if (max_index < index[jump])
				max_index = index[jump];
			jump++;
		}
		if (jump == len)
			return true;
		return false;
	}
	
	// O(n*n) ³¬Ê±£¡£¡£¡
	bool canJump2(vector<int>& nums) {
		int len = nums.size();
		vector<bool> dp(len, false);
		dp[len - 1] = true;
		for (int i = len - 2; i >= 0; i--)
		{
			int step = min(nums[i], len - i);
			while (step > 0)
			{
				int next = i + step;
				if (next < len)
					dp[i] = dp[i] || dp[next];
				step--;
				if (dp[i]) break;
			}
			
		}
		return dp[0];
	}
};

int main()
{
	vector<int> v = { 2,3,1,1,4 };
	Solution solu; 
	double  ans = solu.canJump(v);
	cout << ans;
	system("pause");
	return 0;
}
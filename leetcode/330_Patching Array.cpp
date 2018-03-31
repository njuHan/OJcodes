
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
	//1. 如果 nums[0,...,i-1], 可以构成[0,miss)的数，
	//那么加上 nums[i]， 可以构成[0,miss+nums[i])的数
	// 2. 如果 nums[i]<=miss, 那么nums[i]加上nums[0,...,i-1]中的一些数，肯定可以构造和为 miss的数，此时miss更新为 miss+nums[i], i++
	// 3. 如果 nums[i]>miss ,无法构造miss, 贪心添加miss这个数， 更新miss = miss + miss
	int minPatches(vector<int>& nums, int n) 
	{
		/*
		case :
		[1,2,31,33]
		2147483647
		使用long long 防止溢出
		*/
		long long  miss = 1, ans = 0, i = 0;
		while (miss <= n)
		{
			if (i<nums.size() && nums[i] <= miss)
			{
				miss += nums[i++];
			}
			else
			{
				miss += miss;
				ans++;
			}
		}
		return ans;
	}
};

int main()
{
	Solution solu;

	return 0;
}
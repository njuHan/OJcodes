#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size(), i;
		for (i = 0; i < n; i++)
		{
			// 1 2 ... n
			//重复元素不交换
			while (nums[i]-1 != i  && nums[i] > 0 && nums[i] <= n && nums[i]!=nums[nums[i]-1])
			{
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		
		for (i = 0; i < n; i++)
		{
			if (nums[i] - 1 != i)
				return i + 1;
		}
		return i + 1;
	}
};
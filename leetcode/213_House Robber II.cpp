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
using namespace std;


class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return n==0 ? 0 : nums[0];
		return max(rob1(nums, 0, n - 1), rob1(nums, 1, n));
	}
	int rob1(vector<int>& nums, int x, int y) {
		if (nums.size() == 0) return 0;
		int take = 0, nottake = 0;
		for (int i = x; i < y; i++)
		{
			int temp = take;
			take = nottake + nums[i];
			nottake = max(temp, nottake);
		}
		return max(take, nottake);
	}
};

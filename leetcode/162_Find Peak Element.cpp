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
	int findPeakElement(vector<int>& nums) {
		bool flag = 1;
		int n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			if (i == n && flag) return i - 1;
			if (flag && nums[i] < nums[i - 1]) return i - 1;
			if (nums[i] < nums[i - 1]) flag = 0;
		}
	}
};
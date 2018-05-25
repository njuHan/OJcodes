#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<map>
#include<set>
#include<algorithm> 
#include<string>
#include<unordered_set>
using namespace std;

// https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C++-solutions
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;
		if (k > 0)
		{
			int i = 0, j = n - k - 1;
			while (i < j) swap(nums[i++], nums[j--]);
			i = n - k, j = n - 1;
			while (i < j) swap(nums[i++], nums[j--]);
			i = 0, j = n - 1;
			while (i < j) swap(nums[i++], nums[j--]);
		}
	}
};

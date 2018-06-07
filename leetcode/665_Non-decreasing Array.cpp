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
	bool checkPossibility(vector<int>& nums) {
		int n = nums.size();
		for (int i = 1; i < n; i++)
		{
			if (nums[i] < nums[i - 1])
			{
				int temp = nums[i - 1];
				nums[i - 1] = nums[i];
				if (is_sorted(nums.begin(), nums.end())) return true;
				nums[i - 1] = nums[i] = temp;
				return is_sorted(nums.begin(), nums.end());
			}
		}
		return true;
	}
};
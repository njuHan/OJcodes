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
#include<functional>
using namespace std;


class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int len = nums.size();
		if (len < 2) return false;
		unordered_map<int, int> modIdx; //(num%k , idx)
		modIdx[0] = -1;
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			sum += nums[i];
			sum = k == 0 ? sum : sum%k;
			if (modIdx.count(sum))
			{
				if (i - modIdx[sum] > 1) return true;
			}
			else modIdx[sum] = i;
		}
		return false;
	}
};
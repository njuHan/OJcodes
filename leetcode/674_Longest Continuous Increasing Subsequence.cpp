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
#include<ctime>
using namespace std;



class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int len = nums.size();
		if (len < 1) return 0;
		int pre = 1, maxlen = 1;
		for (int i = 1; i < len; i++)
		{
			if (nums[i - 1] < nums[i])
			{
				pre = pre + 1;
				maxlen = max(maxlen, pre);
			}
			else pre = 1;
		}
		return maxlen;
	}
};
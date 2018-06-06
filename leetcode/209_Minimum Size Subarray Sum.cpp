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
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		int lo = 0, hi = 0, sum = nums[0];
		int minLen = n + 1;
		while (lo<n)
		{
			if (sum < s)
			{
				if (++hi >= n) break;
				sum += nums[hi];
			}
			else
			{
				minLen = min(minLen, hi - lo + 1);
				sum -= nums[lo++];
			}
		}
		return minLen == n + 1 ? 0 : minLen;
	}
};
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
	int splitArray(vector<int>& nums, int m) {
		long long left = 0, right = 0;
		for (int num : nums)
		{
			left = max((int)left, num);
			right += num;
		}
		while (left < right)
		{
			long long mid = left + (right - left) / 2;
			if (canSplit(nums, m - 1, mid)) right = mid;
			else left = mid + 1;
		}
		return left;
	}
private:
	bool canSplit(const vector<int>& nums, int cuts, long long maxSum)
	{
		long long acc = 0;
		for (int num : nums)
		{
			if (acc + num <= maxSum) acc += num;
			else
			{
				acc = num;
				if (--cuts < 0) return false;
			}
		}
		return true;
	}
};
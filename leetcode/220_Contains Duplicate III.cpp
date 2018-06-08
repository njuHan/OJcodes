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
	//nlog(n),can't pass the last test case
	bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
		if (nums.size() < 2 || k < 1 || t < 0) return false;
		set<long long> preNums;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k) preNums.erase(nums[i - k - 1]);
			long long minNum = (long long)nums[i] - t;
			auto p = lower_bound(preNums.begin(), preNums.end(), minNum);
			if (p != preNums.end() && *p - nums[i] <= t) return true;
			preNums.insert(nums[i]);
		}
		return false;
	}

	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		if (nums.size() < 2 || k < 1 || t < 0) return false;
		unordered_map<long long, long long> bucket;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k) bucket.erase(((long long)nums[i - k - 1]  - INT_MIN) / ((long long)t + 1));
			long long num = (long long)nums[i] - INT_MIN;
			long long id = num / ((long long)t + 1);
			if (bucket.count(id)
				|| (bucket.count(id - 1) && nums[i] - bucket[id - 1] <= t)
				|| (bucket.count(id + 1) && bucket[id + 1] - nums[i] <= t))
				return true;
			bucket[id] = nums[i];
		}
		return false;
	}
};


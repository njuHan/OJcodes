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
using namespace std;

// https://leetcode.com/problems/increasing-triplet-subsequence/discuss/78997/Generalization-in-Python

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int a1 = INT_MAX, a2 = INT_MAX;
		for (int num : nums)
		{
			if (num <= a1) a1 = num;
			else if (num <= a2) a2 = num;
			else return true;
		}
		return false;
	}
	bool increasingK(vector<int>& nums) {
		int k = 3;
		vector<int> inc(k - 1, INT_MAX);
		for (int num : nums)
		{
			auto p = lower_bound(inc.begin(), inc.end(), num);
			if (p == inc.end()) return true;
			*p = num;
		}
		return false;
	}
	//dfs to find the increasing sequences
	//Time Limit Exceeded
	bool increasingTripletdfs(vector<int>& nums)
	{
		vector<int> vec = {};
		return dfs(0, vec, nums);
	}
private:
	bool dfs(int cur, vector<int>& seq, vector<int>& nums)
	{
		if (seq.size() == 3) return true;
		for (int i = cur; i < nums.size(); i++)
		{
			if (seq.empty() || seq.back() < nums[i])
			{
				seq.push_back(nums[i]);
				if (dfs(i + 1, seq, nums)) return true;
				seq.pop_back();
			}
		}
		return false;
	}
};

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
#include<numeric>
using namespace std;

class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> seq;
		search(0, seq, nums);
		return vector<vector<int>>(ans.begin(), ans.end());
	}
private:
	unordered_set<vector<int>> ans;
	void search(int cur, vector<int>& seq, vector<int>& nums)
	{
		if (seq.size() > 1) ans.insert(seq);
		for (int i = cur; i < nums.size(); i++)
		{
			if (seq.empty() || seq.back() <= nums[i])
			{
				seq.emplace_back(nums[i]);
				search(i + 1, seq, nums);
				seq.pop_back();
			}
		}
	}
};

// unordered_set
class Solution2 {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> seq;
		search(0, seq, nums);
		return ans;
	}
private:
	vector<vector<int>> ans;
	void search(int cur, vector<int>&seq, vector<int>& nums)
	{
		if (seq.size() > 1) ans.emplace_back(seq);
		unordered_set<int> used;
		for (int i = cur; i < nums.size(); i++)
		{
			if ((seq.empty() || seq.back() <= nums[i]) && !used.count(nums[i]))
			{
				used.insert(nums[i]);
				seq.emplace_back(nums[i]);
				search(i + 1, seq, nums);
				seq.pop_back();
			}
		}
	}
};
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
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		this->nums = nums;
		sort(this->nums.begin(), this->nums.end());
		n = nums.size();
		for (int e : nums) numCnt[e]++;
		vector<int> a;
		unordered_map<int, int> cnt;
		dfs(0, a, cnt);
		return ans;
	}
private:
	unordered_map<int, int> numCnt;
	vector<vector<int>> ans;
	vector<int> nums;
	int n;
	void dfs(int cur, vector<int>& a, unordered_map<int, int>& cnt)
	{

		if (cur == n)
		{
			ans.push_back(a);
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || nums[i] != nums[i - 1])
			{
				if (cnt[nums[i]] < numCnt[nums[i]])
				{
					cnt[nums[i]]++;
					a.push_back(nums[i]);
					dfs(cur + 1, a, cnt);
					cnt[nums[i]]--;
					a.pop_back();
				}
			}
		}
	}
};
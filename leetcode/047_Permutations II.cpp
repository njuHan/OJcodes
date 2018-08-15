#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//使用swap, 每次从剩余元素中选取一个添加到排列
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		pick(0, nums);
		return ans;
	}
private:
	vector<vector<int>> ans;
    // 这里nums 不能引用，因为cur+1之后的操作会打乱cur时的nums的顺序，导致重复访问
	void pick(int cur, vector<int> nums)
	{
        
		if (cur == nums.size()) { ans.emplace_back(nums); return; }
		for (int i = cur; i < nums.size(); i++)
		{
			if (i > cur && nums[i] == nums[cur]) continue;
			swap(nums[i], nums[cur]);
			pick(cur + 1, nums);
		}
	}
};


// backtracking
class Solution2 {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		int n = nums.size();
        sort(nums.begin(), nums.end());
		vis = vector<bool>(n, 0);
		vector<int> vec = vector<int>(n, 0);
		search(0, vec, nums);
		return ans;
	}
private:
	vector<bool> vis;
	vector<vector<int>> ans;
	void search(int cur, vector<int>& arr, vector<int>& nums)
	{
		if (cur == nums.size()) { ans.emplace_back(arr); return; }
		for (int i = 0; i < nums.size(); i++)
		{
			//  这里避免相同元素重复访问，首先得排序使得相同元素相邻
			if (vis[i] || i != 0 && nums[i - 1] == nums[i] && vis[i - 1] == 0) continue;
			vis[i] = 1;
			arr[cur] = nums[i];
			search(cur+1, arr, nums);
			vis[i] = 0;
		}
	}
};


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
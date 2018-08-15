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

class Solution2 {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> comb = {};
		search(1, n, k, comb);
		return ans;
	}
private:
	vector<vector<int>> ans;
	void search(int cur, int n, int k, vector<int>& comb)
	{	
		if (k==0)
		{
			ans.emplace_back(comb);
			return;
		}
		for (int i = cur; i <= n+1-k; i++)
		{
			comb.emplace_back(i);
			search(i + 1, n, k-1, comb);
			comb.pop_back();
		}
	}
};


class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (k <= 0) return{ {} };
		if (k >= n) 
		{
			vector<int> nums;
			for (int i = 1; i <= n; i++) nums.emplace_back(i);
			return{ nums };
		}
		vector<int> cur(k);
		dfs(cur, 1, 0, k, n);
		return ans;
	}
private:
	
	vector<vector<int>> ans;
	void dfs(vector<int>& cur, int num, int idx, int k, int n)
	{
		if (k == 0)
		{
			ans.emplace_back(cur);
			return;
		}
		if (n - idx < k) return;
		for (int i = num; i <= n; i++)
		{
			cur[idx] = i;
			dfs(cur, i + 1,idx+1, k - 1, n);
		}
	}
};
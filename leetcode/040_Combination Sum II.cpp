#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Solution2 {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> arr = {};
		search(0, arr, target, candidates);
		return ans;
	}
private:
	vector<vector<int>> ans;
	void search(int cur, vector<int>& arr, int target, vector<int>& candidates)
	{
		if (target == 0) { ans.emplace_back(arr); return; }
		for (int i = cur; i < candidates.size() && candidates[i] <= target; i++)
		{
            //防止在同一个cur上取重复元素
            if (i!=cur && candidates[i-1] == candidates[i]) continue;
			arr.emplace_back(candidates[i]);
			search(i+1, arr, target - candidates[i], candidates);
			arr.pop_back();
		}
	}
};

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
	{
		sort(candidates.begin(), candidates.end());
		this->tag = target;
		vector<vector<int>> ans;
		vector<int> vec;
		int curSum = 0;
		int start = 0;
		getAns(ans, vec, candidates, start, curSum);
		return ans;
	}
	void getAns(vector<vector<int>>& ans, vector<int> vec, vector<int>& candidates, int start, int curSum)
	{
		for (int i = start; i < candidates.size(); i++)
		{
			if (i == start || candidates[i] != candidates[i - 1])
			{
				vec.push_back(candidates[i]);
				if (curSum + candidates[i] == tag)
				{
					ans.push_back(vec);
				}
				else if (curSum + candidates[i] < tag)
					getAns(ans, vec, candidates, i + 1, curSum + candidates[i]);
				vec.pop_back();
			}

		}
	}
private:
	int tag;
};

int main()
{
	Solution solu;
	vector<int> vec = { 10, 1, 2, 7, 6, 1, 5 };
	vector<vector<int>> ans = solu.combinationSum2(vec, 8);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			printf("%d,", ans[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
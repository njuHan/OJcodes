#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;


class Solution2 {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
			arr.emplace_back(candidates[i]);
			search(i, arr, target - candidates[i], candidates);
			arr.pop_back();
		}
	}
};

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		vector<int> curVec;
		addnum(candidates, target, curVec, 0, 0);
		return ans;
	}
	void addnum(vector<int>& candidates, int target, vector<int>& curVec, int sum, int start)
	{
		for (int i = start; i < candidates.size(); i++)
		{
			if (sum + candidates[i] < target)
			{
				curVec.push_back(candidates[i]);
				addnum(candidates, target, curVec, sum + candidates[i], i);
				curVec.pop_back();
			}
			if (sum + candidates[i] == target)
			{
				curVec.push_back(candidates[i]);
				ans.push_back(curVec);
				curVec.pop_back();
			}
		}
	}
private:
	vector<vector<int>> ans;
};
int main()
{
	Solution solu;
	vector<int > vec = { 2,3,6,7 };
	int t = 1;
	vector<vector<int>> ans = solu.combinationSum(vec, 7);

	system("pause");
	return 0;
}
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

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
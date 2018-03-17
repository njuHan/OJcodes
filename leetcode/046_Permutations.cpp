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
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> vec;
		search(nums, 0, vec);
		return ans;
	}
	void search(vector<int>& nums, int cur, vector<int>& curVec)
	{
		if (cur == nums.size())
		{
			ans.push_back(curVec);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			vector<int>::iterator it = find(curVec.begin(), curVec.end(), nums[i]);
			if (it == curVec.end())
			{
				curVec.push_back(nums[i]);
				search(nums, cur + 1, curVec);
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
	vector<int > vec = { 1,2,3 };
	vector<vector<int>> ans = solu.permute(vec);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			printf("%d, ", ans[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
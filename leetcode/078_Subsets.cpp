#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
	
	vector<vector<int>> subsets(vector<int>& nums) {
		int len = nums.size();
		ans.push_back({});
		if (len <= 0) return ans;
		for (int i = 0; i < len; i++)
		{
			getsub(nums, i);
		}
		return ans;

	}
	void getsub(vector<int>& nums, int i)
	{
		int len = ans.size();
		for (int p = 0; p < len ; p++)
		{
			vector<int> temp = ans[p];
			temp.push_back(nums[i]);
			ans.push_back(temp);
		}
	}
private:
	vector<vector<int>> ans;
};

int main()
{
	Solution solu;
	vector<int> vec = { 1,2,3 };
	vector<vector<int>> ans = solu.subsets(vec);
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
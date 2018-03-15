#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

	
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > ans;
		vector<int> vec;
		subsets(ans, nums, vec, 0);
		return ans;
	}

	//现在的讨论的子集是vec，vec还能添加的元素起始下标为 begin
	//begin 用于定序，排除重复
	//这里vec不用引用也行，只是为了加速
	void subsets(vector<vector<int>>& ans, vector<int> &nums, vector<int>& vec, int begin) {
		ans.push_back(vec);
		for (int i = begin; i != nums.size(); ++i)
		{
			if (i == begin || nums[i] != nums[i - 1])
			{
				vec.push_back(nums[i]);
				subsets(ans, nums, vec, i + 1);
				vec.pop_back();
			}
		}
	}

	//理解后自己写的：
	vector<vector<int>> subsetsWithDup2(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > ans;
		vector<int> vec;
		ans.push_back(vec);
		getsub(ans, vec, nums, 0);
		return ans;
	}


	
	void getsub(vector<vector<int>>& ans, vector<int>& vec, vector<int>& nums, int cur)
	{
		for (int i = cur; i != nums.size(); i++)
		{
			if (i == cur || nums[i] != nums[i - 1])
			{
				vec.push_back(nums[i]);
				ans.push_back(vec);
				getsub(ans, vec, nums, i + 1);
				vec.pop_back();
			}
		}
	}
};

int main()
{
	Solution solu;
	vector<int> vec = { 2,1,2,2 };
	vector<vector<int>> ans = solu.subsetsWithDup2(vec);
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
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		int len = nums.size();
		if (len <= 0) return ans;
		for (int i = 0; i < 1 << len; i++)
		{
			vector<int> temp;
			for (int j = 0; j < len; j++)
			{
				if (i&(1 << j)) temp.push_back(nums[j]);
			}
			ans.push_back(temp);
		}
		return ans;
	}
	

	
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
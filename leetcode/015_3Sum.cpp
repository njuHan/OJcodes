#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is :
[
	[-1, 0, 1],
	[-1, -1, 2]
]
*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		//注意这里的 size()-1, 可能nums为空。利用短路判断
		if (nums.size()<3 ||nums[nums.size() - 1] < 0 ) return ans;
		for (int i = 0; i < nums.size()-2; i++) //注意 i 的范围
		{
			if (nums[i] > 0) break;
			if (i == 0 || nums[i - 1] != nums[i]) //跳过重复元素
			{
				int low = i + 1, high = nums.size() - 1;
				while (low<high)
				{
					//跳到下一对不一样的 (low, high)
					if (nums[i] + nums[low] + nums[high] == 0)
					{ 
						ans.push_back({ nums[i], nums[low], nums[high] });
						while (low < high && nums[low + 1] == nums[low])
							low++;
						while (low < high && nums[high-1]==nums[high])
							high++;
						low++;
						high--;
					}
					else if (nums[i] + nums[low] + nums[high] < 0)
						low++;
					else
						high--;
					
				}
				
			}
		}
		return ans;

	}
};

int main()
{
	vector<int> s;//= { -1, 0, 1, 2, -1, -4 };
	Solution solu;
	vector<vector<int>> ans = solu.threeSum(s);
	system("pause");
	return 0;
}
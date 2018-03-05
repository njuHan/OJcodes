
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		vector<vector<int>> ans;
		// 不能添加 || nums[0]>target，因为有负数
		if (len<4  || nums[len - 1] * len < target) return ans;
		for (int i = 0; i < len - 3; i++)
		{
			if (i != 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < len - 2; j++)
			{
				if (j != i + 1 && nums[j] == nums[j - 1]) continue;
				int low = j + 1, high = len - 1;
				while (low<high)
				{
					if (nums[i] + nums[j] + nums[low] + nums[high] == target)
					{
						ans.push_back({ nums[i], nums[j], nums[low], nums[high] });
						while (low < high && nums[low + 1] == nums[low])
							low++;
						while (low < high && nums[high - 1] == nums[high])
							high--;
						low++;
						high--;
					}
					else if (nums[i] + nums[j] + nums[low] + nums[high] > target)
						high--;
					else
						low++;
				}
			}
		}

		return ans;
	}
};

int main()
{
	vector<int> s = { 1,-2,-5,-4,-3,3,3,5 };
	Solution solu;
	vector<vector<int>> ans = solu.fourSum(s, -11);
	
	system("pause");
	return 0;
}

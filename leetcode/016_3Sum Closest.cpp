#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int ans = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size() - 2; i++)
		{
			int low = i + 1, high = nums.size() - 1;
			while (low < high)
			{
				int result = nums[i] + nums[low] + nums[high];
				if (abs(target - ans)>abs(target - result))
					ans = result;
				if (result == target)
					return target;
				if (result > target)
					high--;
				else
					low++;
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> s = { -1 ,2 ,1 ,- 4 };
	Solution solu;
	int ans = solu.threeSumClosest(s, 1);
	printf("%d\n", ans);
	system("pause");
	return 0;
}

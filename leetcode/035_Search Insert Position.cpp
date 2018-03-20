#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int len = nums.size();
		if (len < 1) return 0;
		int low = 0, high = len - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (low == high)
			{
				if (nums[low] == target) return low;
				else if (nums[low]>target) return low;
				else return low + 1;
			}
			if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid;
		}
	}
}; int main()
{
	Solution solu;
	vector<int> vec = { 1,3,5,6 };
	int ans = solu.searchInsert(vec, 0);
	cout << ans;
	system("pause");
	return 0;
}
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

//用折半法，讨论target和low high mid 上的元素大小，但是条件太多，难以理清
//所以直接找到最小元素，之后就好办了

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len < 1) return -1;
		int low = 0, high = len - 1;
		int minIdx;
		while (low <= high)
		{
			if (nums[low] <= nums[high])
			{
				minIdx = low;
				break;
			}
			int mid = (low + high) / 2;
			//注意这里要拿 mid 和 high 比较
			//只有两个元素时 mid==low， 可能会出错
			nums[mid] > nums[high] ? low = mid + 1 : high = mid;
		}

		if (target < nums[minIdx] || nums[(minIdx - 1 + len)%len] < target) return -1;
		
		if (target >= nums[0])
			return bSearch(0, (minIdx - 1 +len)%len, nums, target);
		else return bSearch(minIdx, len - 1, nums, target);
		

	}
	int bSearch(int i, int j, vector<int>& nums, int t)
	{
		while (i<=j)
		{
			int mid = (i + j) / 2;
			if (nums[mid] == t) return mid;
			if (i == j && nums[mid] != t) return -1;
			nums[mid] < t ? i = mid + 1 : j = mid;
		}
		return -1;
	}
};

int main()
{
	Solution solu;
	vector<int > vec = { 3,1};
	int t = 1;
	int ans = solu.search(vec, t);
	cout << ans;
	system("pause");
	return 0;
}
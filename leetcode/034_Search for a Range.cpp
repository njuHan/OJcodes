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
	vector<int> searchRange2(vector<int>& nums, int target) {
		int len = nums.size();
		if (len < 1) return{ -1,-1 };
		if (target<nums[0] || target>nums[len - 1]) return{ -1,-1 };
		int low = 0, high = len - 1;
		int find = -1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] == target)
			{
				find = mid;
				break;
			}
			if (low == high) break;
			nums[mid] < target ? low = mid + 1 : high = mid;
		}
		if (find == -1) return { -1,-1 };
		int l = find, r = find;
		while (l - 1 >= 0 && nums[l - 1] == target) l--;
		while (r + 1 < len && nums[r + 1] == target) r++;
		return { l,r };
	}
	/*
	ForwardIter lower_bound(ForwardIter first, ForwardIter last,const _Tp& val)算法返回一个非递减序列[first, last)中的第一个大于等于值val的位置。
	ForwardIter upper_bound(ForwardIter first, ForwardIter last, const _Tp& val)算法返回一个非递减序列[first, last)中第一个大于val的位置。
	*/
	vector<int> searchRange(vector<int>& nums, int target) {
		auto it1 = lower_bound(nums.begin(), nums.end(), target);
		auto it2 = upper_bound(nums.begin(), nums.end(), target);
		if ((it1 == nums.end() && it2 == nums.end()) || *it1 != target)
			return vector<int>({ -1, -1 });
		else
			return vector<int>({ it1 - nums.begin(), it2 - nums.begin() - 1 });
	}

};

int main()
{
	Solution solu;
	vector<int > vec = { 5, 7, 7, 8, 8, 10 };
	int t = 1;
	vector<int > ans = solu.searchRange(vec, 8);
	
	system("pause");
	return 0;
}
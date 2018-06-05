#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
using namespace std;


/*
272 / 275 test cases passed.
Input:
[1,1,3,1]
3
Output: false
Expected: true
error : minidx = 0

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size()-1, minidx=0, maxidx=0;
		while (lo<hi)
		{
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] > nums[hi]) lo = mid + 1;
			else if (nums[mid] < nums[hi]) hi = mid;
			else hi--;
		}
		minidx = lo;
		maxidx = (lo + nums.size() - 1) % nums.size();
		if (target<nums[minidx] || target>nums[maxidx]) return false;
		if (target >= nums[0]) return bSearch(0, maxidx + 1, nums, target);
		else return bSearch(maxidx, nums.size(), nums, target);
	}
	bool bSearch(int x, int y, vector<int>& nums, int target)
	{
		while (x<y)
		{
			int mid = x + (y - x) / 2;
			if (nums[mid] == target) return true;
			if (nums[mid] < target) x = mid+1;
			else y = mid;
		}
		return false;
	}
};
*/

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C++-solution-(o(logn)-on-average-o(n)-worst-case)
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0) return false;
		int lo = 0, hi = nums.size()-1;
		while (lo < hi)
		{
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) return true;
			if (nums[lo] < nums[mid])
			{
				if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
				else lo = mid + 1;
			}
			else if (nums[mid] < nums[hi])
			{
				if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
				else hi = mid - 1;
			}
			else
			{
				if (nums[lo] == nums[mid]) lo++;
				if (nums[hi] == nums[mid]) hi--;
			}
		}
		return nums[lo] == target;
	}
};

int main()
{
	Solution solu;
	vector<int> vec = { 2,5,6,0,0,1,2 };
	solu.search(vec, 0);
	return 0;
}
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) return len;
		int cnt = 0, max = INT_MIN;
		vector<int>::iterator it = nums.begin();
		while (it!=nums.end())
		{
			if (*it == max)
			{
				if (cnt < 2)
				{
					cnt++;
					it++;
				}
				else
				{
					it = nums.erase(it);
				}
				
			}
			else
			{
				max = *it;
				cnt = 1;
				it++;
			}
		}
		return nums.size();
	}
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size(), more = 1;
		int i;
		for ( i = len - 1; i >= 0; i--)
		{
			digits[i] += more;
			if (digits[i] < 10)
				break;
			more = digits[i] / 10;
			digits[i] %= 10;
		}
		if (-1 == i && more)
		{
			digits.insert(digits.begin(), more);
		}
		return digits;
	}
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		if (numRows < 1) return ans;
		ans.push_back({ 1 });
		for (int i = 1; i < numRows; i++)
		{
			vector<int> vec(i + 1, 1);
			for (int j = 0; j < vec.size(); j++)
			{
				if (j - 1 >= 0 && j < i)
					vec[j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
			ans.push_back(vec);
		}
		return ans;
	}
	vector<int> getRow(int rowIndex) {
		vector<int> ans(rowIndex + 1, 1);
		for (int i = 1; i <= rowIndex; i++)
		{
			int pre = rowIndex - i;
			for (int j = pre+1; j < rowIndex; j++)
			{
				ans[j] = ans[j] + ans[j + 1];
			}
		}
		return ans;
	}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		nums1.insert(nums1.begin()+m, nums2.begin(), nums2.end());
		nums1.resize(m + n);
		for (int i = m; i < m + n; i++)
		{
			int j = 0;
			while (j < i)
			{
				if (nums1[j]>nums1[i])
				{
					int temp = nums1[j];
					nums1[j] = nums1[i];
					nums1[i] = temp;
				}
				j++;
			}
		}
		
	}
	/*
	int arrayNesting_time_limited(vector<int>& nums) {
		int len = nums.size();
		vector<int> next(len,-1);
		for (int i = 0; i < len; i++)
			next[i] = nums[nums[i]];
		bool flag = false;
		int cnt = 1;
		do
		{
			flag = false;
			for (int i = 0; i < len; i++)
			{
				if (next[i] != nums[i] )
				{
					next[i] = nums[next[i]];
					flag = true;
				}
			}
		
			if (flag) cnt++;
		} while (flag);
		return cnt;
	}
	*/
	// 图染色的思路，避免重复访问！！！
	int arrayNesting(vector<int>& nums)
	{
		int len = nums.size();
		vector<bool> vis(len, false);
		int maxt = 0, cnt = 0;
		for (int i = 0; i < len; i++)
		{
			if (!vis[i])
			{
				int next = nums[i];
				vis[i] = true;
				do
				{
					next = nums[next];
					vis[next] = true;
					cnt++;
				} while (next != nums[i]);
				maxt = maxt < cnt ? cnt : maxt;
				cnt = 0;
			}
		}
		return maxt;
		
	}
	int findMin_1(vector<int>& nums) {
		if (nums.size() <= 1) return nums[0];
		int low = 0, high = nums.size()-1;
		
		while (low < high)
		{
			if (nums[low] < nums[high]) return nums[low]; //有序
			if (low + 1 == high)
				return nums[low]<nums[high] ? nums[low] : nums[high];
			int mid = (low + high) / 2;
			if (nums[low]>nums[mid])
				high = mid;
			else
				low = mid;
		}
	}
	/*
	Follow up for "Find Minimum in Rotated Sorted Array":
	What if duplicates are allowed?

	Would this affect the run-time complexity? How and why?
	*/
	int findMin(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) return 0;
		if (len == 1) return nums[0];
		int low = 0, high = len - 1;
		while (low < high)
		{
			if (nums[low] < nums[high]) return nums[low]; //有序
			if (low + 1 == high)
				return nums[low]<nums[high] ? nums[low] : nums[high];
			int mid = (low + high) / 2;
			if (nums[low] < nums[mid])
				low = mid;
			else if (nums[low]>nums[mid])
				high = mid;
			else
				low++;
		}
	}
};

int main() 
{
	vector<int> vec = { 2,3,3,4,1,1,2 };
	Solution solu;
	int ans = solu.findMin(vec);
	printf("%d\n", ans);
	system("pause");
	return 0;
}
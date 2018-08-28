#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

//快排思想：
int patition(vector<int>& nums, int x, int y)
{
	int greater = x, val = nums[x];
	for (int i = x; i < y; i++)
	{
		if (nums[i] > val)
			swap(nums[++greater], nums[i]);
	}
	swap(nums[greater], nums[x]);
	return x;
}
int klargest(vector<int> nums, int k)
{
	if (k < 0 || nums.size() < k) return 0;
	int x = 0, y = nums.size();
	int pivot = patition(nums, x, y);
	while (pivot!=k-1)
	{
		if (pivot < k - 1)
			x = pivot + 1;
		else
			y = pivot;
		pivot = patition(nums, x, y);
	}
	return nums[k - 1];
}

 
// O(1)空间复杂度， 不能改变数组，假如有重复元素
// O(k*n) 时间
int getK(vector<int> nums, int k)
{
	if (k < 1 || nums.size() < k) return 0;
	pair<int, int> maxidx(INT_MAX, 0);
	while (k>0)
	{
		int submax = INT_MIN, subidx;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > maxidx.first) continue;
			if (nums[i] == maxidx.first && i > maxidx.second)
			{
				k--;
				if (k == 0) return maxidx.first;
				maxidx.second = i;
			}
			if (nums[i]<maxidx.first)// nums[i]<max, update sub max
			{
				if (nums[i] > submax)
				{
					submax = nums[i];
					subidx = i;
				}
			}
		}
		maxidx = pair<int, int>(submax, subidx);
		k--;
	}
	return maxidx.first;
}


int main()
{
	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 1; i <= vec.size(); i++)
		cout << klargest(vec, i) << endl;
	system("pause");
	return 0;
}



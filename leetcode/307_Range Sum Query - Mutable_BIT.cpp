#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

// range sum , using binary indexed tree, BIT
#define lowbit(x) (x&(-x))
class NumArray {
public:
	NumArray(vector<int> nums) {
		n = nums.size();
		c = vector<int>(n + 1, 0);
		for (int i = 0; i < n; i++)
			add(i + 1, nums[i]);
	}
	void add(int x, int val)
	{
		while (x<=n)
		{
			c[x] += val;
			x = x + lowbit(x);
		}
	}
	int sum(int x)
	{
		int ans = 0;
		while (x>0)
		{
			ans += c[x];
			x = x - lowbit(x);
		}
		return ans;
	}

	void update(int i, int val) {
		val = val - sumRange(i, i);
		add(i+1, val);
	}

	int sumRange(int i, int j) {
		return sum(j + 1) - sum(i);
	}
private:
	int n;
	vector<int> c;
};


class NumArray {
public:
	NumArray(vector<int> nums) {
		n = nums.size();
		c = vector<int>(n + 1, 0);
		for (int i = 0; i < n; i++)
			add(i + 1, nums[i]);
	}

	void update(int i, int val) {
		int d = val - sumRange(i, i);
		add(i + 1, d);
	}

	int sumRange(int i, int j) {
		return sum(j+1) - sum(i);
	}
private:
	vector<int> c;
	int n;
	int lowbit(int x)
	{
		return x & (-x);
	}
	int sum(int x)
	{
		int ans = 0;
		while (x>0)
		{
			ans += c[x];
			x = x - lowbit(x);
		}
		return ans;
	}
	void add(int x, int d)
	{
		while (x<=n)
		{
			c[x] += d;
			x = x + lowbit(x);
		}
	}
};


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// great solution: https://leetcode.com/problems/burst-balloons/description/
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int len = nums.size();
		if (len <= 0) return 0;
		vector<int> newNums(len + 2, 0);
		//记忆表
		table = vector<vector<int>>(len + 2, vector<int>(len + 2, 0));
		// 新数组 首尾添加1
		for (int i = 0; i < len; i++) newNums[i + 1] = nums[i];
		newNums[0] = newNums[len + 1] = 1;
		return submax(0, len + 1, newNums);
		
	}
	int submax(int left, int right, vector<int>& newNums)
	{
		if (right - left < 2)
			return 0;
		int& ans = table[left][right];
		if (ans > 0) return ans;
		for (int i = left + 1; i < right; i++)
		{
			ans = max(ans, newNums[i] * newNums[left] * newNums[right] + submax(left, i, newNums) + submax(i, right, newNums));
		}
		return ans;
	}
private:
	vector<vector<int>> table;
};

int main()
{
	Solution solu;
	vector<int> vec = { 3,1,5,8 };
	int ans = solu.maxCoins(vec);
	cout << ans;
	system("pause");
	return 0;
}
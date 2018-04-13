#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<bitset>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int total = accumulate(nums.begin(), nums.end(), 0);
		if (total & 1) return false; //odd
		arr = nums;
		len = arr.size();
		sort(arr.rbegin(), arr.rend());
		return dfs(0,  total >> 1, total);
	}
	bool dfs(int cur,  int target, int left) //这里的left 剪枝很重要
	{
		for (int i = cur; i < len; i++)
		{
			left -= arr[i];
			if (arr[i] > target) continue;
			if (arr[i] == target || left == target) return true;
			if (dfs(i + 1, target - arr[i], left)) return true;
			if (left < target) return false;
		}
		return false;
	}
	// dp solution
	// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
	bool canPartition2(vector<int>& nums) 
	{
		int total = accumulate(nums.begin(), nums.end(), 0);
		if (total & 1) return false; //odd
		int target = total >> 1;
		int len = nums.size();
		vector<bool> dp(target + 1, 0);
		dp[0] = 1;
		for (int num : nums)
			for (int i = target; i >= num; i--)  //二维dp变为一维，注意顺序
				dp[i] = dp[i] || dp[i - num]; //利用上一轮的dp, 先更新大的i, 本轮更新的i不会在本轮再次使用
		return dp[target];                    // 否则，若num == 1 ,dp[2] = dp[1-1], dp[3] = dp[2-1], num重复使用了
	}
	//bitset 
	//https://leetcode.com/problems/partition-equal-subset-sum/discuss/90590/simple-c-4-line-solution-using-a-bitset
	bool canPartition3(vector<int>& nums)
	{
		const int maxnum = 100;
		const int maxsize = 200;
		int total = accumulate(nums.begin(), nums.end(), 0);
		if (total & 1) return false; //odd

		//bits 从最优边第0位开始， 第i位表示可以组成和为 i 的子集
		bitset< (maxnum*maxsize >> 1) + 1> bits(1); //初始化和为0的子集为true
		for (int num : nums)
			bits = bits | (bits << num);
		return bits[total >> 1];
	}
private:
	vector<int> arr;
	int len;
};



int main()
{

	vector<int> vec = {1,2,5};
	Solution solu;
	solu.canPartition2(vec);

	system("pause");
	return 0;
}




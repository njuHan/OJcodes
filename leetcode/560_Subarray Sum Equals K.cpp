#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
#include<bitset>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int subarraySum2(vector<int>& nums, int k) {
		int len = nums.size();
		vector<int> sum(len + 1, 0);
		for (int i = 1; i <= len; i++)
			sum[i] = sum[i - 1] + nums[i - 1];
		int ans = 0;
		for (int i = 0; i < len; i++)
			for (int j = i + 1; j <= len; j++)
				if (sum[j] - sum[i] == k)
					ans++;
		return ans;
	}
	//prefix map faster
	int subarraySum(vector<int>& nums, int k) {
		int len = nums.size();
		int ans = 0;
		unordered_map<int, int> sumCnt;
		sumCnt[0]++;
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			sum += nums[i];
			if (sumCnt.count(sum - k)) ans += sumCnt[sum-k];
			sumCnt[sum]++;
		}
		return ans;

	}
};
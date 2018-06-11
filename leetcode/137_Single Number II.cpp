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
#include<ctime>
using namespace std;

//https://leetcode.com/problems/single-number-ii/discuss/43313/A-general-C++-solution-for-these-type-problems
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> bitCnt(32);
		for (int num : nums)
		{
			for (int i = 31; i >=0 ; i--)
			{
				if (num & 1) bitCnt[i]++;
				num = num >> 1;
				if (!num) break;
			}
		}
		int ans = 0;
		for (int i = 0; i < 32; i++)
		{
			ans = ans << 1;
			if (bitCnt[i] % 3) ans += ans | 1;
		}
		return ans;
	}
};
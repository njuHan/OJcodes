#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	//ÅÅĞò£¬¶ş·Ö²é
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int x = 0, y = nums.size();
		while (x<y)
		{
			int m = x + (y - x) / 2;
			if (nums[m] > m) y = m;
			else x = m + 1;
		}
		return x;
	}
	//xor
	int missingNumber2(vector<int>& nums) {
		int ans = 0, i = 1;
		for (int num : nums)
		{
			ans ^= i++;
			ans ^= num;
		}
		return ans;
	}
	//sum
	int missingNumber2(vector<int>& nums)
	{
		int ans = 0, i=1;
		for (int num : nums)
		{
			ans += i++ - num;
		}
		return ans;
	}
};
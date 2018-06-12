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
#include<sstream>
using namespace std;


class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int axorb = 0, a = 0, b = 0;
		for (int num : nums) axorb ^= num;
		int lowbit = axorb & (-axorb);
		for (int num : nums)
		{
			if (num&lowbit) a ^= num;
			else b ^= num;
		}
		return{ a,b };
	}
};
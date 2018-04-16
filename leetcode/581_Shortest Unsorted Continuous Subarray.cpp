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
	/*
	1. From the left, for a number to stay untouched, there need to be no number less than it on the right hand side;
	2. From the right, for a number to stay untouched, there need to be no number greater than it on the left hand side;
	*/
	int findUnsortedSubarray(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) return 0;
		vector<int> maxlhs(len, 0);
		vector<int> minrhs(len, 0);
		maxlhs[0] = nums[0];
		minrhs[len - 1] = nums[len - 1];
		for (int i = 1; i < len; i++) maxlhs[i] = max(nums[i], maxlhs[i - 1]);
		for (int i = len - 2; i >= 0; i--) minrhs[i] = min(nums[i], minrhs[i + 1]);
		int i = 0, j = len - 1;
		while (i < len && nums[i] <= minrhs[i]) i++;
		while (j > i && nums[j] >= maxlhs[j]) j--; // j>i, i已经检查的元素，无需再检查
		return j - i + 1;  //i, j 指向需要排序元素的首尾，元素个数+1
	}
};


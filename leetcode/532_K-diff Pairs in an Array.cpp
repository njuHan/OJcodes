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

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;
		unordered_set<int> ans, preNum;
		for (int num : nums)
		{
			if (preNum.count(num - k)) ans.insert(num - k);
			if (preNum.count(num + k)) ans.insert(num);
			preNum.insert(num);
		}
		return ans.size();
	}
};
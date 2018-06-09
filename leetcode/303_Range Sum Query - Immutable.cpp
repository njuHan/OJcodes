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


class NumArray {
public:
	NumArray(vector<int> nums) {
		int n = nums.size();
		curSum = vector<int>(n + 1, 0);
		int cur = 0;
		for (int i = 0; i < n; i++)
			curSum[i + 1] = (cur += nums[i]);
	}

	int sumRange(int i, int j) {
		return curSum[j + 1] - curSum[i];
	}
private:
	vector<int> curSum;
};

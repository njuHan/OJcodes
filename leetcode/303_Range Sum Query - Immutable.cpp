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
		sum = vector<int>(n+1, 0);
		for (int i = 0; i < n; i++)
			sum[i + 1] = sum[i] + nums[i];
	}

	int sumRange(int i, int j) {
		return sum[j+1] - sum[i];
	}
private:
	vector<int> sum;
};
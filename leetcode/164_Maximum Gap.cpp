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
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return 0;
		auto min_max = minmax_element(nums.begin(), nums.end());
		int minGap = (*min_max.second - *min_max.first) / (n - 1);
		minGap = minGap > 1 ? minGap : 1;
		int m = (*min_max.second - *min_max.first) / minGap + 1;
		vector<int> bucketMin(m, INT_MAX), bucketMax(m, INT_MIN);
		for (int num : nums)
		{
			int k = (num - *min_max.first) / minGap;
			if (num < bucketMin[k]) bucketMin[k] = num;
			if (num > bucketMax[k]) bucketMax[k] = num;
		}
		int maxGap = bucketMax[0] - bucketMax[0], i=0, j;
		while (i<m-1)
		{
			j = i + 1;
			while (j < m && bucketMax[j] == INT_MIN) j++; //skip empty bucket
			if (j == m) break;
			maxGap = max(maxGap, bucketMin[j] - bucketMax[i]);
			i = j;
		}
		return maxGap;
	}
};
#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<map>
#include<set>
#include<algorithm> 
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		vector<int> sorted(nums);
		sort(sorted.begin(), sorted.end());
		for (int k = 0, i = n / 2 + n % 2, j = n-1; k < n; k++)
			nums[k] = sorted[(k & 1) == 0 ? i++ : j++];
	}
};
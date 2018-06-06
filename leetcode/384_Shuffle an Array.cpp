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
	Solution(vector<int> nums) {
		this->nums = nums;
		srand(time(0));
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return nums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> ans(nums.begin(), nums.end());
		int sz = ans.size();
		for (int i = 0; i < sz; i++)
			swap(ans[i], ans[rand() % sz]);
		return ans;
	}
private:
	vector<int> nums;
};

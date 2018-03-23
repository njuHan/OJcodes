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
	int maxProduct(vector<int>& nums) {
		int len = nums.size();
		if (len < 1) return 0;
		int maxPre = nums[0], minPre = nums[0], maxCur, minCur;
		int ans = nums[0];
		for (int i = 1; i < len; i++)
		{
			maxCur = max(max(maxPre*nums[i], minPre*nums[i]), nums[i]);
			minCur = min(min(maxPre*nums[i], minPre*nums[i]), nums[i]);
			ans = max(maxCur, ans);
			maxPre = maxCur;
			minPre = minCur;
		}
		return ans;
	}
};

int main()
{


	system("pause");
	return 0;
}
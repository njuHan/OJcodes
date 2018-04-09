#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> ans(len, 1);
		for (int i = 1; i < len; i++)
			ans[i] *= ans[i - 1] * nums[i - 1];
		int right = 1;
		for (int j = len - 1; j >= 0; right *= nums[j--])
			ans[j] *= right;
		return ans;
	}
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> ans(len, 1);
		int left = 1, right = 1;
		for (int i = 0; i < len; i++)
		{
			ans[i] *= left;
			left *= nums[i];
			ans[len - i - 1] *= right;
			right *= nums[len - i - 1];
		}
		return ans;
	}
};

int main()
{

	
	system("pause");
	return 0;
}




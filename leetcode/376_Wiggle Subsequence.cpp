#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int len = nums.size();
		if (len < 2)
			return len;
		int* up = new int[len];
		int* down = new int[len];
		up[0] = down[0] = 1;
		for (int i = 1; i < len; i++)
		{
			if (nums[i] > nums[i - 1])
			{
				up[i] = down[i - 1] + 1;
				down[i] = down[i - 1];
			}
			else if (nums[i] < nums[i - 1])
			{
				down[i] = up[i - 1] + 1;
				up[i] = up[i - 1];
			}
			else
			{
				down[i] = down[i - 1];
				up[i] = up[i - 1];

			}
		}
		int ans =  down[len - 1] > up[len - 1] ? down[len - 1] : up[len - 1];
		delete[] up;
		delete[] down;
		return ans;
	}
};


int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
	Solution solu;
	int ans = solu.wiggleMaxLength(v);
	printf("%d\n", ans);
	system("pause");
	return 0;
}
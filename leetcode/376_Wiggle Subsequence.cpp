#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n<1) return 0;
        int up = 1, down = 1;
        for (int i=1; i<n; i++)
        {	
			//证明 nums[i-1]和 nums[i]之间的大小关系，可以保证 up down 序列衔接正确
			// 如果(nums[i-1]<nums[i]) 且 nums[i-1]结尾是下降的，那么加上nums[i]，以nums[i]结尾上升：满足 up = down + 1;
			// 如果(nums[i-1]<nums[i]) 且 nums[i-1]结尾是上升的，那么必定存在 j< i-1 && nums[j]<nums[i-1] => nums[j]<nums[i], 
			// nums[j]作用于down, 加上nums[i]，以nums[i]结尾上升：满足 up = down + 1;
			// 同理可知 down = up + 1 正确
            if (nums[i-1]<nums[i]) up = down + 1; 
            else if (nums[i-1]>nums[i]) down = up+1;
        }
        return max(up, down);
    }
};

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
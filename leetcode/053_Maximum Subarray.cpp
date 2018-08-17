#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

//dp solutions
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int sum = nums[0], ans = nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            sum = sum>0 ? sum + nums[i] : nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};

// divide and conquer approach , O(n)
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		this->nums = nums;
		int x = 0, y = nums.size(), mx = 0, l, r, s;
		findMax(x, y, mx, l, r, s);
		return mx;
	}
private:
	vector<int> nums;
	//[x,y)
	void findMax(int x, int y, int& mx, int& left, int& right, int &sum )
	{
		if (y - x == 1)
		{
			mx = left = right = sum = nums[x];
			return;
		}
		int m = x + (y - x) / 2;
		int mx1, mx2, l1, l2, r1, r2, s1, s2;
		findMax(x, m, mx1, l1, r1, s1);
		findMax(m, y, mx2, l2, r2, s2);
		mx = max({ mx1,mx2, r1 + l2 }); //左边、右边、中间包括mid
		//O(1)更新 left right sum ，使得T(n) = 2T(n/2) + O(1)
		left = max(l1, s1 + l2);
		right = max(r2, s2 + r1);
		sum = s1 + s2;
	}
};

int main()
{
	Solution solu;
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	int ans = solu.maxSubArray(nums);
	cout << ans;
	system("pause");
	return 0;
}
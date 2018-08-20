#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], cnt = 0;
        for (int num : nums)
        {
            if (cnt==0) ans = num;
            cnt += ans==num ? 1 : -1; 
        }
        return ans;
    }
};

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int len = nums.size();
		if (len < 1) return 0;
		stack<int> sk;
		sk.push(nums[0]);
		for (int i = 1; i < len; i++)
		{
			if (sk.empty() || sk.top() == nums[i])
				sk.push(nums[i]);
			else
				sk.pop();
		}
		return sk.top();
		
	}
};

int main()
{


	system("pause");
	return 0;
}
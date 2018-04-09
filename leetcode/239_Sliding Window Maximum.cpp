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


//solution : https://leetcode.com/problems/sliding-window-maximum/discuss/65884/Java-O(n)-solution-using-deque-with-explanation
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int len = nums.size();
		deque<int> idxque;
		vector<int> ans;
		if (len < 1 || k < 1) return ans;
		for (int i = 0; i < len; i++)
		{
			while (!idxque.empty() && idxque.front()<i-k+1)
			{
				idxque.pop_front();
			}
			while (!idxque.empty() && nums[idxque.back()]<nums[i]) //使得队列nums元素大小降序
			{
				idxque.pop_back();
			}
			idxque.push_back(i);
			if (i >= k - 1) ans.push_back(nums[idxque.front()]);
		}
		return ans;
	}
};
int main()
{


	system("pause");
	return 0;
}




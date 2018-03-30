
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;


class Solution {
public:
	//O(n*n) time out
	int candy1(vector<int>& ratings) {
		int len = ratings.size();
		if (len < 1) return 0;
		int ans = len;
		vector<int> nums(len, 1);
		for (int e : ratings)
		{
			rate.insert(e);
		}
		rate.erase(rate.begin());
		for (int r : rate)
		{
			for (int i = 0; i < len; i++)
			{
				if (ratings[i] == r)
				{
					int temp = nums[i];
					if (i > 0 && ratings[i - 1] < ratings[i]) nums[i] = max(nums[i], nums[i - 1] + 1);
					if (i < len - 1 && ratings[i + 1] < ratings[i]) nums[i] = max(nums[i], nums[i + 1] + 1);
					ans += nums[i] - temp;
				}
			}
		}
		return ans;
	}

	// scan twice, O(n) menmory space
	int candy2(vector<int>& ratings)
	{
		int len = ratings.size();
		if (len < 1) return 0;
		if (1 == len) return 1;
		vector<int> nums(len, 0);
		nums[0] = 1;
		for (int i = 1; i < len; i++)
		{
			if (ratings[i] > ratings[i - 1]) nums[i] = nums[i - 1] + 1;
			else nums[i] = 1;
		}
		int ans = nums[len - 1];
		for (int i = len - 2; i >= 0; i--)
		{
			if (ratings[i] > ratings[i + 1] && nums[i] <= nums[i + 1]) nums[i] = nums[i + 1] + 1;
			ans += nums[i];
		}
		return ans;
	}
	/*
	This solution picks each element from the input array only once. First, we give a candy to the first child. Then for each child we have three cases:

	His/her rating is equal to the previous one -> give 1 candy.
	His/her rating is greater than the previous one -> give him (previous + 1) candies.
	His/her rating is less than the previous one -> don’t know what to do yet, let’s just count the number of such consequent cases.
	When we enter 1 or 2 condition we can check our count from 3. 
	If it’s not zero then we know that we were descending before 
	and we have everything to update our total candies amount: number of children in 
	descending sequence of raitings - coundDown, number of candies given at peak - prev 
	(we don’t update prev when descending). Total number of candies for 
	“descending” children can be found through arithmetic progression formula 
	(1+2+…+countDown). Plus we need to update our peak child if his number of candies is less then or equal to countDown.
	*/
	//O(n) time , O(1) space
	int candy(vector<int>& ratings) {
		int len = ratings.size();
		if (len < 1) return 0;
		if (1 == len) return 1;
		int ans = 1, pre = 1, downCnt = 0;
		for (int i = 1; i < len; i++)
		{
			//注意这个if判断，提高代码复用
			if (ratings[i] >= ratings[i - 1])
			{
				if (downCnt > 0)
				{
					if (pre <= downCnt) ans += (downCnt + 1 - pre);
					ans += ((1 + downCnt)*downCnt >> 1);
					downCnt = 0;
					pre = 1; 
				}
				pre = ratings[i] == ratings[i - 1] ? 1 : pre+1;
				ans += pre;
			}
			else
				downCnt++;
		}
		if (downCnt > 0)
		{
			ans += ((1 + downCnt)*downCnt >> 1);
			if (pre <= downCnt) ans += downCnt + 1 - pre;
		}
		return ans;
	}
private:
	set<int> rate;

};
int main()
{
	Solution solu;
	vector<int> vec = { 1,1,2,2 };
	int ans = solu.candy(vec);
	
	return 0;
}
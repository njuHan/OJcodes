#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len <= 1) return 0;
		/*
		states[][0]: one buy
		states[][1]: one buy, one sell
		states[][2]: two buys, one sell
		states[][3]: two buy, two sells
		*/
		// 买的收益初始化为最小值，把买的价格视为负数
		// 卖的收益初始化为 0 
		int states[2][4] = { INT_MIN, 0, INT_MIN, 0 };
		int cur = 0, next = 1;
		for (int i = 0; i < len; i++)
		{
			states[next][0] = max(states[cur][0], -prices[i]);
			states[next][1] = max(states[cur][1], states[cur][0] + prices[i]);
			states[next][2] = max(states[cur][2], states[cur][1] - prices[i]);
			states[next][3] = max(states[cur][3], states[cur][2] + prices[i]);
			printf("%d %d %d %d\n", states[next][0], states[next][1], states[next][2], states[next][3]);
			swap(next, cur);
		}
		return max(states[cur][1], states[cur][3]);
	}
	
};

int main()
{
	Solution solu;
	vector<int> A = { 1,3,5,7,2,4,6,8 };
	int ans = solu.maxProfit(A);
	printf("%d", ans);
	system("pause");
	return 0;
}
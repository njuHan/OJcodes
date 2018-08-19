#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


class Solution2 {
public:
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
    int maxProfit(vector<int>& prices) {
        vector<int> buy(3, INT_MAX), sell(3, 0);
        for (int i=0; i<prices.size(); i++)
            for (int k=1; k<=2; k++)
            {
                //we integrate the profit of first transaction into the cost of the second buy, 
                //then the profit of the second sell will be the total profit of two transactions.
				// 第 k 次交易的最低买入价，要考虑进之前交易的收益， 买入价 = prices[i] - sell[k-1]
                buy[k] = min(buy[k], prices[i] - sell[k-1]);
				// 前 k 次交易的总收益(1,2,...,k)，是一个累积收益值，与buy[i]的单次买入不同
                sell[k] = max(sell[k], prices[i] - buy[k]);
            }
        return sell[2];
    }
};

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
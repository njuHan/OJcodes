#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n < 2) return 0;
		vector<int> buy(n, INT_MIN), sell(n, 0);
		buy[0] = -prices[0]; buy[1] = max(-prices[0], -prices[1]);
		sell[1] = max(sell[0], buy[0] + prices[1]);
		for (int i = 2; i < n; i++)
		{
            //buy[i]：在第 i 天 以买结束的最大收益
            //等于 不买，直接继承buy[i-1]， 或者买prices[i]，加上sell[i-2]
			buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
		}
		return sell[n - 1];
	}
};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len <= 1) return 0;
		vector<int> buy(len + 1, INT_MIN);
		vector<int> sell(len + 1, 0);
		buy[0] = -prices[0];
		buy[1] = max(buy[0], -prices[1]);
		sell[1] = max(sell[1], buy[0] + prices[1]);
		for (int i = 2; i < len; i++)
		{
			buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
		}
		return sell[len - 1];
	}
};

int main()
{
	Solution solu;
	vector<int> A = { 1,3,5,7,2,4,6,8,9,10,11,12 };
	int ans = solu.maxProfit(A);
	printf("%d", ans);
	system("pause");
	return 0;
}
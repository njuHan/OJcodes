#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int len = prices.size();
		if (len <= 1) return 0;
		vector<int> buy(len + 1, INT_MIN);
		vector<int> sell(len + 1, 0);
		buy[0] = -prices[0];
		for (int i = 1; i < len; i++)
		{
			buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
		}
		return sell[len - 1];
	}
};

int main()
{
	Solution solu;
	vector<int> A = { 1, 3, 2, 8, 4, 9 };
	int ans = solu.maxProfit(A,2);
	printf("%d", ans);
	system("pause");
	return 0;
}
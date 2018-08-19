#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n/2 <= k)
        {
            int ans = 0;
            for (int i=1; i<n; i++) ans += max(0, prices[i] - prices[i-1]);
            return ans;
        }
        vector<int> buy(k+1, INT_MAX), sell(k+1, 0);
        for (int num : prices)
            for (int i=1; i<=k; i++)
            {
                buy[i] = min(buy[i], num - sell[i-1]);
                sell[i] = max(sell[i], num - buy[i]);
            }
        return sell[k];
    }
};

class Solution {

public:
	int maxProfit(int k, vector<int>& prices) 
	{
		int len = prices.size();
		if (len <= 1 || k <= 0) return 0;
		if (k >= len / 2) return maxProfit(prices);
		vector<int> buy(k + 1, INT_MIN);
		vector<int> sell(k + 1, 0);
		for (int i = 0; i < len; i++)
			for (int j = 1; j <= k; j++)
			{
				buy[j] = max(buy[j], sell[j-1] - prices[i]);
				sell[j] = max(sell[j], buy[j] + prices[i]);
			}
		return sell[k];
	}
	//leetcode 122:
	int maxProfit(vector<int>& prices) 
	{
		int len = prices.size();
		int maxpft = 0;
		for (int i = 1; i < len; i++)
		{
			maxpft += max(prices[i] - prices[i - 1], 0);
		}
		return maxpft;
	}
};

int main()
{
	Solution solu;
	vector<int> A = { 1,3,5,7,2,4,6,8,9,10,11,12 };
	int ans = solu.maxProfit(6,A);
	printf("%d", ans);
	system("pause");
	return 0;
}
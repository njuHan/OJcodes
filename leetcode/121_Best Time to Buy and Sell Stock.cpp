#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) 
	{
		int len = prices.size();
		if (len <= 1) return 0;
		int minbuy = prices[0];
		int pft = 0;
		for (int i = 1; i < len; i++)
		{
			pft = prices[i] - minbuy > pft ? prices[i] - minbuy : pft;
			minbuy = minbuy > prices[i] ? prices[i] : minbuy;
		}
		return pft;
	}
};

int main()
{
	Solution solu;
	vector<int> A = { 7,6,4,3,1 };
	int ans = solu.maxProfit(A);
	printf("%d", ans);
	system("pause");
	return 0;
}
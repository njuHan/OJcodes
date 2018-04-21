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


class Solution {
public:
	int numSquares(int n) 
	{
		static vector<int> dp(1,0);
		if (n < dp.size()) return dp[n];
		int m = dp.size();
		dp.resize(n+1, INT_MAX);
		for (int i = 1, i2; (i2 = i*i) <= n; i++)
		{
			for (int j = max(m, i2); j <= n; j++)
			{
				dp[j] = dp[j] > dp[j - i2] + 1 ? dp[j - i2] + 1 : dp[j];
			}
		}
		return dp[n];
		
	}
	int numSquares2(int n)
	{
		vector<int> dp(1,0); //dp[0] =1;
		while (dp.size()<=n)
		{
			int m = dp.size();
			int num = INT_MAX;
			for (int i = 1; i*i <= m; i++)
				num = min(num, dp[m - i*i]+1);
			dp.push_back(num);
		}
		return dp[n];
	}


};
int main()
{


	system("pause");
	return 0;
}




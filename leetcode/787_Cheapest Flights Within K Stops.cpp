#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
	{
		int stepNum = K + 1;
		vector<vector<int>> dp(n, vector<int>(stepNum + 1, -1));
		dp[src][0] = 0;
		for (int i = 1; i <= stepNum; i++)
		{
			for (int j = 0; j < n; j++)
				dp[j][i] = dp[j][i - 1];
			for (int j = 0; j < flights.size(); j++)
			{
				int u = flights[j][0], v = flights[j][1], dist = flights[j][2];
				if (dp[u][i - 1] != -1)
				{
					int temp = dp[u][i - 1] + dist;
					dp[v][i] = dp[v][i] == -1 ? temp : min(dp[v][i], temp);
				}
			}
		}
		
		return dp[dst][stepNum];
	}
};
int main()
{
	Solution solu;
	vector<vector<int>> f = { {0, 1, 2},{1, 2, 1},{2, 0, 10 } };
	int n = 3;
	int ans = solu.findCheapestPrice(n, f, 1, 2 ,1);
	cout << ans << endl;
	system("pause");
	return 0;
}
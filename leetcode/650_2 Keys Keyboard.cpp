#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minSteps(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 0;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = i; //对于质数i，每次只粘贴一个 A
			for (int j = i - 1; j > 1; j--) //找最大因数，每次粘贴至少2个A
			{
				if (i%j == 0)
				{
					dp[i] = dp[j] + i / j;
					break;
				}
			}
		}
		return dp[n];
	}
};

int main()
{
	Solution solu;
	int ans = solu.minSteps(12);
	printf("%d", ans);
	system("pause");
	return 0;
}
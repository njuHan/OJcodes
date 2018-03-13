#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;


class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size(), n = s2.size(), t = s3.size();
		if (m + n != t) return false;
		vector<vector<bool>> dp(m+1 , vector<bool>(n + 1, false));
		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= n; j++)
			{
				if (i == 0 && j == 0)
					dp[0][0] = 1;
				else if (j == 0)
					dp[i][j] = s1.substr(0, i) == s3.substr(0, i);
				else if (i == 0)
					dp[i][j] = s2.substr(0, j) == s3.substr(0, j);
				else
				{
					if (s1[i - 1] == s3[i + j - 1])
						dp[i][j] = dp[i - 1][j];
					if (s2[j - 1] == s3[i + j - 1])
						dp[i][j] = dp[i][j - 1] || dp[i][j];
				}
			}
		return dp[m][n];
	}
};


int main()
{
	Solution solu;

	bool ans = solu.isInterleave("aa","bb","abab");
	//printf("%d\n", ans);
	system("pause");
	return 0;
}
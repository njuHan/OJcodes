#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		//dp[i][j]表示s的前i个字符与 p中的前j个字符是否匹配
		//即s[0...i-1] 与 p[0...j-1]注意下标
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		//dp[0][j]，j>0 可能匹配 (p[j-1]=='*')
		//dp[i][0], i>0 不可能匹配
		//所以 递推时无需讨论j==0的情况
		//两个串都为0长度空串时，匹配
		dp[0][0] = true;
		for (int i = 0; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				//进行i-1时，一定要首先判断i>0 !!!!!!!!!!!!!!
				if (p[j - 1] != '*')
					dp[i][j] = (i>0) && (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i][j - 2] || ( i>0 && (p[j-2]=='.'||s[i - 1] == p[j - 2]) && dp[i - 1][j] );
			}
		return dp[m][n];
	}
};

int main()
{
	system("pause");
	return 0;
}
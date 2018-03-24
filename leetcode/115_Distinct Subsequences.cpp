#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int m = s.size(), n = t.size();
		if (n == 0) return 1;
		if (m < n || m == 0) return 0;
		//dp[i][j] : s[0...i-1] Æ¥Åä t[0...j-1]µÄ´ÎÊý, i>=j
		int cnt = 0;
		vector <vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= m; i++) dp[i][0] = 1;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= i && j <= n; j++)
			{
				dp[i][j] = dp[i - 1][j] + (dp[i - 1][j - 1])*(s[i - 1] == t[j - 1]);
			}
		}
		return dp[m][n];
	}
};
int main()
{
	Solution solu;
	string s = "rabbbitt";
	string t = "rabit";
	int ans = solu.numDistinct(s, t);
	system("pause");
	return 0;
}
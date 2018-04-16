#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<bitset>
#include<stack>
using namespace std;



class Solution {
public:
	// dp[i][j]: the longest palindromic subsequence¡¯s length of substring(i, j)
	int countSubstrings(string s) {
		int len = s.length();
		vector<vector<int>> dp(len, vector<int>(len, 0));
		for (int i = 0; i < len; i++) dp[i][i] = 1;
		for (int d = 1; d<len; d++) // distance between i,j
			for (int i = 0; i < len - d; i++)
			{
				int j = i + d;
				dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] + 2 : (dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1]);
			}
		return dp[0][len - 1];

	}
	//longest common subsequence LCS
	int countSubstrings2(string s) {
		string revS(s.rbegin(), s.rend());
		int len = s.length();
		vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
		for (int i=1;i<=len; i++)
			for (int j = 1; j <= len; j++)
			{
				dp[i][j] = s[i-1] == revS[j-1] ? dp[i - 1][j - 1] + 1 :(dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
			}
		return dp[len][len];
	}
};
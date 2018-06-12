#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		int len1 = strlen(str), len2 = strlen(pattern);
		vector<vector<bool>> dp(len1 + 1, vector<bool>(len2, 0));
		dp[0][0] = 1;
		for (int i = 0; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (pattern[j - 1] != '*')
					dp[i][j] = (i > 0) && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.') && dp[i-1][j-1];

				else
					//匹配0个 或者多个(匹配当前i-1，匹配上一个: i-2)
					dp[i][j] = dp[i][j - 2] || ( (i>0)&&(str[i-1]==pattern[j-2]||pattern[j-2]=='.')&&dp[i-1][j] );
			}
		}
		return dp[len1][len2];
	}
};
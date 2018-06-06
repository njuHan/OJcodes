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
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int n = s.length();
		vector<vector<bool>> isPalin(n, vector<bool>(n, false));
		vector<int> dp(n); //[0:i] min cut;
		for (int i = 0; i < n; i++) dp[i] = i;
		for (int j = 1; j < n; j++)
		{
			//substr [i...j]
			for (int i = j; i >= 0; i--)
			{
				if (s[i] == s[j] && (j - i <= 2 || isPalin[i + 1][j - 1]))
				{
					isPalin[i][j] = 1;
					if (i == 0) dp[j] = 0;
					else dp[j] = min(dp[j], dp[i - 1] + 1);
				}
			}
		}
		return dp[n-1];
	}
};
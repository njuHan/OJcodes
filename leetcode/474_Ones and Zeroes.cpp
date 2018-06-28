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
#include<functional>
using namespace std;

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int len = strs.size();
		if (len <= 0 || (m <= 0 && n <= 0)) return 0;
		for (string str : strs) cnt(str);
		vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
		for (int i = 1; i <= len; i++)
		{
			for (int j = 0; j <= m; j++)
				for (int k = 0; k <= n; k++)
				{
					int num0 = cnt01[strs[i-1]].first, num1 = cnt01[strs[i-1]].second;
					if (j >= num0 && k >= num1)
						dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - num0][k - num1] + 1);
					else dp[i][j][k] = dp[i - 1][j][k];	
				}
		}
		return dp[len][m][n];
	}

	int findMaxForm2(vector<string>& strs, int m, int n) {
		int len = strs.size();
		if (len <= 0 || (m <= 0 && n <= 0)) return 0;
		for (string str : strs) cnt(str);
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < len; i++)
		{
			for (int j = m; j >= 0 ; j--)
				for (int k = n; k >= 0; k--)
				{
					int num0 = cnt01[strs[i]].first, num1 = cnt01[strs[i]].second;
					if (j >= num0 && k >= num1)
						dp[j][k] = max(dp[j][k], dp[j - num0][k - num1] + 1);
					else dp[j][k] = dp[j][k];
				}
		}
		return dp[m][n];
	}
private:
	unordered_map<string, pair<int, int>> cnt01;
	void cnt(string str)
	{
		if (cnt01.count(str)) return;
		int cnt0 = 0, cnt1 = 0;
		for (char ch : str)
		{
			if (ch == '0') cnt0++;
			else if (ch == '1') cnt1++;
		}
		cnt01[str] = make_pair(cnt0, cnt1);
	}
};


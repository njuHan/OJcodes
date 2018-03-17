#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


class Solution {
public:
	string longestPalindrome(string s) 
	{
		int len = s.size();
		if (len == 0) return "";
		vector<vector<bool>> vis(len, vector<bool>(len, false));
		vector<vector<bool>> isValid(len, vector<bool>(len, false));
		int maxlen = 0;
		string ans;
		for (int i = 0; i < len; i++)
			for (int j = i; j < len; j++)
			{
				if (dp(i, j, vis, isValid, s))
				{
					if (j - i + 1 > maxlen)
					{
						maxlen = j - i + 1;
						ans = s.substr(i, j - i + 1);
					}
				}
			}
		return ans;
	}
	bool dp(int i, int j, vector<vector<bool>>& vis, vector<vector<bool>>& isValid, string& s)
	{
		if (vis[i][j]) return isValid[i][j];
		vis[i][j] = true;
		if (i == j)
			return isValid[i][j] = true;
		else if (i + 1 == j)
			return isValid[i][j] = (s[i] == s[j]);
		return isValid[i][j] = (dp(i+1,j-1,vis,isValid,s) && s[i] == s[j]);

	}
};

int main()
{
	Solution solu;
	string ans = solu.longestPalindrome("babad");
	
	system("pause");
	return 0;
}
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, 0); dp[0] = 1;
        for (int i=1; i<=n; i++)
        {
            for (string& word : wordDict)
            {
                int j = word.length();
                dp[i] = dp[i] || (i>=j) && (word==s.substr(i-j, j)) && dp[i-j];
            }
        }
        return dp[n];
    }
};

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int len = s.size();
		if (len < 1) return false;
		vector<bool> dp(len+1, false); //dp[i]: 从下标0开始，长度为i的字符串是否true
		unordered_map<string, int> str2num;
		for (auto e : wordDict)
			str2num[e] = 1;
		dp[0] = true;
		for (int i = 1; i <= len; i++)
		{
			for (int j = 0; j < i; j++)
			{
				dp[i] = dp[j] && (str2num.count(s.substr(j, i - j))>0);
				if (dp[i]) break;
			}
		}
		return dp[len];
	}
};

int main()
{
	Solution solu;
	vector<int> vec = { 100, 4, 200, 1, 3, 2 };
	
	system("pause");
	return 0;
}
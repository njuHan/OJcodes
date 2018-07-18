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
#include<ctime>
#include<numeric>
using namespace std;

// same dp idea as problem 546 
class Solution {
public:
	int strangePrinter(string s) {
		if (s.empty()) return 0;
		// shorten the string s
		res = "";
		size_t start = 0, pos = 0;
		res.push_back(s[0]);
		while ((pos = s.find_first_not_of(s[start], start)) != string::npos)
		{
			res.push_back(s[pos]);
			start = pos;
		}
		dp = vector<vector<int>>(res.length(), vector<int>(res.length(), 0));
		//cout<<res<<endl;
		return print(0, res.length() - 1);
	}
private:
	vector<vector<int>> dp;
	string res;
	int print(int i, int j)
	{
		if (i > j) return 0;
		if (dp[i][j]) return dp[i][j];
		dp[i][j] = 1 + print(i + 1, j);
		for (int m = i + 1; m <= j; m++)
		{
			/*
			why not use dp[i][j] = min(dp[i][j], 1 + print(i + 1, m - 1) + print(m+1, j));
			see my answer in:
			https://leetcode.com/problems/strange-printer/discuss/106792/Java-O(n3)-short-DP-Solution/155973
			*/
			if (res[i] == res[m])
				dp[i][j] = min(dp[i][j], print(i + 1, m - 1) + print(m, j));

		}
		return dp[i][j];
	}
};

int main()
{
	string str = "aabbccddaa";
	string res = "";
	size_t start = 0, pos = 0;
	res.push_back(str[0]);
	while ( (pos = str.find_first_not_of(str[start], start)) != string::npos )
	{
		res.push_back(str[pos]);
		start = pos;
	}
	cout << res << endl;
	return 0;
}
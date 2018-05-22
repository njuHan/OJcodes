#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;

class Solution {
public:
	// dp  https://leetcode.com/problems/decode-ways/discuss/30490/7-lines-cpp-solution
	int numDecodings(string s) {
		if (s.length() == 0 || s[0] == '0') return 0;
		int f0 = 1, f1 = 1, f2 = 0;
		for (int i = 1; i < s.length(); i++)
		{
			string two = s.substr(i - 1, 2);
			f2 = (s[i] != '0')*f1 + (two >= "10" && two <= "26")*f0;
			f0 = f1;
			f1 = f2;
		}
		return f1; //return f1, in case s == "1"
	}
	// dfs Time Limit Exceeded
	int numDecodings2(string s) {
		if (s.length() == 0) return 0;
		str = s;
		ans = 0;
		dfs(0);
		return ans;
	}
private:
	int ans;
	string str;
	void dfs(int cur)
	{
		if (cur == str.length()) 
		{
			ans++;
			return;
		}
		if (str[cur] != '0') dfs(cur + 1);
		if (cur + 1 < str.length() && str.substr(cur, 2) <= "26" && str.substr(cur, 2) >= "10")
			dfs(cur + 2);
	}
};

int main()
{
	Solution solu;
	solu.numDecodings("12");

	system("pause");
	return 0;
}
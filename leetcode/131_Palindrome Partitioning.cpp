#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;


class Solution {
public:
	vector<vector<string>> partition(string s) {
		this->s = s;
		vector<string> vec;
		dfs(0, vec);
		return ans;
	}
private:
	vector<vector<string>> ans;
	string s;
	//ÅÐ¶Ï [cur ,i)ÊÇ·ñ»ØÎÄ
	void dfs(int cur, vector<string>& vec)
	{
		if (cur == s.length()) 
		{
			ans.push_back(vec);
			return;
		}
		for (int i = cur + 1; i <= s.length(); i++)
		{
			string sub = s.substr(cur, i - cur);
			if (isPalin(sub))
			{
				vec.push_back(sub);
				dfs(i, vec);
				vec.pop_back();
			}
		}
	}
	bool isPalin(string str)
	{
		int i = 0, j = str.length() - 1;
		while (i<j)
			if (str[i++] != str[j--]) return false;
		return true;
	}
};
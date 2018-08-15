#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;

class Solution2 {
public:
	vector<vector<string>> partition(string s) {
		vector<string> arr;
		search(0, arr, s);
		return ans;
	}
private:
	vector<vector<string>> ans;
	void search(int cur, vector<string>& arr, string& s)
	{
		if (cur == s.length()) { ans.emplace_back(arr); return; }
		for (int i = cur; i < s.size(); i++)
		{
			if (isPalin(s, cur, i))
			{
				arr.emplace_back(string(&s[cur], &s[i + 1]));
				search(i + 1, arr, s);
				arr.pop_back();
			}
		}
	}
	bool isPalin(string& s, int x, int y)
	{
		while (x<y)
			if (s[x++] != s[y--]) return false;
		return true;
	}
};


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
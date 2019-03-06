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
using namespace std;


class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.length() == 0) return ans;
		sort(str.begin(), str.end());
		vis = vector<bool>(str.length(), 0);
		string s(str.length(), 0);
		dfs(0, s, str);
		return ans;
	}
private:
	vector<bool> vis;
	vector<string> ans;
	void dfs(int cur, string& permu, string& str)
	{
		if (cur == str.length())
		{
			ans.emplace_back(permu);
			return;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (i > 0 && !vis[i - 1] && str[i - 1] == str[i]) continue;
			if (vis[i] == 0)
			{
				vis[i] = 1;
				permu[cur] = str[i];
				dfs(cur + 1, permu, str);
				vis[i] = 0;
			}
		}
	}
};

class Solution {
public:
	vector<string> Permutation(string str) {
		int len = str.length();
		if (len < 1) return ans;
		sort(str.begin(), str.end());
		this->str = str;
		for (char ch : str) unused[ch]++;
		string permu(len,0);
		dfs(0, permu);
		return ans;
	}
private:
	vector<string> ans;
	string str;
	unordered_map<char, int> unused;
	void dfs(int cur, string& permu )
	{
		if (cur == str.length())
		{
			ans.push_back(permu);
			return;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (i > 0 && str[i - 1] == str[i]) continue;
			if (unused[str[i]] == 0) continue;
			unused[str[i]]--;
			permu[cur] = str[i];
			dfs(cur + 1, permu);
			unused[str[i]]++;;
			
		}
	}
};
int main()
{
	string str = "abc";
	Solution solu;
	vector<string> ans = solu.Permutation(str);
	system("pause");
	return 0;
}
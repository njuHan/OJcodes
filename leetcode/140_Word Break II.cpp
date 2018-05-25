#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		this->s = s;
		this->dict = unordered_set<string>(wordDict.begin(), wordDict.end());
		return dfs(0);
		
	}
private:
	string s;
	unordered_set<string> dict;
	unordered_map<int, vector<string>> cache; //ºó×º´æ´¢
	vector<string> dfs(int cur)
	{
		if (cur == s.length()) return{ "" };
		vector<string> ans;
		for (int i = cur + 1; i <= s.length(); i++)
		{
			string sub = s.substr(cur, i - cur);
			if (dict.count(sub))
			{
				bool find = cache.count(i);
				vector<string>& suffix = cache[i];
				if (find == false)
					suffix = dfs(i);
				for (string str : suffix)
					ans.emplace_back(sub + (str==""? "": (" " + str) ) );
			}
		}
		return ans;
	}
};
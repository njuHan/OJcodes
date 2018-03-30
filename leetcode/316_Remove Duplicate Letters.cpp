
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		int len = s.size();
		if (len < 1) return "";
		vector<int> cnt(26, 0);
		for (int i = 0; i < len; i++) cnt[s[i] - 'a']++;
		int pos = 0;
		/*
		the greedy choice (i.e., the leftmost letter in the answer) is the smallest s[i], 
		s.t. the suffix s[i … ] contains all the unique letters.
		*/
		for (int i = 0; i < len; i++)
		{
			if (s[pos] > s[i]) pos = i;
			if (--cnt[s[i] - 'a'] == 0) break; // s[i]在i最后一次出现
		}
		string right(&s[pos + 1], &s[len]);
		removeCh(right, s[pos]);
		return s.substr(pos,1) + removeDuplicateLetters(right);
	}
	void removeCh(string& str, char ch)
	{
		string::iterator it = str.begin();
		while (it != str.end())
		{
			if (*it == ch)
			{
				it = str.erase(it);
			}
			else it++;
		}
	}
};

int main()
{
	Solution solu;
	
	return 0;
}
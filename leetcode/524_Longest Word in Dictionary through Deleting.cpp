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
using namespace std;


class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		string ans = "";
		for (string str : d)
		{
			int i, j;
			for (i = 0, j = 0; i < s.length() && j < str.length(); i++)
				j += (s[i] == str[j]);
			if (j == str.length() && (ans.length() < str.length() || (ans.length() == str.length() && ans > str)))
				ans = str;
		}
		return ans;
	}
};
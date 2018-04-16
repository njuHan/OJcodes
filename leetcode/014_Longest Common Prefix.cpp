#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<bitset>
#include<stack>
using namespace std;


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int m = strs.size();
		string ans = "";
		if (m < 1) return ans;
		int p = 0;
		while (1)
		{
			char common;
			if (p < strs[0].length())
				common = strs[0][p];
			else
				break;
			int i;
			for (i = 1; i < m; i++)
			{
				if (p >= strs[i].length() || strs[i][p] != common)
					break;
			}
			if (i == m)
				ans.push_back(common);
			else
				break;
			p++;
		}
		return ans;
	}
	string longestCommonPrefix2(vector<string>& strs)
	{
		int pos = 0;
		while (strs.size())
		{
			for (string str : strs)
			{
				if (pos == str.length() || str[pos] != strs[0][pos])
					return strs[0].substr(0, pos);
			}
			pos++;
		}
		return "";
	}
};
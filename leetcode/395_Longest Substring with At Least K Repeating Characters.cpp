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
using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) {
		int n = s.size();
		if (n == 0 || n < k) return 0;
		multiset<char> st(s.begin(), s.end());
		bool badchar = false;
		int pos;
		for (pos = 0; pos < n; pos++)
		{
			if (st.count(s[pos]) < k)
			{
				badchar = true;
				break;
			}
		}
		if (badchar == false) return n;
		int ans = 0;
		size_t begin = 0, end;
		while ((end = s.find_first_of(s[pos],begin))!=string::npos)
		{
			ans = max(ans, longestSubstring(s.substr(begin, end - begin), k));
			begin = end + 1;
		}
		ans = max(ans, longestSubstring(s.substr(begin), k));
		return ans;
	}
};

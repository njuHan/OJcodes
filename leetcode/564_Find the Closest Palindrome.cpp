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

// https://leetcode.com/problems/find-the-closest-palindrome/discuss/102396/C%2B%2B-short-solution-only-need-to-compare-5-numbers/143958
class Solution {
public:
	string nearestPalindromic(string n) {
		//use long long , in case input : "2147483647"
		long long num = stol(n);
		int len = n.length();
		set<long long> st;
		st.insert((long long)pow(10, len) + 1);
		st.insert((long long)pow(10, len - 1) - 1);
		long long prefix = stol(n.substr(0, (len + 1) / 2));
		for (int i = -1; i <= 1; i++)
		{
			string temp = to_string(prefix + i);
			temp += string(temp.rbegin() + (len & 1), temp.rend());
			st.insert(stol(temp));
		}
		st.erase(num);  //not including itself
		long long ans = *st.begin(), mindiff = abs(ans - num);
		for (long long i : st)
		{
			long long diff = abs(num - i);
			if (mindiff > diff)
			{
				ans = i;
				mindiff = diff;
			}
		}
		return to_string(ans);
	}
};
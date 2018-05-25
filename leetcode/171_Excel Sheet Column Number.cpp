#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int ans = 0;
		int base = 1;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			ans += ((s[i] - 'A') + 1)*base;
			base *= 26;
		}
		return ans;
	}
};
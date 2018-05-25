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
	int firstUniqChar(string s) {
		unordered_map<char, int> cnt;
		for (char ch : s)
			cnt[ch]++;
		for (int i=0; i<s.length(); i++)
			if (cnt[s[i]] == 1) return i;
		return -1;
	}
};
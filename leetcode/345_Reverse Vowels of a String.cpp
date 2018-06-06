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
	string reverseVowels(string s) {
		int len = s.length();
		if (len <= 1) return s;
		unordered_set<char> vowels = { 'a','e','i','o','u','A','E','I','O','U' };
		int lo = 0, hi = len - 1;
		while (lo<hi)
		{
			if (vowels.count(s[lo]) == 0) lo++;
			else if (vowels.count(s[hi]) == 0) hi--;
			else swap(s[lo++], s[hi--]);
		}
		return s;
	}
};
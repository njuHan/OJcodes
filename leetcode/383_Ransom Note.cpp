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
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> cnt;
		for (char ch : magazine) cnt[ch]++;
		for (char ch : ransomNote)
			if (!cnt.count(ch) || --cnt[ch] < 0) return false;
		return true;
	}
};
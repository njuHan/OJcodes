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
	bool isAnagram(string s, string t) {
		int len1 = s.length(), len2 = t.length();
		if (len1 != len2) return false;
		cnt = 0;
		for (char ch : s)
		{
			cnt++;
			charCnt[ch]++;
		}
		for (char ch : t)
			if (charCnt[ch]-- > 0) cnt--;
		
		return cnt == 0;
	}
private:
	int cnt;
	unordered_map<char, int> charCnt;
};
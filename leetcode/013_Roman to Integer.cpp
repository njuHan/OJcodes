#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		if (s.length() == 0) return 0;
		unordered_map<char, int> T = { { 'I' , 1 },{ 'V' , 5 },{ 'X' , 10 },{ 'L' , 50 },{ 'C' , 100 },{ 'D' , 500 },{ 'M' , 1000 } };
		int sum = T[s.back()];
		for (int i = s.length() - 2; i >= 0; --i) {
			sum += (T[s[i]] < T[s[i + 1]] ? -T[s[i]] : T[s[i]]);
		}
		return sum;
	}
};
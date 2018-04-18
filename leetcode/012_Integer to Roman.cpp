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
	string intToRoman(int num) {
		vector<string> M = { "", "M", "MM", "MMM" };
		vector<string> C = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		vector<string> X = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		vector<string> I = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
		return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
	}
};
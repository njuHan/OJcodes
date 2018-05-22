#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;

int mod = 1000000007;
class Solution {
public:
	int numDecodings(string s) {
		int n = s.length();
		if (n == 0 || s[0] == '0') return 0;
		long long f0 = 1, f1 = s[0] == '*' ? 9 : 1, f2 = 0; //use long long
		for (int i = 1; i < n; i++)
		{
			long long one = s[i] == '0' ? 0 : (s[i] == '*' ? 9 : 1), two;
			if (s[i - 1] == '*'&& s[i] == '*') two = 15;
			else if (s[i - 1] == '*') two = s[i] <= '6' ? 2 : 1;
			else if (s[i] == '*') two = (s[i - 1] == '1' || s[i - 1] == '2') ? (s[i - 1] == '1' ? 9 : 6) : 0;
			else two = s.substr(i - 1, 2) >= "10" && s.substr(i - 1, 2) <= "26";
			f2 = one*f1 + two*f0;
			f0 = f1;
			f1 = f2%mod;
		}
		return f1;
	}
};
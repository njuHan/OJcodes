#include<iostream>
#include<cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<unordered_map>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string shortestPalindrome(string s) {
		int len = s.length();
		if (len < 1) return s;
		string temp = s + "#" + string(s.rbegin(), s.rend())+"#";
		int n = temp.length();
		vector<int> next(n, -1);
		next[0] = -1;
		int j = -1, i = 0;
		while (i<n-1)
		{
			if (j == -1 || temp[j] == temp[i])
			{
				i++;
				j++;
				next[i] = j;
			}
			else
				j = next[j];
		}
		int pali = next[n - 1];
		string add = s.substr(pali);
		return string(add.rbegin(), add.rend()) + s;
	}
};


int main()
{
	string s = "aacecaaa";
	Solution solu;
	string ans = solu.shortestPalindrome(s);
	system("pause");
	return 0;
}

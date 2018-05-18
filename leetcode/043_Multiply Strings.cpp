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
	string multiply(string num1, string num2) {
		int len1 = num1.length(), len2 = num2.length();
		string ans(len1 + len2, 0);
		for (int i = len1 - 1; i >= 0; i--)
		{
			for (int j = len2 - 1; j >= 0; j--)
			{
				int p1 = len1 - 1 - i, p2 = len2 - 1 - j;
				ans[p1 + p2] += (num1[i] - '0') * (num2[j] - '0');
				ans[p1 + p2 + 1] += ans[p1 + p2] / 10;
				ans[p1 + p2] %= 10;
			}
		}
		//ans == "0"
		while (ans.length()>1 && ans.back()==0)
		{
			ans.pop_back();
		}
		for (auto& e : ans)
			e = e + '0';
		return string(ans.rbegin(), ans.rend());
	}
};
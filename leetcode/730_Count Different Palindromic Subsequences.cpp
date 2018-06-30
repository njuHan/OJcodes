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
#include<sstream>
#include<functional>
using namespace std;

// https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/109514/C++-O(N2)-time-O(N)-memory-with-explanation

class Solution {
public:
	int countPalindromicSubsequences(string S) {
		int n = S.length();
		const int charNum = 4, mod = 1e9 + 7;
		//pre2[c][i],当前长度-2， 首尾为 c，起始为S[i], 的回文序列个数
		vector<vector<int>> pre2(charNum, vector<int>(n, 0));
		vector<vector<int>> pre1(charNum, vector<int>(n, 0));
		vector<vector<int>> cur(charNum, vector<int>(n, 0));
		for (int i = 0; i < n; i++) pre1[S[i] - 'a'][i] = 1;
		for (int len = 2; len <= n; len++)
		{
			for (int i = 0; i <= n - len; i++)
			{
				//提前计算pre2之和
				int sum = 0;
				for (int c = 0; c < charNum; c++)
				{
					sum += pre2[c][i+1];
					sum %= mod;
				}
				for (int c = 0; c < charNum; c++)
				{
					if (S[i] - 'a' != c)
						cur[c][i] = pre1[c][i + 1];
					else if (S[i + len - 1] - 'a' != c)
						cur[c][i] = pre1[c][i];
					else
						cur[c][i] = sum + 2; // add base case : c, cc
				
				}
			}
			pre2 = pre1;
			pre1 = cur;
		}
		int ans = 0;
		for (int c = 0; c < charNum; c++)
		{
			ans += pre1[c][0];
			ans %= mod;
		}
		return ans;
	}
};
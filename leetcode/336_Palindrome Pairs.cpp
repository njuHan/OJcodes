#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
using namespace std;

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> str2idx;
		vector<vector<int>> ans;
		set<vector<int>> tempans;
		int nums = words.size();
		if (nums <= 1) return ans;
		for (int i = 0; i < nums; i++) str2idx[words[i]] = i;
		for (int i = 0; i < nums; i++)
		{
			string word = words[i];
			/*
			The <= in for (int j=0; j<=words[i].length(); j++) is aimed to handle empty string in the input. 
			Consider the test case of [“a”, “”];
			Since we now use <= in for (int j=0; j<=words[i].length(); j++) instead of <. 
			There may be duplicates in the output (consider test case [“abcd”, “dcba”]). 
			Therefore I put a str2.length()!=0 to avoid duplicates.
			*/
			for (int len = 0; len <= word.size(); len++)
			{
				string prefix = word.substr(0, len);
				string suffix = word.substr(len);
				if (isPalin(prefix)) //前缀是回文，只需找到后缀的逆序string
				{
					string target(suffix.rbegin(), suffix.rend());
					// 注意target不能是自己
					if (str2idx.count(target) && str2idx[target]!=i) tempans.insert({ str2idx[target], i });
				}
				if (isPalin(suffix))
				{
					string target(prefix.rbegin(), prefix.rend());
					if (str2idx.count(target) && str2idx[target] != i) tempans.insert({ i, str2idx[target] });
				}
			}
		}
		copy(tempans.begin(), tempans.end(), back_inserter(ans));
		return ans;
	}
private:
	bool isPalin(string s)
	{
		int len = s.size();
		if (len <= 1) return true;
		int i = 0, j = len - 1;
		while (i < j)
			if (s[i++] != s[j--]) return false;
		return true;
	}
};


//参考源码：
class Solution2 {
	bool isPalindrome(const string& s) {
		if (s.empty()) return true;
		for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
			if (s[i] != s[j]) return false;
		}
		return true;
	}
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> res;
		if (words.size() < 2) return res;
		unordered_map<string, int> str2idx;
		for (int i = 0; i < words.size(); ++i) {
			str2idx[words[i]] = i;
		}
		for (int i = 0; i < words.size(); ++i) {
			string word = words[i];
			for (int len = 0; len <= word.size(); ++len) {
				string prefix = word.substr(0, len);
				string suffix = word.substr(len);
				if (isPalindrome(prefix)) {
					string tmp(suffix.rbegin(), suffix.rend());
					if (str2idx.count(tmp) && str2idx[tmp] != i) {
						res.push_back({ str2idx[tmp], i });
					}
				}
				if (isPalindrome(suffix)) {
					string tmp(prefix.rbegin(), prefix.rend());
					if (str2idx.count(tmp) && str2idx[tmp] != i && !suffix.empty()) {
						res.push_back({ i, str2idx[tmp] });
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	
	system("pause");
	return 0;
}
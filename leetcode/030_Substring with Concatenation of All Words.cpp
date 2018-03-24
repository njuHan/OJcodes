#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) 
	{
		vector<int> ans;
		int slen = s.size(), num = words.size();
		if (slen < 1 || num < 1) return ans;
		int wlen = words[0].size();
		if (wlen > slen) return ans;
		unordered_map<string, int> wordNum, wordCnt;
		for (string w : words) wordNum[w]++;
		// 可能同一个单词 被前后两个子串使用 1 2 3 2 1 ，words: 1 2 3
		for (int i = 0; i <= slen - num*wlen; i++)
		{
			wordCnt.clear();
			int j;
			for (j = 0; j < num; j++)
			{
				string w = s.substr(i + j*wlen, wlen);
				if (wordNum.count(w))
				{
					wordCnt[w]++;
					if (wordCnt[w] > wordNum[w])
						break;
				}
				else
					break;
			}
			if (j == num) ans.emplace_back(i);
		}
		return ans;
	}

	// 参考代码：
	vector<int> findSubstring2(string s, vector<string>& words) {
		unordered_map<string, int> counts;
		for (string word : words)
			counts[word]++;
		int n = s.length(), num = words.size(), len = words[0].length();
		vector<int> indexes;
		for (int i = 0; i < n - num * len + 1; i++) {
			unordered_map<string, int> seen;
			int j = 0;
			for (; j < num; j++) {
				string word = s.substr(i + j * len, len);
				if (counts.find(word) != counts.end()) {
					seen[word]++;
					if (seen[word] > counts[word])
						break;
				}
				else break;
			}
			if (j == num) indexes.push_back(i);
		}
		return indexes;
	}
};

int main()
{
	Solution solu;
	
	system("pause");
	return 0;
}
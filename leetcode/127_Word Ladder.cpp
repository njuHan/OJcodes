#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
#include<unordered_set>

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		wordDict = unordered_set<string>(wordList.begin(), wordList.end());
		toVisit.push(beginWord);
        wordDict.erase(beginWord); //入队列时删除，防止重复访问， 环
		cnt = 1;
		while (!toVisit.empty())
		{
			int len = toVisit.size();
			for (int i = 0; i < len; i++)
			{
				string word = toVisit.front(); toVisit.pop();
				if (word == endWord) return cnt;
				addWord(word);
			}
			cnt++;
		}
		return 0;
	}
private:
	int cnt;
	queue<string> toVisit;
	unordered_set<string> wordDict;
	void addWord(string word)
	{
		for (int i = 0; i < word.size(); i++)
		{
			string temp(word);
			for (int j = 0; j < 26; j++)
			{
				temp[i] = j + 'a';
				if (wordDict.count(temp))
				{
					toVisit.push(temp);
					wordDict.erase(temp); //入队列时删除，防止重复访问， 环
				}
			}
		}
	}
};

#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// https://leetcode.com/problems/word-ladder-ii/discuss/40540/88ms!-Accepted-c++-solution-with-two-end-BFS.-68ms-for-Word-Ladder-and-88ms-for-Word-Ladder-II
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end()); //转为set
		unordered_set<string> startWords, endWords; //首尾两端BFS的结点
		startWords.insert(beginWord);
		if (dict.count(endWord)) endWords.insert(endWord);
		unordered_map<string, vector<string>> children; //存储结点便于输出路径
		bool flip = false; //正向反向BFS标志
		vector<vector<string>> ladders;
		vector<string> ladder;
		ladder.push_back(beginWord);
		if (search(startWords, endWords, dict, children, flip))
			getLadders(beginWord, endWord, children, ladder, ladders);
		return ladders;
	}
private:
	bool search(unordered_set<string>& startWords, unordered_set<string>& endWords, 
		unordered_set<string>& dict, unordered_map<string, vector<string>>& children, bool flip)
	{
		if (startWords.empty()) return false;
		if (startWords.size() > endWords.size()) //翻转为BFS搜索较小的集合
			return search(endWords, startWords, dict, children, !flip);
		//删除已经访问的结点
		for (string e : startWords) dict.erase(e);
		for (string e : endWords) dict.erase(e);
		//BFS startWords
		unordered_set<string> nextlayer;
		bool done = false;
		for (string word : startWords)
		{
			int len = word.length();
			for (int i = 0; i < len; i++)
			{
				string temp(word);
				for (int j = 0; j < 26; j++)
				{
					temp[i] = j + 'a';
					if (endWords.count(temp))
					{
						done = true;
						flip ? children[temp].push_back(word) : children[word].push_back(temp);
					}
					else if (!done && dict.count(temp))
					{
						nextlayer.insert(temp);
						flip ? children[temp].push_back(word) : children[word].push_back(temp);
					}
				}
			}
		}
		return done || (search(nextlayer, endWords, dict, children, flip));
	}
	
	void getLadders(string& start, string& end, unordered_map<string, vector<string> >& children,
		vector<string>& ladder, vector<vector<string> >& ladders)
	{
		if (start == end)
		{
			ladders.push_back(ladder);
			return;
		}
		for (string child : children[start])
		{
			ladder.push_back(child);
			getLadders(child, end, children, ladder, ladders);
			ladder.pop_back(); //回溯
		}
	}
};


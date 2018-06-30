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

//Trie method will get MLE
class TrieNode
{
public:
	bool isWord;
	TrieNode* next[26];
	TrieNode(bool b = false) :isWord(b)
	{
		memset(next, 0, sizeof(next));
	}
};

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		dict = unordered_set<string>(words.begin(), words.end());
		root = new TrieNode();
		for (string str : words) insert(str);
		vector<string> ans;
		for (string word : words)
			if (dfs(word, 0) > 1) ans.emplace_back(word);
		deleteNode(root);
		return ans;
	}
private:
	unordered_set<string> dict;
	unordered_map<string, int> cnt;
	TrieNode* root;
	void insert(string word)
	{
		if (word.length() == 0) return; //empty string "" will make root->isWord=1
		TrieNode* p = root;
		for (char ch : word)
		{
			if (p->next[ch - 'a'] == NULL) p->next[ch - 'a'] = new TrieNode();
			p = p->next[ch - 'a'];
		}
		p->isWord = true;
	}
	int dfs(string word, int cur)
	{
		TrieNode* p = root;
		for (int i = cur; i < word.length(); i++)
		{
			if (p->next[word[i]-'a'] == NULL) return 0;
			p = p->next[word[i] - 'a'];
			if (p->isWord)
			{
				int n = dfs(word, i + 1);
				if (n > 0) return 1 + n; //后缀可以分割
			}
		}
		return p->isWord;
	}
	void deleteNode(TrieNode* node)
	{
		for (int i = 0; i < 26; i++)
			if (node->next[i])
				deleteNode(node->next[i]);
		delete node;
	}
};
// https://leetcode.com/problems/concatenated-words/discuss/95654/20-line-C++-169-ms-Beats-100-and-Why-I-think-this-problem-is-not-properly-judged.
class Solution2 {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		if (words.empty()) return{};
		sort(words.begin(), words.end(), [](const string& lhs, const string& rhs) {return lhs.length() < rhs.length(); });
		vector<string> ans;
		minLen = words.front().length();
		minLen = max(1, minLen);
		for (int i = 0; i < words.size(); dict.insert(words[i++]))
			if (words[i].length() >= (minLen << 1) && isValid(words[i])) ans.emplace_back(words[i]);
		return ans;
	}
private:
	unordered_set<string> dict;
	int minLen;
	bool isValid(const string& word)
	{
		if (dict.count(word)) return true;
		int len = word.length();

		for (int i = minLen; i <= len - minLen; i++)
		{
			if (dict.count(word.substr(0, i)) && isValid(word.substr(i, len - i)))
				return true;
		}
		return false;
	}
};
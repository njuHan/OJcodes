#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

const int maxn = 26;
class TrieNode
{
public:
	bool isWord;
	TrieNode* next[maxn];
	string word;
	TrieNode(bool is = false) : isWord(is) { memset(next, 0, sizeof(next)); }
};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		if (board.empty()) return ans;
		root = buid(words);
		m = board.size(); n = board[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (root->next[board[i][j] - 'a'] != NULL) dfs(i, j, root, board);
			}
		}
		return ans;
	}
private:
	vector<string> ans;
	TrieNode* root;
	int m, n;
	TrieNode* buid(vector<string>& words)
	{
		TrieNode* root = new TrieNode();
		for (string word : words)
		{
			TrieNode* p = root;
			for (int i = 0; i < word.length(); i++)
			{
				if (p->next[word[i] - 'a'] == NULL) p->next[word[i] - 'a'] = new TrieNode();
				p = p->next[word[i] - 'a'];
			}
			p->isWord = true;
			p->word = word;
		}
		return root;
	}
	//cur i, j, pre node
	void dfs(int i, int j, TrieNode* node, vector<vector<char>>& board)
	{
		TrieNode* curnode;
		if (i < 0 || j < 0 || i >= m || j >= n || board[i][j]=='#' || (curnode = node->next[board[i][j] - 'a']) == NULL) return;
		if (curnode->isWord)
		{
			ans.emplace_back(curnode->word);
			curnode->isWord = false; //de-duplicate
		}
		char temp = board[i][j];
		board[i][j] = '#';
		dfs(i - 1, j, curnode, board);
		dfs(i + 1, j, curnode, board);
		dfs(i, j - 1, curnode, board);
		dfs(i, j + 1, curnode, board);
		board[i][j] = temp;
	}
};
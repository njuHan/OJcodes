#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

class TrieNode
{
public:
	bool isWord;
	TrieNode* next[26];
	TrieNode(bool b=false) :isWord(b) 
	{
		memset(next, 0, sizeof(next)); //set to NULL
	}
};

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode(false);
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (p->next[word[i] - 'a'] == NULL)
				p->next[word[i] - 'a'] = new TrieNode(false);
			p = p->next[word[i] - 'a'];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* p = find(word);
		return  p!= NULL && p->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return find(prefix) != NULL;
	}
	~Trie()
	{
		deleteNode(this->root);
	}
private:
	TrieNode* root;
	TrieNode* find(string key)
	{
		TrieNode* p = root;
		for (int i = 0; i < key.size() && p != NULL; i++)
		{
			p = p->next[key[i] - 'a'];
		}
		return p;
	}
	void deleteNode(TrieNode* node)
	{
		for (int i = 0; i < 26; i++)
			if (node->next[i])
				deleteNode(node->next[i]);
		delete node;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/

int main()
{

	system("pause");
	return 0;
}
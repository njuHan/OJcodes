#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

const int maxn = 26;

struct TrieNode
{
	TrieNode* next[maxn];
	bool isWord;
	TrieNode(bool isw = false) :isWord(isw) { memset(next, 0, sizeof(next)); }
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode(false);
	}
	~WordDictionary()
	{
		deleteTree(root);
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (p->next[word[i] - 'a'] == NULL)
				p->next[word[i] - 'a'] = new TrieNode();
			p = p->next[word[i] - 'a'];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return find(root, word);
	}
private:
	TrieNode* root;
	bool find(TrieNode* p, string key)
	{
		if (p == NULL) return false;
		if (key.size() == 0) return p->isWord;
		bool ans = false;
		if (key[0] == '.')
		{
			for (int i = 0; i < maxn; i++)
			{
				if (p->next[i])
					ans = ans || find(p->next[i], string(&key[1]));
				if (ans)
					break;
			}
		}
		else
			ans = find(p->next[key[0] - 'a'], string(&key[1]));
		return ans;
		
	}
	void deleteTree(TrieNode* node)
	{
		if (node == NULL) return;
		for (int i = 0; i < maxn; i++)
			if (node->next[i])
				deleteTree(node->next[i]);
		delete node;
	}
};
int main()
{
	
	system("pause");
	return 0;
}




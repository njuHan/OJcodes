struct TrieNode
{
	TrieNode* next[26];
	int val;
	TrieNode(int v = 0):val(v) { memset(next, 0, sizeof(next)); }
};

class MapSum {
public:
	/** Initialize your data structure here. */
	MapSum() {
		root = new TrieNode();
	}

	void insert(string key, int val) {
		TrieNode* p = root;
		for (int i = 0; i < key.length(); i++)
		{
			if (p->next[key[i] - 'a'] == NULL) p->next[key[i] - 'a'] = new TrieNode();
			p = p->next[key[i] - 'a'];
		}
		p->val = val;
	}

	int sum(string prefix) {
		int ans = 0;
		TrieNode* p = root;
		for (int i = 0; i < prefix.length() && p; i++)
			p = p->next[prefix[i] - 'a'];
		dfs(p, ans);
		return ans;
	}
	~MapSum()
	{
		deleteNode(root);
	}
private:
	TrieNode* root;
	void deleteNode(TrieNode* node)
	{
		for (int i = 0; i < 26; i++)
			if (node->next[i]) deleteNode(node->next[i]);
		delete node;
	}
	void dfs(TrieNode* node, int& sum)
	{
		if (!node) return;
		sum += node->val;
		for (int i = 0; i < 26; i++) dfs(node->next[i], sum);
	}
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
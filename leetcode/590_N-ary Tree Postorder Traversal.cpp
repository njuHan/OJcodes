#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
#include<functional>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
class Solution {
public:
	vector<int> postorder(Node* root) {
		dfs(root);
		return ans;
	}
private:
	vector<int> ans;
	void dfs(Node* node)
	{
		if (!node) return;
		for (int i = 0; i < node->children.size(); i++)
			dfs(node->children[i]);
		ans.emplace_back(node->val);
	}
};

class Solution2 {
public:
	vector<int> postorder(Node* root) {
		vector<int> ans;
		stack<Node*> sk;
		sk.push(root);
		while (!sk.empty())
		{
			Node* node = sk.top(); sk.pop();
			if (!node) continue;
			ans.emplace_back(node->val);
			for (Node* & p : node->children) sk.push(p);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* pruneTree(TreeNode* root) {
		isDelete(root);
		return root;
	}
private:
	bool isDelete(TreeNode* node)
	{
		if (!node) return true;
		bool left = isDelete(node->left), right = isDelete(node->right);
		if (left) node->left = NULL;
		if (right) node->right = NULL;
		return node->val == 0 && left && right;
	}
};
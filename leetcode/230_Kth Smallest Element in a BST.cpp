#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> sk;
		while (root || !sk.empty())
		{
			while (root)
			{
				sk.push(root);
				root = root->left;
			}
			root = sk.top(); sk.pop();
			if (--k == 0) return root->val;
			root = root->right;
		}
	}
};
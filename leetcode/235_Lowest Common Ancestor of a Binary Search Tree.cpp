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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val > q->val) swap(p, q); // let p->val <= q->val
		while (root)
		{
			if (p->val <= root->val && root->val <= q->val)
				break;
			else if (p->val < root->val && q->val < root->val)
				root = root->left;
			else
				root = root->right;
		}
		return root;
	}
};
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

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (root->val < p->val && root->val<q->val) return lowestCommonAncestor(root->right, p, q);
        if (root->val > p->val && root->val>q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val > q->val) swap(p, q); // let p->val <= q->val
		while (root)
		{
			if (p->val <= root->val && root->val <= q->val)
				break;
			else if (q->val < root->val)
				root = root->left;
			else
				root = root->right;
		}
		return root;
	}
};
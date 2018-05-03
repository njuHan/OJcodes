#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL) return false;
		sum -= root->val;
		if (root->left == NULL && root->right == NULL && sum == 0) return true;
		return hasPathSum(root->left, sum) ||  hasPathSum(root->right, sum);
	}
};
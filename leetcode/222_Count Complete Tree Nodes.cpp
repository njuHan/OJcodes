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
	int countNodes(TreeNode* root) {
		if (!root) return 0;
		int ld = 0, rd = 0;
		for (TreeNode* p = root; p; p = p->left) ld++;
		for (TreeNode* p = root; p; p = p->right) rd++;
		if (ld == rd)
			return (1 << ld) - 1;
		else
			return 1 + countNodes(root->left) + countNodes(root->right);
	}

};
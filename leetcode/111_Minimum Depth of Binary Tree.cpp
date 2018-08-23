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
/*
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
*/


class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		// 不能直接return min(left, right) + 1; 这样会返回非叶结点的深度
		return root->left && root->right?  min(left, right) + 1 : left+right+1;
	}
};
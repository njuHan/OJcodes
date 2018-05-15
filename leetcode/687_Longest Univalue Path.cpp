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
	int longestUnivaluePath(TreeNode* root) {
		maxp = 0;
		getdep(root);
		return maxp;
	}
private:
	int maxp;
	int getdep(TreeNode* node)
	{
		if (!node) return 0;
		int left = getdep(node->left); 
		int right = getdep(node->right);
		if (node->left != NULL && node->left->val != node->val)
			left = 0;  //左边和node结点相同的最长路径结点个数，不包括node
		if (node->right != NULL && node->right->val != node->val)
			right = 0;
		maxp = max(maxp, left + right);
		return max(left, right) + 1; // +1 node 结点
	}
};
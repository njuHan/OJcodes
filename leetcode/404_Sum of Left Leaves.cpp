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
	int sumOfLeftLeaves(TreeNode* root) {
		sum = 0;
		if (!root) return sum;
		getSum(root->left, 1);
		getSum(root->right, 0);
		return sum;
	}
private:
	int sum;
	void getSum(TreeNode* node, bool isLeft)
	{
		if (!node) return;
		if (!node->left && !node->right) sum += isLeft ? node->val : 0;
		getSum(node->left, 1);
		getSum(node->right, 0);
	}
};
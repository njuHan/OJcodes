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
	bool isBalanced(TreeNode* root) {
		int ht = 0;
		return depth(root, ht);
	}
private:
	bool depth(TreeNode* node, int& ht)
	{
		if (node == NULL) 
		{
			ht = 0;
			return true;
		}
		int l, r;
		if (!depth(node->left, l) || !depth(node->right, r))
			return false;
		else if (abs(l - r) > 1)
			return false;
		else
		{
			ht = max(l, r) + 1;
			return true;
		}
	}
};
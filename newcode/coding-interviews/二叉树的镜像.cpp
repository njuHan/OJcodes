/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL) return;
		swap(pRoot->left, pRoot->right);
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
	//非递归
	void Mirror2(TreeNode *pRoot) {
		if (pRoot == NULL) return;
		stack<TreeNode*> sk;
		sk.push(pRoot);
		while (!sk.empty())
		{
			TreeNode* node = sk.top(); sk.pop();
			if (node->left || node->right)
				swap(node->left, node->right);
			if (node->left) sk.push(node->left);
			if (node->right) sk.push(node->right);
		}
	}
};
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
};
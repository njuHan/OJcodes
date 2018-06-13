/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
// 注意这题问的是子结构，不是子树，不需要完全子树匹配。。。。。。。。。。。。。。。。。。。。。
//和leetcode572 不一样
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL) return false;
		return isSame(pRoot1, pRoot2) ||  (pRoot1 && (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2)) );
	}
private:
	bool isSame(TreeNode* lhs, TreeNode* rhs)
	{
		if (!rhs) return true;
		if (!lhs) return false;
		return (lhs->val == rhs->val) && isSame(lhs->left, rhs->left) && isSame(lhs->right, rhs->right);

	}
};
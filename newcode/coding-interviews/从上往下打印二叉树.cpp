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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> que;
		vector<int> ans;
		if (root == NULL) return ans;
		que.push(root);
		while (!que.empty())
		{
			int m = que.size();
			while (m--)
			{
				TreeNode* p = que.front(); que.pop();
				ans.emplace_back(p->val);
				if (p->left) que.push(p->left);
				if (p->right) que.push(p->right);
			}
		}
		return ans;
    }
};
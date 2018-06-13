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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		this->target = expectNumber;
		if (root == NULL) return ans;
		vector<int> vec;
		dfs(root, vec, 0);
		return ans;
	}
private:
	vector<vector<int>> ans;
	int target;
	void dfs(TreeNode* p, vector<int>& vec, int sum)
	{
		vec.emplace_back(p->val);
		sum += p->val;
		if (!p->left && !p->right && sum == target) ans.push_back(vec);
		if (p->left) dfs(p->left, vec, sum);
		if (p->right) dfs(p->right, vec, sum);
		vec.pop_back();
		sum -= p->val;
	}

};
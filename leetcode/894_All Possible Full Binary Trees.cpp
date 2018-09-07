struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> allPossibleFBT(int N) {
		if (N & 1 == 0 || N < 1) return {}; // even
		if (N == 1) return vector<TreeNode*>{ new TreeNode(0) };
		if (cache.count(N)) return cache[N];
		vector<TreeNode*> ans;
		for (int i = 2; i < N; i += 2)
		{
			TreeNode* root = new TreeNode(0);
			for (auto left : allPossibleFBT(i-1))
				for (auto right : allPossibleFBT(N - i))
				{
					root->left = left;
					root->right = right;
					ans.push_back(root);
				}
		}
		return cache[N] = ans;
	}
private:
	unordered_map<int, vector<TreeNode*>> cache;
};
#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	vector<vector<string>> printTree(TreeNode* root) {
		if (!root) return ans;
		m = getHeight(root);
		ans = vector<vector<string>>(m, vector<string>((1 << m) - 1, ""));
		getAns(root, 1,  0);
		return ans;
	}
private:
	vector<vector<string>> ans;
	int m;
	int getHeight(TreeNode* node)
	{
		if (!node) return 0;
		int l = getHeight(node->left);
		int r = getHeight(node->right);
		return max(l, r) + 1;
	}
	// root level is 1;
	void getAns(TreeNode* node, int level, int start)
	{
		if (node == NULL) return;
		int subWidth = (1 << (m - level)) - 1;
		ans[level-1][start + subWidth] = to_string(node->val);
		getAns(node->left, level + 1, start);
		getAns(node->right, level + 1, start + subWidth + 1);
	}
};
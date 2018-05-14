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


int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		ans = 0;
		dfs(root, 1, 0);
		return ans;
	}
private:
	vector<int> lefts;
	int ans;
	void dfs(TreeNode* node, int id, int dep)
	{
		if (!node) return;
		if (dep >= lefts.size()) lefts.push_back(id);
		ans = max(ans, id - lefts[dep] + 1);
		dfs(node->left, id << 1, dep + 1);
		dfs(node->right, (id << 1) + 1, dep + 1);
	}
};
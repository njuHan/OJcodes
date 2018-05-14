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


static int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int findSecondMinimumValue(TreeNode* root) {
		minval = root->val;
		return find(root);
	}
private:
	int minval;
	int find(TreeNode* node)
	{
		if (!node) return -1;
		if (node->val != minval) return node->val;
		int left = find(node->left), right = find(node->right);
		return left == -1 ? right : (right == -1 ? left : min(left, right));
	}
};
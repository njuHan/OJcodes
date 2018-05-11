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
	int findTilt(TreeNode* root) {
		ans = 0;
		get(root);
		return ans;
	}
private:
	int ans;
	int get(TreeNode* root) {
		if (root == NULL) return 0;
		int left = get(root->left);
		int right = get(root->right);
		int add = left - right;
		add = add < 0 ? -add : add;
		ans += add;
		return left + right + root->val;
	}
};
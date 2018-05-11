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
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d < 1) return NULL;
		if (d == 1)
		{
			TreeNode* node = new TreeNode(v);
			node->left = root;
			return node;
		}
		int cnt = d - 2;
		queue<TreeNode*> que;
		if(root) que.push(root);
		while (cnt>0 && !que.empty())
		{
			int m = que.size();
			while (m--)
			{
				TreeNode* node = que.front(); que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			cnt--;
		}
		if (cnt != 0 || que.empty()) return root;
		while (!que.empty())
		{
			TreeNode* node = que.front(); que.pop();
			TreeNode* left = new TreeNode(v), *right = new TreeNode(v);
			left->left = node->left;
			node->left = left;
			right->right = node->right;
			node->right = right;
		}
		return root;
	}
};
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL) return ans;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			int m = que.size();
			vector<int> level;
			while (m--)
			{
				TreeNode* node = que.front(); que.pop();
				level.push_back(node->val);

				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}

			ans.push_back(level);
		}
		return vector<vector<int>>(ans.rbegin(), ans.rend());
	}
};
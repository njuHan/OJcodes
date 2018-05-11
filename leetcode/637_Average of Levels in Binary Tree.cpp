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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ans;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			int m = que.size();
			double sum = 0.0;
			for (int i = 0; i < m; i++)
			{
				TreeNode* node = que.front(); que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
				sum += node->val;
			}
			ans.push_back(sum / m);
		}
		return ans;
	}
};
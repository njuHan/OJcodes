#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

int x = []()
{     
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int> ans;
		if (!root) return ans;
		queue<TreeNode*> que;
		que.push(root);
		TreeNode* node;
		while (!que.empty())
		{
			int max = que.front()->val;
			int m = que.size();
			while (m--)
			{
				node = que.front(); que.pop();
				max = max < node->val ? node->val : max;
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			ans.push_back(max);
		}
		return ans;
	}
};
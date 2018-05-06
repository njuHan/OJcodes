#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;
/*
int x = []()
{     
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		que.push(root);
		TreeNode* leftMost;
		while (!que.empty())
		{
			int m = que.size();
			TreeNode* node;
			leftMost = que.front();
			while (m--)
			{
				node = que.front(); que.pop();
				if (node->left)  que.push(node->left);
				if (node->right)  que.push(node->right); 
			}
		}
		return leftMost->val;
	}
};
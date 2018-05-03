#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
	{
		vector<vector<int>> ans;
		if (!root) return ans;
		bool flag = 0;
		stack<TreeNode*> sk, tempsk;
		sk.push(root);
		while (!sk.empty())
		{
			int m = sk.size();
			vector<int> level;
			while (m--)
			{
				TreeNode* node = sk.top(); sk.pop();
				level.push_back(node->val);
				if (!flag)
				{
					if (node->left) tempsk.push(node->left);
					if (node->right) tempsk.push(node->right);
				}
				else
				{
					if (node->right) tempsk.push(node->right);
					if (node->left) tempsk.push(node->left);
				}
			}
			swap(tempsk, sk);
			ans.push_back(level);
			flag = !flag;
		}
		return ans;
	}
};
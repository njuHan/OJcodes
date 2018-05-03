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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (root == NULL) return ans;
		stack<TreeNode*> sk;
		TreeNode* curNode = root, *lastNode = NULL;
		while (curNode || !sk.empty())
		{
			if (curNode)
			{
				sk.push(curNode);
				curNode = curNode->left;
			}
			else
			{
				TreeNode* node = sk.top();
				if (node->right && node->right != lastNode)
				{
					curNode = node->right;
				}
				else
				{
					ans.push_back(node->val);
					lastNode = node;
					sk.pop();
				}
			}
		}
		return ans;
	}
};

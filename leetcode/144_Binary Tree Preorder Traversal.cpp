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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		TreeNode* pre, *cur = root;
		while (cur)
		{
			if (cur->left == NULL)
			{
				ans.push_back(cur->val);
				cur = cur->right;
			}
			else
			{
				pre = cur->left;
				while (pre->right != NULL && pre->right != cur) pre = pre->right;
				if (pre->right == NULL)
				{
					pre->right = cur;
					ans.push_back(cur->val);
					cur = cur->left;
				}
				else
				{
					pre->right = NULL;
					cur = cur->right;
				}
			}
		}
		return ans;
	}
};
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> sk;
        while(root || !sk.empty())
        {
            while(root) 
            {
                sk.push(root);
                ans.emplace_back(root->val);
                root = root->left;
            }
            TreeNode* node = sk.top(); sk.pop();
            root = node->right;
        }
        return ans;
    }
};
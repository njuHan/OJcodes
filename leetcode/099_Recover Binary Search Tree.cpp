#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recoverTree(TreeNode* root) {
		TreeNode* pre, *cur = root;
		TreeNode* node1 = NULL, *node2 = NULL, *inorderpre = NULL;
		while (cur)
		{
			if (cur->left != NULL)
			{
				pre = cur->left;
				while (pre->right != NULL && pre->right != cur)
				{
					pre = pre->right;
				}
				if (pre->right == NULL)
				{
					pre->right = cur;
					cur = cur->left;
				}
				if (pre->right == cur)
				{
					pre->right = NULL;
					cout << cur->val << ",";
					if (inorderpre && node1 == NULL && inorderpre->val > cur->val)
						node1 = inorderpre;
					if (inorderpre && cur->val < inorderpre->val)
						node2 = cur;
					inorderpre = cur;

					cur = cur->right;
				}
			}
			else
			{
				cout << cur->val << ",";
				if (inorderpre && node1 == NULL && inorderpre->val > cur->val)
					node1 = inorderpre;
				if (inorderpre && cur->val < inorderpre->val)
					node2 = cur;
				inorderpre = cur;

				cur = cur->right;
			}
		}
		int temp = node1->val;
		node1->val = node2->val;
		node2->val = temp;
	}
};
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<ctime>
using namespace std;



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k < 1) return NULL;
		TreeNode* pre = NULL, *cur = pRoot;
		while (cur)
		{
			if (cur->left == NULL)
			{
				if (--k == 0) return cur;
				cur = cur->right;
			}
			else
			{
				pre = cur->left;
				while (pre->right != NULL && pre->right != cur) pre = pre->right;
				if (pre->right == NULL)
				{
					pre->right = cur;
					cur = cur->left;
				}
				else
				{
					pre->right = NULL;
					if (--k == 0) return cur;
					cur = cur->right;
				}
			}
		}
		return NULL;
	}


};

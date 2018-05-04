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

//Morris traversal
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		cur = root;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return cur != NULL;
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* pre = NULL;
		int val = 0;
		while (cur)
		{
			if (cur->left == NULL)
			{
				val = cur->val;
				cur = cur->right;
				break;
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
					val = cur->val;
					cur = cur->right;
					break;
				}
			}
		}
		return val;
	}
private:
	TreeNode* cur;
};


// stack method
class BSTIterator2 {
public:
	BSTIterator2(TreeNode *root) {
		while (root)
		{
			sk.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !sk.empty();
	}

	/** @return the next smallest number */
	int next() {
		if (!hasNext()) return -1;
		TreeNode* top = sk.top(); sk.pop();
		TreeNode* cur = top->right;
		while (cur)
		{
			sk.push(cur);
			cur = cur->left;
		}
		return top->val;
	}
private:
	stack<TreeNode*> sk;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/
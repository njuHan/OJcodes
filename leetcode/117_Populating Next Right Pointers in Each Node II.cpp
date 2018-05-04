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


struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
	void connect2(TreeLinkNode *root) {
		if (!root) return;
		queue<TreeLinkNode*> que;
		que.push(root);
		while (!que.empty())
		{
			int m = que.size();
			while (m--)
			{
				TreeLinkNode* node = que.front(); que.pop();
				if (m == 0)
					node->next = NULL;
				else
					node->next = que.front();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
	}

	//O(1) space
	void connect(TreeLinkNode *root)
	{
		TreeLinkNode* head = root, temp = TreeLinkNode(0);
		while (head)
		{
			TreeLinkNode* parent = head, *child = &temp;
			while (parent)
			{
				if (parent->left) child = child->next = parent->left;
				if (parent->right) child = child->next = parent->right;
				parent = parent->next;
			}
			child->next = NULL;
			head = temp.next;
		}
	}
	
};
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>


struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

using namespace std;
class Solution {
public:
	void connect(TreeLinkNode *root) {
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
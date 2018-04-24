#include<iostream>
#include<cstdio>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL) return NULL;
		TreeLinkNode* ans = NULL;
		if (pNode->right)
		{
			ans = pNode->right;
			while (ans->left)
			{
				ans = ans->left;
			}
		}
		else if (pNode->next)
		{
			ans = pNode->next;
			TreeLinkNode* son = pNode;
			while (ans && ans->right == son)
			{
				son = ans;
				ans = ans->next;
			}
		}
		return ans;
	}
};
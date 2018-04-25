#include<iostream>
#include<cstdio>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return new TreeNode(head->val);
		ListNode* fast = head->next->next, *head2 = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			head2 = head2->next;
		}
		TreeNode* root = new TreeNode(head2->next->val);
		ListNode* temp = head2;
		head2 = head2->next->next;
		temp->next = NULL;
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(head2);
		return root;
	}
};
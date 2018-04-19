#include<iostream>
#include<cstdio>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		for (ListNode** pp = &head; *pp && (*pp)->next; )
		{
			ListNode* next = (*pp)->next;
			if ((*pp)->val == next->val)
			{
				(*pp)->next = next->next;
				delete next;
			}
			else
				pp = &(*pp)->next;
		}
		return head;
	}
};
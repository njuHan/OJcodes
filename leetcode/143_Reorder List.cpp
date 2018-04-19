#include<iostream>
#include<cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<unordered_map>
using namespace std;




struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL) return;
		//要使得slow指向前一半链表的尾巴
		ListNode* fast = head->next, *slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		if (slow==head) return;
		ListNode* head2 = slow->next;
		slow->next = NULL;  //两半链表分离
		reverse(&head2);
		ListNode* p1 = head, *p2 = head2;
		while (p1 && p2)
		{
			ListNode* temp = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p2 = temp;
			p1 = p1->next->next;
		}
	}
private:
	void reverse(ListNode** phead)
	{
		if (*phead == NULL || (*phead)->next==NULL) return;
		ListNode* pivot = *phead;
		while (pivot->next)
		{
			ListNode* next = pivot->next;
			pivot->next = next->next;
			next->next = *phead;
			*phead = next;
		}
	}
};
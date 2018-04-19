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
	//循环链表法
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) return head;
		int nodenum = 1;
		ListNode* tail;
		for ( tail = head; tail->next; tail = tail->next)
			nodenum++;
		
		if ( (k = k%nodenum) == 0) return head;
		int cnt = nodenum - k;
		tail->next = head;
		while (cnt-->0)
		{
			tail = tail->next;
		}
		ListNode* newhead = tail->next;
		tail->next = NULL;
		return newhead;
		
	}
	//逐次翻转法
	ListNode* rotateRight2(ListNode* head, int k) {
		int nodenum = 0;
		for (ListNode* temp = head; temp; temp = temp->next)
			nodenum++;
		if (head == NULL || (k = k%nodenum) == 0) return head;
		while (k-->0)
		{
			rotateRight(&head);
		}
		return head;
	}
private:
	void rotateRight(ListNode** phead)
	{
		ListNode* last = *phead;
		while (last->next->next != NULL) last = last->next;
		ListNode* next = last->next;
		last->next = NULL;
		next->next = *phead;
		*phead = next;
	}
};
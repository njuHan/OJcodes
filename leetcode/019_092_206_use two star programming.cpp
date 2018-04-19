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
	ListNode* reverseList(ListNode* head) {
		ListNode** pp = &head;
		ListNode* pivot = *pp;
		while (pivot && pivot->next)
		{
			ListNode* next = pivot->next;
			pivot->next = next->next;
			next->next = *pp;
			*pp = next;
		}
		return head;
	}
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* fast = head;
		ListNode** pp = &head;
		int i;
		for (i = 0; i < n&&fast; i++)
		{
			fast = fast->next;
		}
		if (i != n) return head; //不足n
		while (fast)
		{
			fast = fast->next;
			pp = &((*pp)->next);
		}
		if (*pp)
		{
			ListNode* temp = *pp;
			*pp = temp->next;
			delete temp;
		}
		return head;
	}
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode** pp = &head;
		for (int i = 1; i < m; i++) pp = &((*pp)->next);
		ListNode* pivot = *pp;
		for (int i = 0; i < n - m; i++)
		{
			ListNode* next = pivot->next;
			pivot->next = next->next;
			next->next = *pp;
			*pp = next;
		}
		return head;
	}
};
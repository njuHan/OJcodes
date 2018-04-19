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
	ListNode* deleteDuplicates2(ListNode* head)
	{
		if (head == NULL || head->next == NULL) return head;
		for (ListNode** pp = &head; *pp; )
		{
			ListNode* cur = *pp;
			if (cur->next && cur->val == cur->next->val)
			{
				int val = cur->val;
				while (cur && cur->val == val)
				{
					ListNode* next = cur->next;
					delete cur;
					cur = next;
				}
				*pp = cur;
			}
			else
				pp = &(*pp)->next;
		}
		return head;
	}
	//重复元素全都删除
	ListNode* deleteDuplicates2(ListNode* head)
	{
		if (head == NULL) return head;
		int val;
		bool flag = false;
		for (ListNode** pp = &head; *pp; )
		{
			ListNode* cur = *pp, *next = cur->next;
			if (next && cur->val == next->val)
			{
				val = cur->val;
				flag = true;
				*pp = next->next;
				delete cur;
				delete next;
			}
			else if (flag && cur->val == val)
			{
				*pp = next;
				delete cur;
			}
			else
			{
				pp = &(*pp)->next;
			}
		}
		return head;
	}
	//重复元素只保留一个
	ListNode* deleteDuplicates3(ListNode* head) {
		if (head == NULL) return head;
		int val = head->val;
		for (ListNode** pp = &head->next; *pp; )
		{
			ListNode* entry = *pp;
			if (entry->val == val)
			{
				*pp = entry->next;
				delete entry;
			}
			else
			{
				val = entry->val;
				pp = &((*pp)->next);
			}
		}
		return head;
	}
};
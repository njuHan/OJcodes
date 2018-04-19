#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<assert.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		reverseK(&head, k);
		return head;
	}
private:
	void reverseK(ListNode** head, int k)
	{
		if (k == 1 || *head == NULL) return;
		ListNode** pp = head, **nextpp = &((*head)->next);
		ListNode* todo = *head, *nexthead = *head;
		int cnt = k;
		while (cnt>0 && nexthead!=NULL)
		{
			cnt--;
			nexthead = nexthead->next;
		}
		if (cnt > 0) return; //不足k，不反转
		*pp = nexthead;  //这句别忘了
		while (todo!=nexthead)
		{
			ListNode* next = todo->next;
			todo->next = *pp;
			*pp = todo;
			todo = next;
		}
		reverseK(nextpp, k);
		return;
	}
};
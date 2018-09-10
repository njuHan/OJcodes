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

//每隔n个元素反转， n=k
void reverseN(ListNode** head, int k) //必须使用指针的指针
{
	if (k == 1 || *head == NULL) return;
	ListNode** pp = head, **ppnext = &((*head)->next);
	ListNode* nexthead = *head;
	int cnt = k;
	while (cnt>0 && nexthead != NULL)
	{
		cnt--;
		nexthead = nexthead->next;
	}
	ListNode* todo = *pp;
	*pp = nexthead;
	while (todo != nexthead)
	{
		ListNode* next = todo->next;
		todo->next = *pp;
		*pp = todo;
		todo = next;
	}
	reverseN(ppnext, k);
	return;
}

void printNode(ListNode* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return;
}

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(6);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	reverseN(&node1, 2);
	printNode(node1);
	system("pause");
	return 0;
}

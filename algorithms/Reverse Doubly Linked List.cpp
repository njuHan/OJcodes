#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<set>
using namespace std;

struct ListNode
{
	int val;
	ListNode* pre, *next;
	ListNode(int _val = 0,ListNode* _pre = 0, ListNode* _next = 0):val(_val), pre(_pre), next(_next){}
};

void printNode(ListNode* head)
{
	ListNode* p = head;
	while (p->next)
	{
		cout << p->val;
		p = p->next;
	}
	cout << endl;
	while (p)
	{
		cout << p->val;
		p = p->pre;
	}
	cout << "---------" << endl;
}
ListNode* reverse(ListNode* head)
{
	ListNode* p = head, *pre = NULL;
	while (p)
	{
		ListNode* next = p->next;
		// 反转p 的两个指针 
		p->next = pre;
		p->pre = next;
		pre = p;
		p = next;
	}
	return pre;
}

void reverse(ListNode** phead)
{
	ListNode* pivot = *phead;
	while (pivot && pivot->next)
	{
		ListNode* next = pivot->next;
		pivot->next = next->next;
		// 这里本质上也是反转 next 的两个指针 
		// 但是 next 的上一个结点需要在下一轮循环才知道（需要先next->pre=NULL, 防止没有下一轮），
		next->next = *phead; next->pre = NULL;
		(*phead)->pre = next;  //到了下一轮，把 (*phead)->pre 设置成当前的 next
		*phead = next;
	}
}

int main()
{	
	ListNode* node0, *node1, *node2, *node3;
	node0 = new ListNode(0);
	node1 = new ListNode(1);
	node2 = new ListNode(2);
	node3 = new ListNode(3);
	node0->next = node1, node1->next = node2, node2->next = node3, node3->next = 0;
	node3->pre = node2, node2->pre = node1, node1->pre = node0, node0->pre = 0;
	ListNode* p1 = reverse(node0);
	printNode(p1);

	reverse(&p1);
	printNode(p1);

	system("pause");
	return 0;
}
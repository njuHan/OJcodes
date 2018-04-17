#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode**pp = &head;
		ListNode* a, *b;
		while ((a = *pp) && (b = a->next))
		{
			a->next = b->next;
			b->next = a;
			*pp = b;
			pp = &(a->next);
		}
		return head;
	}
	ListNode* remove(ListNode* head, int x)
	{
		ListNode** pp = &head;
		while (*pp)
		{
			ListNode* node = *pp;
			if (node->val == x)
			{
				*pp = node->next;
				//delete node;
			}
			else
				pp = &node->next;
		}
		return head;
	}
};

void printNode(ListNode* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
}

int main()
{
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);
	ListNode node6(6);
	node1.next = &node2; 
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	

	Solution solu;
	ListNode* head = solu.remove(&node1, 3);
	printNode(head);
	system("pause");
	return 0;
}


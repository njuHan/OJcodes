#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2;
		while (l1)
		{
			s1.push(l1->val);
			l1 = l1->next;
		}
		while (l2)
		{
			s2.push(l2->val);
			l2 = l2->next;
		}
		int more = 0;
		ListNode head(0);
		ListNode* p = &head;
		while (!s1.empty() || !s2.empty())
		{
			int sum = 0;
			if (!s1.empty()) { sum += s1.top(); s1.pop(); }
			if (!s2.empty()) { sum += s2.top(); s2.pop(); }
			sum += more;
			more = sum / 10;
			sum = sum % 10;
			ListNode* next = p->next;
			p->next = new ListNode(sum);
			p->next->next = next;
		}
		if (more)
		{
			ListNode* next = p->next;
			p->next = new ListNode(more);
			p->next->next = next;
		}
		return p->next;
	}
};

int main()
{
	ListNode a1(7);
	ListNode a2(2);
	ListNode a3(4);
	ListNode a4(3);

	ListNode a5(5);
	ListNode a6(6);
	ListNode a7(4);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;

	a5.next = &a6;
	a6.next = &a7;

	Solution solu;
	ListNode* ans = solu.addTwoNumbers(&a1, &a5);
	system("pause");
	return 0;
}
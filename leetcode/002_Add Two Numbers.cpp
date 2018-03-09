#include<iostream>
#include<cstdio>
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
		int more = 0;
		ListNode head(0);
		ListNode* tail = &head;
		while (l1 && l2)
		{
			int num = l1->val + l2->val + more;
			more = num / 10;
			num = num % 10;
			tail->next = new ListNode(num);
			tail = tail->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* rest = l1 ? l1 : l2;
		while (rest)
		{
			int num = rest->val + more;
			more = num / 10;
			num = num % 10;
			tail->next = new ListNode(num);
			tail = tail->next;
			rest = rest->next;
		}
		if (more > 0) //注意还有剩余进位
		{
			tail->next = new ListNode(more);
			tail = tail->next;
		}
		return head.next;
	}
};

int main()
{
	ListNode a1(2);
	ListNode a2(4);
	ListNode a3(3);
	ListNode a4(5);
	ListNode a5(6);
	ListNode a6(4);
	a1.next = &a2;
	a2.next = &a3;
	a4.next = &a5;
	a5.next = &a6;

	
	Solution solu;
	ListNode* ans = solu.addTwoNumbers(&a1, &a4);
	system("pause");
	return 0;
}
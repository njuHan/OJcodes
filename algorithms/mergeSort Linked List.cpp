#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* head1, ListNode* head2);
ListNode* sortList(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast && fast->next) //找到链表中间
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode* head2 = slow->next; //第二段链表的头结点
	slow->next = NULL;
	ListNode* ans = merge(sortList(head), sortList(head2));
	return ans;

}

ListNode* merge(ListNode* head1, ListNode* head2)
{
	ListNode temp(0);
	ListNode* tail = &temp;
	tail->next = NULL;
	while (head1 || head2)
	{
		if (head1 && (!head2 || head2->val >= head1->val))
		{
			tail = tail->next = head1;
			head1 = head1->next;
		}
		if (head2 && (!head1 || head1->val >= head2->val))
		{
			tail = tail->next = head2;
			head2 = head2->next;
		}
	}
	tail->next = NULL;
	return temp.next;
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
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(5);
	ListNode* node4 = new ListNode(2);
	ListNode* node5 = new ListNode(4);
	ListNode* node6 = new ListNode(6);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	ListNode* ans = sortList(node1);
	printNode(ans);
	system("pause");
	return 0;
}
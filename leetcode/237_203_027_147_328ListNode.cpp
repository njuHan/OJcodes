#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* next = node->next;
		ListNode* pre;
		while (next)
		{
			node->val = next->val;
			pre = node;
			node = node->next;
			next = next->next;
		}
		pre->next = NULL;
	}

	ListNode* removeElements(ListNode* head, int val) {
		ListNode temp_head(0);
		temp_head.next = head;
		ListNode* pre = &temp_head, *p = head;
		while (p)
		{
			if (p->val == val)
			{
				pre->next = p->next;
				p = pre->next;
			}
			else
			{
				p = p->next;
				pre = pre->next;
			}
		}
		return temp_head.next;
	}
	int removeElement(vector<int>& nums, int val) 
	{
		int len = nums.size();
		int i = 0;
		while (i < len)
		{
			if (nums[i] == val)
			{
				nums[i] = nums[len - 1];
				len--;
			}
			else
				i++;
		}
		return len;
	}
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head; //注意边界值
		ListNode temp_head(0);
		temp_head.next = head;
		ListNode* pre = head, *cur = head->next;
		while (cur)
		{
			if (cur->val >= pre->val)
			{
				cur = cur->next;
				pre = pre->next;
			}
			else
			{
				pre->next = cur->next;
				ListNode* i = &temp_head, *j = temp_head.next; //注意temp_head的下一个结点会变化
				while (i != pre)
				{
					if (cur->val <= j->val)
					{
						i->next = cur;
						cur->next = j;
						cur = pre->next;
						break;
					}
					i = i->next;
					j = j->next;
				}
			}
		}
		return temp_head.next;
	}
	//结点序号的奇偶，不是val的奇偶
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* odd = head, *even = head->next, *p = head->next->next;
		ListNode* tail[2];
		tail[0] = odd;
		tail[1] = even;
		int i = 0;
		while (p)
		{
			tail[i]->next = p;
			tail[i] = tail[i]->next;
			i ^= 1;
			p = p->next;
		}
		tail[0]->next = even;
		tail[1]->next = NULL;
		return odd;
	}
};
void printList(ListNode* head)
{
	if (!head)
		cout << "NULL" << endl;
	while (head)
	{
		printf("%d %p %p\n", head->val, head, head->next);
		head = head->next;
	}
	printf("------------------\n");
}

int main()
{
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);

	ListNode a5(5);
	ListNode a6(3);
	ListNode a7(4);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;



	Solution solu;
	//solu.deleteNode(&a3);
	printList(&a1);
	ListNode* head = solu.oddEvenList(&a1);
	printList(head);
	system("pause");
	return 0;
}
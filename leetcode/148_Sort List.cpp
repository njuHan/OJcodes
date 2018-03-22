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
	// 递归归并排序，空间复杂度不是O(1)
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
	// 迭代 合并， 空间复杂度O(1)
	ListNode* sortList2(ListNode* head) 
	{
		int cmpSize = 1, sortedSize = 0;
		ListNode tempHead(0);
		ListNode* last = &tempHead;
		last->next = head;
		int len = getLen(head);
		//合并开始的下标， 长度A， 长度B
		int start = 0, lenA, lenB; 
		ListNode* pos, *headA, *headB;
		while (cmpSize<len)
		{
			last = &tempHead; //插入合并链表的地方
			start = 0;  //起始下标，用于判断结束
			pos = tempHead.next; //记录headA起始的地址
			while (start<len)
			{
				lenA = min(cmpSize, len - start);
				lenB = min(cmpSize, len - start - lenA);
				headA = pos;
				//把两个链表拿出来, 链尾NULL
				//更新pos为下一次比较的地方
				for (int i = 0; i < lenA-1; i++) pos = pos->next;
				headB = pos->next;
				pos->next = NULL;
				pos = headB;
				if (lenB > 0) //如果lenB==0，pos = NULL;
				{
					for (int i = 0; i < lenB - 1; i++) pos = pos->next;
					ListNode* temp = pos->next;
					pos->next = NULL;
					pos = temp;
				}
				//合并两个链表
				while (headA || headB)
				{
					if (headA && (!headB || headB->val >= headA->val))
					{
						last = last->next = headA;
						headA = headA->next;
					}
					if (headB && (!headA || headA->val >= headB->val))
					{
						last = last->next = headB;
						headB = headB->next;
					}
				}
				last->next = NULL;
				start += (lenA + lenB);
			}
			cmpSize = cmpSize << 1;
		}
		return tempHead.next;

	}
private:
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

	int getLen(ListNode* node)
	{
		int n = 0;
		while (node)
		{
			n++;
			node = node->next;
		}
		return n;
	}
};

int main()
{

	vector<int> vec = { 100, 4, 200, 1, 3, 2 };

	system("pause");
	return 0;
}
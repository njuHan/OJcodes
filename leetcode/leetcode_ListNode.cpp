#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

// 仿函数
struct cmp
{
	//若A的优先级比B的小，返回true
	bool operator() (const ListNode* A, const ListNode*	B) const
	{
		//val 小的优先级大
		if (A->val > B->val)
			return true;
		return false;
	}
};

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}

};

class Solution
{
public:
	//方法1 原地逆序法
	ListNode* reverseList(ListNode* head)
	{
		ListNode* next, *new_head = NULL;
		while (head)
		{
			next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}
		return new_head;
	}
	//方法2 头插法
	ListNode* reverseList2(ListNode* head)
	{
		ListNode* next;
		ListNode temp_head(0);
		temp_head.next = NULL;
		while (head)
		{
			next = head->next;
			head->next = temp_head.next;
			temp_head.next = head;
			head = next;
		}
		return temp_head.next;
	}

	//使用头插法
	ListNode* reverseMN(ListNode* head, int m, int n)
	{
		ListNode temp_head(0);
		temp_head.next = head;
		ListNode *pre_pm = &temp_head;
		ListNode *pm = head, *pn = head;
		for (int i = m; i > 1; i--)
		{
			pre_pm = pre_pm->next;
			pm = pm->next;
		}
		for (int i = n; i > 1; i--)
			pn = pn->next;
		//最后pn->next会改变，先保存pn->next作为结束标志
		ListNode* next_pn = pn->next;
		pre_pm->next = next_pn;
		while (pm != next_pn)
		{
			ListNode* next = pm->next;
			pm->next = pre_pm->next;
			pre_pm->next = pm;
			pm = next;
		}
		return temp_head.next;
	}
	//原地逆序法
	ListNode* reverseMN2(ListNode* head, int m, int n)
	{
		ListNode temp_head(0);
		temp_head.next = head;
		ListNode* pre_pm = &temp_head;
		ListNode* pm = head, *pn = head, *next_pn;
		for (int i = m; i > 1; i--)
		{
			pm = pm->next;
			pre_pm = pre_pm->next;
		}
		for (int i = n; i > 1; i--)
			pn = pn->next;
		next_pn = pn->next;
		pn->next = NULL;
		while (pm)
		{
			ListNode* next = pm->next;
			pm->next = next_pn;
			next_pn = pm;
			pm = next;
		}
		pre_pm->next = next_pn;

		return temp_head.next;
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode temp_head(0);
		ListNode* cur = &temp_head;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if (l1)
			cur->next = l1;
		if (l2)
			cur->next = l2;
		return temp_head.next;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		int lenA = 0, lenB = 0;
		ListNode* head = headA;
		while (head)
		{
			head = head->next;
			lenA++;
		}
		head = headB;
		while (head)
		{
			head = head->next;
			lenB++;
		}
		int delta = lenA - lenB;
		if (lenA < lenB)
		{
			delta = -delta;
			ListNode* temp = headA;
			headA = headB;
			headB = temp;
		}
		while (delta-->0)
			headA = headA->next;
		while (headA && headB)
		{
			if (headA == headB)
				return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;

	}
	bool hasCycle(ListNode *head)
	{
		ListNode* fast = head, *slow = head;
		while (fast && fast->next && slow)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				return true;
		}
		return false;
	}
	ListNode *detectCycle(ListNode *head)
	{

		ListNode* fast = head, *slow = head, *meet = NULL;
		while (fast && fast->next && slow)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				meet = fast;
				break;
			}
		}
		if (!meet) return meet;
		while (meet != head)
		{
			meet = meet->next;
			head = head->next;
		}
		return meet;
	}
	ListNode* partition(ListNode* head, int x)
	{
		ListNode less_head(0), more_head(0);
		ListNode* less_tail = &less_head, *more_tail = &more_head;
		less_tail->next = more_tail->next = NULL;
		while (head)
		{
			if (head->val < x)
			{
				less_tail->next = head;
				less_tail = head;
			}
			else
			{
				more_tail->next = head;
				more_tail = head;
			}
			head = head->next;
		}
		less_tail->next = more_head.next;
		more_tail->next = NULL;
		return less_head.next;
	}
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		map<RandomListNode*, int> nodeMap;
		vector<RandomListNode*> nodeVec;
		int i = 0;
		RandomListNode* p = head;
		while (p)
		{
			nodeMap[p] = i;
			nodeVec.push_back(new RandomListNode(p->label));
			i++;
			p = p->next;
		}
		i = 0;
		p = head;
		nodeVec.push_back(NULL);
		while (p)
		{
			nodeVec[i]->next = nodeVec[i + 1];
			if (p->random)
				nodeVec[i]->random = nodeVec[nodeMap[p->random]];
			p = p->next;
			i++;
		}
		return nodeVec[0];
	}

	ListNode* mergeKLists2(vector<ListNode*>& lists)
	{
		ListNode temp_head(0);
		temp_head.next = NULL;
		ListNode* tail = &temp_head;
		while (lists.size() > 1)
		{
			vector<ListNode*>::iterator it = lists.begin();
			vector<ListNode*>::iterator minIt = it;
			while (it != lists.end())
			{
				//该链表为空
				if ((*it) == NULL)
				{
					it = lists.erase(it);
				}
				else
				{
					if ((*minIt) == NULL || (*minIt)->val > (*it)->val)
						minIt = it;
					it++;
				}
			}
			if (lists.size()>0)
			{
				tail->next = (*minIt);
				tail = tail->next;
				ListNode* next = (*minIt)->next;
				lists.erase(minIt);
				lists.push_back(next);
			}
		}
		if (lists.size() == 1)
		{
			tail->next = lists[0];
		}

		return temp_head.next;
	}

	//使用优先队列
	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		priority_queue<ListNode*, vector<ListNode* >, cmp> nodeQue;
		vector<ListNode*>::iterator it = lists.begin();
		ListNode temp_head(0);
		ListNode* tail = &temp_head;
		tail->next = NULL;
		while (it != lists.end())
		{
			ListNode* temp = (*it);
			while (temp)
			{
				nodeQue.push(temp);
				temp = temp->next;
			}
			it++;
		}
		while (!nodeQue.empty())
		{
			tail->next = nodeQue.top();
			nodeQue.pop();
			tail = tail->next;
		}
		tail->next = NULL;
		return temp_head.next;
		
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
	ListNode a(1);
	ListNode b(3);
	ListNode c(5);
	ListNode d(7);
	ListNode e(9);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode* head = &a;

	ListNode a1(2);
	ListNode b1(4);
	ListNode c1(6);
	ListNode d1(8);
	ListNode e1(10);
	a1.next = &b1;
	b1.next = &c1;
	c1.next = &d1;
	d1.next = &e1;
	ListNode* head1 = &a1;

	ListNode a2(0);
	ListNode b2(0);
	ListNode c2(20);
	a2.next = &b2;
	b2.next = &c2;
	ListNode* head2 = &a2;

	printList(head);
	printList(head1);
	printList(head2);

	Solution solu;
	vector<ListNode*> lists;
	lists.push_back(head);
	lists.push_back(head1);
	lists.push_back(NULL);
	ListNode* p = solu.mergeKLists(lists);
	printList(p);
	system("pause");
	return 0;
}

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

// reference： https://stackoverflow.com/questions/14805936/optimal-quicksort-for-single-linked-list

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool LEQ(ListNode* lhs, ListNode* rhs)
{
	return lhs->val <= rhs->val;
}

//head, tail, root node's address
void qs(ListNode * hd, ListNode * tl, ListNode ** rtn)
{
	int nlo, nhi;
	ListNode *lo, *hi, *q, *p;

	/* Invariant:  Return head sorted with `tl' appended. */
	while (hd != NULL) {

		nlo = nhi = 0;
		lo = hi = NULL;
		q = hd;
		p = hd->next;

		/* Start optimization for O(n) behavior on sorted and reverse-of-sorted lists */
		//如果是逆序，反转链表
		//如果正序，经过partition 后变为逆序(hi)
		while (p != NULL && LEQ(p, hd)) {
			hd->next = hi;
			hi = hd;
			++nhi;
			hd = p;
			p = p->next;
		}

		/* If entire list was ascending, done. */
		if (p == NULL) {
			*rtn = hd;
			hd->next = hi;
			q->next = tl;
			return;
		}
		/* End optimization.  Can be deleted if desired. */

		/* Partition and count sizes. */
		while (p != NULL) {
			q = p->next;
			if (LEQ(p, hd)) {   //use hd as pivot
				p->next = lo;
				lo = p;
				++nlo;
			}
			else {
				p->next = hi;
				hi = p;
				++nhi;
			}
			p = q;
		}

		/* Recur to establish invariant for sublists of hd,
		choosing shortest list first to limit stack. */
		// lo's sublist ->  hd ->  hi's sublist -> tl(NULL)
		if (nlo < nhi) {
			qs(lo, hd, rtn);
			rtn = &hd->next;  //sublist lo is sorted, next to sort hi
			hd = hi;        /* Eliminated tail-recursive call. */
		}
		else {
			qs(hi, tl, &hd->next);  //先排序较大数的sublist
			tl = hd;       //接下来准备排序小数sublist， 设置 tail = hd, hd = lo
			hd = lo;        /* Eliminated tail-recursive call. */
		}
	}
	/* Base case of recurrence. Invariant is easy here. */
	//when hd == NULL
	*rtn = tl;
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

//rewrite
//head : 待排序链表的头
//tail: 待排序链表最后一个结点的下一个结点
//二级指针 root: *root == 排序后的链表头
void quickSort(ListNode* head, ListNode* tail, ListNode** root)
{
	ListNode *p, *q, *hi, *lo;
	int nhi, nlo;
	while (head)
	{
		nhi = nlo = 0;
		hi = lo = NULL;
		q = head;
		p = head->next;

		/* Start optimization for O(n) behavior on sorted and reverse-of-sorted lists */
		//如果是逆序，反转链表
		//如果正序，经过partition 后变为逆序(hi)
		while (p != NULL && LEQ(p, head)) {
			head->next = hi;
			hi = head;
			++nhi;
			head = p;
			p = p->next;
		}

		/* If entire list was ascending, done. */
		// 此时相当于把链表反转，再处理head 和 tail
		// 也能cover 只有一个结点的情况(head->next == NULL)
		if (p == NULL) {
			*root = head;
			head->next = hi;
			q->next = tail;
			return;
		}
		//这段优化很重要，https://leetcode.com/problems/sort-list/description/ 864ms -> 46ms
		/* End optimization.  Can be deleted if desired. */

		//partition
		while (p)
		{
			q = p->next;
			if (LEQ(p, head))
			{
				p->next = lo;
				lo = p;
				nlo++;
			}
			else
			{
				p->next = hi;
				hi = p;
				nhi++;
			}
			p = q;
		}
		if (nlo < nhi)
		{
			quickSort(lo, head, root);
			root = &head->next;
			head = hi;
		}
		else
		{
			quickSort(hi, tail, &head->next);
			tail = head;
			head = lo;
		}
	}
	*root = tail;
}

//无优化版
//head : 待排序链表的头
//tail: 待排序链表最后一个结点的下一个结点
//二级指针 phead: *phead == 排序后的链表头
void quickSort(ListNode* head, ListNode* tail, ListNode** phead)
{
	ListNode *p, *q, *hi, *lo;
	int nhi, nlo;
	while (head)
	{
		nhi = nlo = 0;
		hi = lo = NULL;
		q = head;
		p = head->next;

		//partition, 比较 p 和 head 的大小
		while (p)
		{
			q = p->next;
			if (LEQ(p, head))
			{
				p->next = lo;
				lo = p;
				nlo++;
			}
			else
			{
				p->next = hi;
				hi = p;
				nhi++;
			}
			p = q;
		}
		if (nlo < nhi)
		{
			quickSort(lo, head, phead);
			phead = &head->next;
			head = hi;
		}
		else
		{
			//只有一个head结点时 (nlo==nhi==0)，也进入该语句块
			quickSort(hi, tail, &head->next);
			tail = head;
			head = lo;
		}
	}
	//最终 head == NULL, 把下一段链表的头(tail)放到 phead 上
	*phead = tail;
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

	quickSort(node1, NULL, &node1);
	printNode(node1);
	system("pause");
	return 0;
}

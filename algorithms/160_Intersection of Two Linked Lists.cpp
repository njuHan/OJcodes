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


class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* p1 = headA, *p2 = headB;
		while (p1!=p2)
		{
			p1 = p1 ? p1->next : headB; //这里使得p1,p2可以取NULL，当两个链表没有交集，返回NULL
			p2 = p2 ? p2->next : headA;
		}
		return p1;
	}
};


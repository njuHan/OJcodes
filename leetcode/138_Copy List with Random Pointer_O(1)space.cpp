#include<iostream>
#include<cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<unordered_map>
using namespace std;




struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode* node, *newnode;
		if (head == NULL) return;
		for (node = head; node; node = node->next->next)
		{
			newnode = new RandomListNode(node->label);
			newnode->next = node->next;
			node->next = newnode;
		}

		for (node = head; node; node = node->next->next)
		{
			newnode = node->next;
			if (node->random)
				newnode->random = node->random->next;
		}
		RandomListNode* newhead = head->next;
		for (node = head; node; node = node->next)
		{
			newnode = node->next;
			node->next = newnode->next;
			if (newnode->next) newnode->next = newnode->next->next;
		}
		return newhead;
	}
};


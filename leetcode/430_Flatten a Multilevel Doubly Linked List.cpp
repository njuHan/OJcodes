#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<ctime>
#include<numeric>
using namespace std;


// Definition for a Node.
class Node {
public:
	int val = NULL;
	Node* prev = NULL;
	Node* next = NULL;
	Node* child = NULL;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution {
public:
	Node* flatten(Node* head) {
		Node* h = head;
		while (head)
		{
			if (head->child)
			{
				Node* next = head->next;
				head->next = head->child;
				head->next->prev = head;
				head->child = NULL;
				Node* p = head->next;
				while (p->next) p = p->next;
				p->next = next;
				if (next) next->prev = p;
			}
			head = head->next;
		}
		return h;
	}
	Node* flatten2(Node* head) {
		for (Node* h = head; h; h = h->next)
		{
			if (h->child)
			{
				Node* next = h->next;
				h->next = h->child;
				h->next->prev = h;
				h->child = NULL;
				Node* p = h->next;
				while (p->next) p = p->next;
				p->next = next;
				if (next) next->prev = p;
			}
		}
		return head;
	}

};



int main()
{
	Node* n1 = new Node(1,0,0,0), *n2 = new Node(2, 0, 0, 0), *n3 = new Node(3, 0, 0, 0), *n4 = new Node(4, 0, 0, 0), *n5 = new Node(5, 0, 0, 0);
	n1->next = n2;
	n2->prev = n1;
	n2->next = n5;
	n5->prev = n2;
	n2->child = n3;
	n3->next = n4;
	n4->prev = n3;

	Solution solu;
	Node* head = solu.flatten(n1);

	system("pause");
	return 0;
}
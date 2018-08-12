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

struct Node
{
	int val;
	Node* next;
	Node(int _val = 0, Node* _next = NULL) :val(_val), next(_next) {}
};

class MyLinkedList {
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = tail = NULL;
		length = 0;
	}

	void firstAdd(int val)
	{
		Node* newnode = new Node(val);
		head = tail = newnode;
		length++;
	}
	void lastdelete()
	{
		delete head;
		head = tail = 0;
		length = 0;
	}
	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >= length) return -1;
		if (index == length - 1) return tail->val;
		Node* p = head;
		for (int i = 0; i < index; i++) p = p->next;
		return p->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		if (length == 0) return firstAdd(val);
		Node* newnode = new Node(val); 
		Node** pp = &head;
		newnode->next = head;
		*pp = newnode;
		length++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (length == 0) return firstAdd(val);
		Node* newnode = new Node(val);
		tail->next = newnode;
		tail = tail->next;
		length++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index < 0 || index > length) return;
		if (index == length) return addAtTail(val);
		Node** pp = &head;
		for (int i = 0; i < index; i++) pp = &(*pp)->next;
		Node* newnode = new Node(val), *next = *pp;
		*pp = newnode;
		newnode->next = next;
		length++;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0 || index >= length) return;
		if (length == 1) return lastdelete();
		Node** pp = &head;
		for (int i = 0; i < index; i++) pp = &(*pp)->next;
		Node* todel = *pp;
		*pp = todel->next;
		delete todel;
		if (*pp == NULL)
		{
			tail = head;
			while (tail->next) tail = tail->next;
		}
		length--;
	}
private:
	Node* head, *tail;
	int length;
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList obj = new MyLinkedList();
* int param_1 = obj.get(index);
* obj.addAtHead(val);
* obj.addAtTail(val);
* obj.addAtIndex(index,val);
* obj.deleteAtIndex(index);
*/
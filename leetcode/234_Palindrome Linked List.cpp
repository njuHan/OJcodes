#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* slow = head, *fast = head, *pre = NULL;
		while (fast && fast->next) // reverse first half
		{
			fast = fast->next->next;
			ListNode* next = slow->next;
			slow->next = pre;
			pre = slow;
			slow = next;
		}
		ListNode* halfhead = (fast == NULL ? slow : slow->next);
		bool flag = true;
		while (pre) //compare and restore first half
		{
			if (pre->val != halfhead->val) flag = false;
			halfhead = halfhead->next;
			ListNode* temp = pre->next;
			pre->next = slow;
			slow = pre;
			pre = temp;
		}
		while (head)
		{
			printf("%d,", head->val);
			head = head->next;
		}
		return flag;

	}
};
int main()
{
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(3);
	ListNode node6(2);
	ListNode node7(1);
	ListNode* head = &node1;
	node1 = 

	system("pause");
	return 0;
}




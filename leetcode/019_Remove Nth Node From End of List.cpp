#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode tempHead(0);
		ListNode* pre = &tempHead, *slow = head, *fast = head;
		pre->next = head;
		int step = n;
		while (fast && step-- > 0)
			fast = fast->next;
		while (fast)
		{
			pre = pre->next;
			slow = slow->next;
			fast = fast->next;
		}
		pre->next = slow->next;
		return tempHead.next;
	}
};

int main()
{
	Solution solu;
	//vector<string> ans = solu.removeNthFromEnd
	
	system("pause");
	return 0;
}
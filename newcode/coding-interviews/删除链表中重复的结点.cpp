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
#include<sstream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL) return pHead;
		for (ListNode** pp = &pHead; *pp; )
		{
			ListNode* cur = *pp;
			if (cur->next && cur->next->val == cur->val)
			{
				int val = cur->val;
				while (cur && cur->val==val)
				{
					ListNode* next = cur->next;
					delete cur;
					cur = cur->next;
				}
				*pp = cur;
			}
			else
				pp = &(*pp)->next;
		}
		return pHead;
	}
};
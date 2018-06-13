/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
ListNode** pp = &pHead, *pivot = pHead;
		while (pivot &&pivot->next)
		{
			ListNode* next = pivot->next;
			pivot->next = next->next;
			next->next = *pp;
			*pp = next;
		}
		return *pp;
    }
};
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p = pHead1, *q = pHead2;
		while (p!=q)
		{
			p = p ? p->next : pHead2;
			q = q ? q->next : pHead1;
		}
		return p;
    }
};
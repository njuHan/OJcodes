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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode temp(0);
		ListNode* tail = &temp;
		while (pHead1 || pHead2)
		{
			if (pHead2 == NULL || (pHead1 != NULL&& pHead1->val <= pHead2->val))
			{
				tail->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				tail->next = pHead2;
				pHead2 = pHead2->next;
			}
			tail = tail->next;
		}
		return temp.next;
    }
};
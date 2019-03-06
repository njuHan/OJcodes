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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (k < 1) return NULL;
		ListNode* fast = pListHead, *slow = pListHead;
		while (k && fast)
		{
			fast = fast->next;
			k--;
		}
		if (k > 0) return NULL;
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
    }
};
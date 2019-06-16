struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k<=1) return head;
        ListNode* temp = new ListNode(0), *pre, *pivot;
        temp->next = head; pre = temp;
        int cnt = 0;
        for (ListNode* p = head; p; p = p->next) cnt++;
        while(cnt>=k)
        {
            cnt -= k;
            pivot = pre->next;
            for (int i=1; i<k; i++)
            {
                ListNode* next = pivot->next;
                pivot->next = next->next;
                next->next = pre->next;
                pre->next = next;
            }
            pre = pivot;
        }
        return temp->next;
    }
};


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		reverseK(&head, k);
		return head;
	}
private:
	void reverseK(ListNode** head, int k)
	{
		if (k == 1 || *head == NULL) return;
		ListNode** pp = head, **nextpp = &((*head)->next);
		ListNode* todo = *head, *nexthead = *head;
		int cnt = k;
		while (cnt>0 && nexthead!=NULL)
		{
			cnt--;
			nexthead = nexthead->next;
		}
		if (cnt > 0) return; //不足k，不反转
		*pp = nexthead;  //前后两段首尾相连
		while (todo!=nexthead)
		{
			ListNode* next = todo->next;
			todo->next = *pp;
			*pp = todo;
			todo = next;
		}
		reverseK(nextpp, k);
		return;
	}
};
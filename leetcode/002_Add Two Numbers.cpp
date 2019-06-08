class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int res = 0, more = 0;
        ListNode* temp = new ListNode(0), *tail = temp;
        while(l1 || l2 || more)
        {
            res = (l1?l1->val:0) + (l2?l2->val:0) + more;
            tail->next = new ListNode(res%10);
            more = res/10;
            res = 0;
            tail = tail->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return temp->next;    
    }
};
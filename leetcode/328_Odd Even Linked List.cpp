class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode head2(0);
        ListNode* even = &head2, *p;
        for (p = head; p && p->next; )
        {
            even = even->next = p->next;
            p->next = p->next->next;
            if (p->next) p = p->next; //保证结束循环时， p指向最后一个奇数结点
        }
        even->next = NULL; //结尾
        p->next = head2.next;
        return head;
    }
};
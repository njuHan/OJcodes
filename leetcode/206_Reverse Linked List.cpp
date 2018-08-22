
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
class Solution {
public:
	//链表反转， 递归
    ListNode* reverseList1(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* next = head->next;
        ListNode* newhead = reverseList(next);
        next->next = head;
        head->next = NULL;
        return newhead;
    }
	//原地逆序
	ListNode* reverseList2(ListNode* head) {
        ListNode* pre = NULL;
        while(head)
        {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
	// 临时头结点
	ListNode* reverseList3(ListNode* head) {
        ListNode* temp = new ListNode(0); // temp->next=NULL;
        while(head)
        {
            ListNode* next = head->next;
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        return temp->next;
    }
	// two-star **
	ListNode* reverseList4(ListNode* head) {
        ListNode** pp = &head, *pivot = head;
        while(pivot && pivot->next)
        {
            ListNode* next = pivot->next;
            pivot->next = next->next;
            next->next = *pp;
            *pp = next;
        }
        return head;
    }
};


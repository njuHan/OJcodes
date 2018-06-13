/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) return NULL;
		RandomListNode* p, *q, *newHead;
		for (p = pHead; p; p=p->next->next)
		{
			RandomListNode* next = p->next;
			p->next = new RandomListNode(p->label);
			p->next->next = next;
		}
		for (p = pHead; p; p = p->next->next)
			if (p->random) p->next->random = p->random->next;
			
		newHead = pHead->next;
		for (p=pHead; p; p = p->next)
		{
			q = p->next;
			p->next = q->next;
			if (p->next) q->next = p->next->next;
		}
		return newHead;
    }
};
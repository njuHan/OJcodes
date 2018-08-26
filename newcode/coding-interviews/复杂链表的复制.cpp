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
		RandomListNode* p = pHead, *q, temp(0);
		for (p = pHead; p; )
		{
			RandomListNode* next = p->next;
			p->next = new RandomListNode(p->label);
			p = p->next->next = next;
		}
		for (p = pHead; p; p = p->next->next) if(p->random)  p->next->random = p->random->next;
		q = &temp;
		for (p = pHead; p; )
		{
			q = q->next = p->next;
			p = p->next = p->next->next;
		}
		return temp.next;
	}
};

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
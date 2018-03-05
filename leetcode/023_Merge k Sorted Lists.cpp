//merge k sorted lists
//使用优先队列
// 仿函数
//时间复杂度O(Nlogk)
struct cmp
{
	//若A的优先级比B的小，返回true
	bool operator() (const ListNode* A, const ListNode*	B) const
	{
		//val 小的优先级大
		if (A->val > B->val)
			return true;
		return false;
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ppriority_queue<ListNode*, vector<ListNode* >, cmp> nodeQue;
		vector<ListNode*>::iterator it = lists.begin();
		ListNode temp_head(0);
		ListNode* tail = &temp_head;
		tail->next = NULL;
		while (it != lists.end())
		{
			if (*it)
			nodeQue.push((*it));
			it++;
		}
		while (!nodeQue.empty())
		{
			ListNode* top = nodeQue.top();
			nodeQue.pop();
			if (top)
			{
				tail->next = top;
				tail = tail->next;
				if (top->next)
					nodeQue.push(top->next);
			}
		}
		tail->next = NULL;
		return temp_head.next;
        
    }
};
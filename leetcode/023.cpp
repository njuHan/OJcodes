//merge k sorted lists
//使用优先队列
// 仿函数
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
        priority_queue<ListNode*, vector<ListNode* >, cmp> nodeQue;
		vector<ListNode*>::iterator it = lists.begin();
		ListNode temp_head(0);
		ListNode* tail = &temp_head;
		tail->next = NULL;
		while (it != lists.end())
		{
			ListNode* temp = (*it);
			while (temp)
			{
				nodeQue.push(temp);
				temp = temp->next;
			}
			it++;
		}
		while (!nodeQue.empty())
		{
			tail->next = nodeQue.top();
			nodeQue.pop();
			tail = tail->next;
		}
		tail->next = NULL;
		return temp_head.next;
        
    }
};
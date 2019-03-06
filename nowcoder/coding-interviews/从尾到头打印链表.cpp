class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		dfs(head);
		return ans;
	}
private:
	vector<int> ans;
	void dfs(ListNode* p)
	{
		if (p == NULL) return;
		dfs(p->next);
		ans.emplace_back(p->val);
	}
};
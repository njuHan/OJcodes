#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};




class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int len = 0;
		vector<ListNode*> ans;
		if (k <= 0) return ans;
		ans = vector<ListNode*>(k,NULL);
		for (ListNode* p = root; p; p = p->next) len++;
		int a = len / k, b = len%k;
		for (int i = 0; i < k && root; i++)
		{
			ans[i] = root;
			for (int j = 1; j < a + (i < b); j++)
			{
				root = root->next;
			}
			ListNode* next = root->next;
			root->next = NULL;
			root = next;
		}
		return ans;
	}
};
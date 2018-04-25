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
		if (root == NULL) return vector<ListNode*>(k,NULL);
		ListNode* p = root;
		while (p)
		{
			p = p->next;
			len++;
		}
		if (len <= k)
		{
			p = root;
			for (int i = 0; i < k; i++)
			{
				if (p)
				{
					ans.push_back(p);
					ListNode* next = p->next;
					p->next = NULL;
					p = next;
				}
				else
					ans.push_back(NULL);
			}
		}
		else
		{
			int partlen = len / k, more = len%k;
			int i = 0;
			p = root;
			while (i<k)
			{
				int templen = i < more ? partlen + 1 : partlen;
				for (int j = 0; j < templen ; j++)
				{
					if (j == 0)
						ans.push_back(p);
					if (j == templen -1)
					{
						ListNode* next = p->next;
						p->next = NULL;
						p = next;
					}
					else
					{
						p = p->next;
					}
				}
				i++;
			}
			
		}
		return ans;
	}
};
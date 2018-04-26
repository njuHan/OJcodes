#include<iostream>
#include<cstdio>
#include <stdlib.h>
#include <time.h>
#include<unordered_map>
#include<math.h>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
 public:
	 //预处理链表，之后查询G只需遍历G的元素，适合多次查询
	 int numComponents(ListNode* head, vector<int>& G) {
		 if (head == NULL) return 0;
		 int len = 0;
		 for (ListNode* p = head; p; p = p->next) len++;
		 vector<ListNode*> val2point(len,0);
		 for (ListNode* p = head; p; p = p->next) val2point[p->val] = p;
		 unordered_set<ListNode*> hashset;
		 int ans = 0;
		 for (auto e : G) hashset.insert(val2point[e]);
		 for (auto e : G)
		 {
			 if (hashset.count(val2point[e]->next));
			 else ans++;
		 }
		 return ans;
	 }
 };
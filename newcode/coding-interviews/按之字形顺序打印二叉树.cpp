#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> ans;
		if (pRoot == NULL) return ans;
		stack<TreeNode*> sk[2];
		sk[0].push(pRoot);
		int cur = 0;
		while (!sk[cur].empty())
		{
			vector<int> vec;
			while (!sk[cur].empty())
			{
				TreeNode* node = sk[cur].top(); sk[cur].pop();
				vec.emplace_back(node->val);
				if (cur == 0) //left -> right
				{
					if (node->left) sk[!cur].push(node->left);
					if (node->right) sk[!cur].push(node->right);
				}
				else
				{
					if (node->right) sk[!cur].push(node->right);
					if (node->left) sk[!cur].push(node->left);
				}
			}
			ans.emplace_back(vec);
			cur = !cur;
		}
		return ans;
	}

};
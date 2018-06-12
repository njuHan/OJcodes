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
		queue<TreeNode*> que;
		que.push(pRoot);
		while (!que.empty())
		{
			vector<int> vec;
			for (int m = que.size(); m > 0; m--)
			{
				TreeNode* node = que.front(); que.pop();
				vec.emplace_back(node->val);
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			ans.emplace_back(vec);
		}
		return ans;
	}

};
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;
		queue<TreeNode*> q1, q2;
		if (!root) return ans;
		q1.push(root);
		while (!q1.empty())
		{
			TreeNode* node;
			while (!q1.empty())
			{
				node = q1.front();
				q1.pop();
				if (node->left) q2.push(node->left);
				if (node->right) q2.push(node->right);
			}
			ans.push_back(node->val);
			swap(q1, q2);
		}
		return ans;
	}
};

int main()
{
	Solution solu;
	system("pause");
	return 0;
}
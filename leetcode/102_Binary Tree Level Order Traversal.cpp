#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
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
	vector<vector<int>> levelOrder2(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) return ans;
		queue<TreeNode*> cur;
		queue<TreeNode*> next;
		cur.push(root);
	
		while (!cur.empty())
		{
			vector<int> temp;
			while (!cur.empty())
			{
				TreeNode* node = cur.front();
				cur.pop();
				temp.emplace_back(node->val);
				if (node->left) next.push(node->left);
				if (node->right) next.push(node->right);
			}
			ans.emplace_back(temp);
			swap(cur, next);
		}
		return ans;
	}
	// One of C++ solutions (preorder) without queue;
	// faster than queue method
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		preorder(root, 0);
		return ans;
	}
private:
	vector<vector<int>> ans;
	void preorder(TreeNode* node, int depth)
	{
		if (!node) return;
		if (depth == ans.size()) ans.emplace_back(vector<int>());
		ans[depth].emplace_back(node->val);
		preorder(node->left, depth + 1);
		preorder(node->right, depth + 1);
	}


};

int main()
{
	Solution solu;

	system("pause");
	return 0;
}
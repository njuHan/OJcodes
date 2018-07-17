#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return isValid(root->left, root->right);
	}
	bool isValid(TreeNode* l, TreeNode* r)
	{
		if (l == NULL && r == NULL) return true;
		if (l == NULL || r == NULL)  return false;
		if (l->val != r->val) return false;
		return isValid(l->left, r->right) && isValid(l->right, r->left);
	}
	
	bool isSymmetric2(TreeNode* root) {
		if (!root) return true;
		stack<TreeNode*> lhs, rhs; // 用 queue 也行
		lhs.push(root->left); 
		rhs.push(root->right);
		
		while (!lhs.empty())
		{
			TreeNode* left = lhs.top(); lhs.pop();
			TreeNode* right = rhs.top(); rhs.pop();
			if (!left && !right) continue;
			if (!left || !right) return false;
			if (left->val != right->val) return false;
			lhs.push(left->left);
			rhs.push(right->right);
			lhs.push(left->right);
			rhs.push(right->left);
		}
		return true;
	}
	
};

int main()
{
	Solution solu;

	system("pause");
	return 0;
}
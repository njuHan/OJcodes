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
	
};

int main()
{
	Solution solu;

	system("pause");
	return 0;
}
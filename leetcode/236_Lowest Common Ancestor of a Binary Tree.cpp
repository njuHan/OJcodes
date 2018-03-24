#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || root == p || root == q) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left && right) return root;
		if (!left && right) return right;
		if (left && !right) return left;
		return NULL;
	}
};

int main()
{
	Solution solu;
	TreeNode node1(-2);
	TreeNode node2(2);
	TreeNode node3(-3);
	node1.right = &node3;
	
	system("pause");
	return 0;
}
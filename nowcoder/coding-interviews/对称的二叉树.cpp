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
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL) return true;
		return isValid(pRoot->left, pRoot->right);
	}
private:
	bool isValid(TreeNode* p1, TreeNode* p2)
	{
		if (p1 == NULL && p2 == NULL) return 1;
		if (p1 == NULL || p2 == NULL) return 0;
		return p1->val == p2->val && isValid(p1->left, p2->right) && isValid(p1->right, p2->left);
	}

};
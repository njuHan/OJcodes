#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<bitset>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		return cmp(s, t) || (s != NULL && (isSubtree(s->left, t) || isSubtree(s->right, t)));
	}
	bool cmp(const TreeNode* lhs, const TreeNode* rhs)
	{
		if (lhs==NULL && rhs==NULL) return true;
        if (lhs==NULL || rhs==NULL) return false;
		return lhs->val == rhs->val && cmp(lhs->left, rhs->left) && cmp(lhs->right, rhs->right);
	}
};


#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


static int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution2 {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root==NULL) return -1;
        return find(root, root->val);
    }
    int find(TreeNode* node,int minval)
    {
        if (node==NULL) return -1;
        if (node->val!=minval) return node->val;
        int left = find(node->left, minval), right = find(node->right, minval);
        if (left==-1 && right==-1) return -1;
        if (left==-1 || right==-1) return left==-1 ? right : left;
        return min(left, right);
    }
};

class Solution {
public:
	int findSecondMinimumValue(TreeNode* root) {
		minval = root->val;
		return find(root);
	}
private:
	int minval;
	int find(TreeNode* node)
	{
		if (!node) return -1;
		if (node->val != minval) return node->val;
		int left = find(node->left), right = find(node->right);
		return left == -1 ? right : (right == -1 ? left : min(left, right));
	}
};
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
	int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		ans = 0;
		getSum(root, 0);
		return ans;
	}
private:
	int ans;
	void getSum(TreeNode* node, int sum)
	{
		sum = sum * 10 + node->val;
		if (!node->left && !node->right)
		{
			ans += sum;
		}
		else
		{
			if (node->left) getSum(node->left, sum);
			if (node->right) getSum(node->right, sum);
		}
	}
};
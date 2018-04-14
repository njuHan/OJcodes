#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
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
	int diameterOfBinaryTree(TreeNode* root) {
		ans = 0;
		dfs(root);
		return ans;
	}
private:
	int ans;
	//返回该结点的高度，同时更新半径ans
	//高度 = 左右子树最大高度 + 1
	int dfs(TreeNode* node) 
	{
		if (node == NULL) return 0;
		int ldep = dfs(node->left);
		int rdep = dfs(node->right);
		ans = ans < (ldep + rdep) ? ldep + rdep : ans; //更新半径
		return (ldep > rdep ? ldep : rdep) + 1; //返回高度
	}
	
};
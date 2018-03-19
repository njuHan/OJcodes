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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int len = preorder.size();
		TreeNode* root = build(preorder, inorder, 0, len-1, 0, len-1);
		return root;
	}
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int p1, int p2, int q1, int q2)
	{
		if (p1 > p2 || q1>q2) return NULL;
		TreeNode* root = new TreeNode (preorder[p1]);
		int i;
		for (i = q1; i <= q2; i++)
		{
			if (preorder[p1] == inorder[i])
				break;
		}
		int leftLen = i - q1;
		root->left = build(preorder, inorder, p1 + 1, p1 + leftLen, q1, i - 1);
		root->right = build(preorder, inorder, p1 + leftLen + 1, p2, i + 1, q2);
		return root;
	}
};

int main()
{
	Solution solu;

	system("pause");
	return 0;
}
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
/*
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
*/
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
	{
		int len = inorder.size();
		if (len == 0) return NULL;
		in = inorder, post = postorder;
		return build(0, 0, len);
		
	}
	TreeNode* build(int b1, int b2, int len)
	{
		if (len == 0) return NULL;
		TreeNode* root = new TreeNode(post[b2+len-1]);
		int pos = b1;
		while (in[pos] != post[b2 + len - 1]) pos++;
		int left_len = pos - b1;
		root->left = build(b1, b2, left_len);
		root->right = build(pos+1, b2+left_len, len-left_len-1);
		return root;
	}
private:
	vector<int> in, post;
};
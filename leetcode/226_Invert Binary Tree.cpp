#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return NULL;
		TreeNode* left = root->left;
		root->left = root->right;
		root->right = left;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};


int main()
{


	system("pause");
	return 0;
}




#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
#include<stack>
#include<string.h>
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
	TreeNode* convertBST(TreeNode* root) {
		int sum = 0;
		visit(root, sum);
		return root;
	}
	void visit(TreeNode* root, int& sum)
	{
		if (root == NULL) return;
		if (root->right) visit(root->right, sum);
		sum += root->val;
		root->val = sum;
		if (root->left) visit(root->left, sum);
		
	}
};

int main()
{

	system("pause");
	return 0;
}


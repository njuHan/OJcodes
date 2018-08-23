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
        stack<TreeNode*> sk;
        if (root) sk.push(root);
        while(!sk.empty())
        {
            TreeNode* node = sk.top(); sk.pop();
            swap(node->left, node->right);
            if (node->left) sk.push(node->left);
            if (node->right) sk.push(node->right);
        }
        return root;
    }
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




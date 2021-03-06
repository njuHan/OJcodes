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

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        // find a valid root
        while(root && (root->val<L || root->val>R))
        {
            if (root->val<L) root = root->right;
            else root = root->left;
        }
        
        for (TreeNode* node = root; node; )
        {
            // find valid node->left
            while (node->left && node->left->val<L) node->left = node->left->right;
            node = node->left;
        }
        for (TreeNode* node = root; node; )
        {
            // find valid node->right
            while (node->right && node->right->val>R) node->right = node->right->left;
            node = node->right;
        }
        return root;
    }
};

class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root) return NULL;
		if (root->val < L) return trimBST(root->right, L, R);
		if (root->val > R) return trimBST(root->left, L, R);
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
		return root;
	}
};
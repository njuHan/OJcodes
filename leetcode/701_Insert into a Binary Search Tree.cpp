#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
#include<functional>
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
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (!root) return new TreeNode(val);
		if (root->val > val) root->left = insertIntoBST(root->left, val);
		else root->right = insertIntoBST(root->right, val);
		return root;
	}
};

class Solution2 {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		TreeNode* node = new TreeNode(val), * cur = root;
		while (cur)
		{
			if (cur->val > val)
			{
				if (cur->left) cur = cur->left;
				else { cur->left = node; break; }
			}
			else
			{
				if (cur->right) cur = cur->right;
				else { cur->right = node; break; }
			}
		}
		return root ? root : node;
	}
};
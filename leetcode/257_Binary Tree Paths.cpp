#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution2 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
private:
    vector<string> ans;
    void dfs(TreeNode* node, string path)
    {
        if (!node) return;
        if (!node->left && !node->right) ans.push_back(path+to_string(node->val));
        if (node->left) dfs(node->left, path + to_string(node->val) + "->");
        if (node->right) dfs(node->right, path + to_string(node->val) + "->");
    }
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		cur = "";
		ans = {};
		if (!root) return ans;
		cur = to_string(root->val);
		if (root->left == NULL && root->right == NULL) return{ cur };
		if (root->left) dfs(root->left);
		if (root->right) dfs(root->right);
		return ans;
	}
	void dfs(TreeNode* root)
	{
		string temp = cur;
		cur = cur + "->" + to_string(root->val);
		if (root->left == NULL && root->right == NULL)
		{
			ans.push_back(cur);
		}
		else
		{
			if (root->left) dfs(root->left);
			if (root->right) dfs(root->right);
		}
		cur = temp;
	}
private:
	string cur;
	vector<string> ans;
};
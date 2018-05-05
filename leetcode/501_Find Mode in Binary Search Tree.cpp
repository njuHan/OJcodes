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


class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		max = 0;
		inorder(root);
		vector<int> ans;
		for (auto e : valCnt)
		{
			if (e.second == max) ans.push_back(e.first);
		}
		return ans;
	}
private:
	int max;
	unordered_map<int, int> valCnt;
	void inorder(TreeNode* root)
	{
		if (root == NULL) return;
		inorder(root->left);
		valCnt[root->val]++;
		max = max < valCnt[root->val] ? valCnt[root->val] : max;
		inorder(root->right);
	}
};
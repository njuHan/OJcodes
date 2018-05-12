#include<iostream>
#include<cstdio>
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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		ans = {};
		solve(root);
		return ans;
	}
private:
	//tree key , {tree count, tree returned hash value}
	//use current map size as returned hash value
	unordered_map<long long, pair<int, int>> TreeDict;
	vector<TreeNode*> ans;
	long long solve(TreeNode* node)
	{
		if (!node) return 0L;
		long long key = ((long long)node->val << 32) | (solve(node->left) << 16) | solve(node->right);
		auto& p = TreeDict[key];
		if (p.first == 0) p.second = TreeDict.size();
		if (++p.first == 2) ans.push_back(node);
		return p.second;
	}
};
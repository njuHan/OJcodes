#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	string tree2str(TreeNode* t) {
		string ans = "";
		getStr(t, ans);
		return ans;
	}
private:
	void getStr(TreeNode* node, string& str)
	{
		if (!node) return;
		str = str + to_string(node->val);
		if (!node->left && !node->right)
			return;
		str += "(";
		getStr(node->left, str);
		str += ")";
		if (node->right)
		{
			str += "(";
			getStr(node->right, str);
			str += ")";
		}

	}
};
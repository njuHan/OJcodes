#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int h;
		return getHeight(pRoot, h);
	}
private:
	bool getHeight(TreeNode* node, int& ht)
	{
		if (node == NULL)
		{
			ht = 0;
			return 1;
		}
		int left, right;
		if (getHeight(node->left, left) == false || getHeight(node->right, right) == false) return false;
		ht = max(left, right) + 1;
		return abs(left - right) <= 1;
	}
};